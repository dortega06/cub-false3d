/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 19:52:00 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/05/13 20:49:50 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
/*
void	render_column(t_game *game, t_draw_line *draw, int i)
{
	int		tex_x;
	int		tex_y;
	int		y;
	int		color;
	double	step;
	double	tex_pos;

	tex_x = (int)(draw->wall_x * (double)draw->tex->width);
	if (draw->side == 0 && draw->dir_x > 0)
		tex_x = draw->tex->width - tex_x - 1;
	if (draw->side == 1 && draw->dir_y < 0)
		tex_x = draw->tex->width - tex_x - 1;
	step = 1.0 * draw->tex->height / draw->height;
	tex_pos = (draw->start_y - HEIGHT / 2
			+ draw->height / 2) * step;
	y = draw->start_y;
	while (y < draw->end_y)
	{
		tex_y = (int)tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= draw->tex->height)
			tex_y = draw->tex->height - 1;
		tex_pos += step;
		color = get_texture_color(draw->tex, tex_x, tex_y);
		put_pixel(i, y, color, game);
		y++;
	}
}*/

void	render_column_calc(t_draw_line *dw, int *tx_x, double *sp, double *tx_p)
{
	*tx_x = (int)(dw->wall_x * (double)dw->tex->width);
	if (dw->side == 0 && dw->dir_x < 0)
		*tx_x = dw->tex->width - *tx_x - 1;
	if (dw->side == 1 && dw->dir_y > 0)
		*tx_x = dw->tex->width - *tx_x - 1;
	*sp = 1.0 * dw->tex->height / dw->height;
	*tx_p = (dw->start_y - HEIGHT / 2 + dw->height / 2) * (*sp);
}

void	render_column(t_game *game, t_draw_line *draw, int i)
{
	int		tex_x;
	double	step;
	double	tex_pos;
	int		y;
	int		color;

	render_column_calc(draw, &tex_x, &step, &tex_pos);
	y = draw->start_y;
	while (y < draw->end_y)
	{
		color = get_texture_color(draw->tex, tex_x, (int)tex_pos);
		put_pixel(i, y, color, game);
		tex_pos += step;
		y++;
	}
}

void	perpendicular_wall_distance(t_player *player, t_draw_line *draw)
{
	double	angle_diff;

	if (draw->side == 0)
		draw->perp_dist = (draw->map_x - draw->pos_x
				+ (1 - draw->step_x) / 2.0) / draw->dir_x;
	else
		draw->perp_dist = (draw->map_y - draw->pos_y
				+ (1 - draw->step_y) / 2.0) / draw->dir_y;
	if (draw->perp_dist < 0.01)
		draw->perp_dist = 0.01;
	angle_diff = draw->start_x - player->angle;
	draw->correct_dist = draw->perp_dist * cos(angle_diff);
	if (draw->correct_dist < 0.01)
		draw->correct_dist = 0.01;
	draw->height = (int)(HEIGHT / draw->correct_dist);
	draw->start_y = -draw->height / 2 + HEIGHT / 2;
	if (draw->start_y < 0)
		draw->start_y = 0;
	draw->end_y = draw->height / 2 + HEIGHT / 2;
	if (draw->end_y >= HEIGHT)
		draw->end_y = HEIGHT - 1;
}

void	distance_to_next_grid(t_draw_line *draw)
{
	if (draw->dir_x < 0)
	{
		draw->step_x = -1;
		draw->side_x = (draw->pos_x - draw->map_x) * draw->delta_x;
	}
	else
	{
		draw->step_x = 1;
		draw->side_x = (draw->map_x + 1.0 - draw->pos_x) * draw->delta_x;
	}
	if (draw->dir_y < 0)
	{
		draw->step_y = -1;
		draw->side_y = (draw->pos_y - draw->map_y) * draw->delta_y;
	}
	else
	{
		draw->step_y = 1;
		draw->side_y = (draw->map_y + 1.0 - draw->pos_y) * draw->delta_y;
	}
}

/*
//	Lanza un rayo desde la posición del jugador en un ángulo determinado y
	dibuja la columna de pared correspondiente.

//	Utiliza el algoritmo DDA para avanzar en la cuadrícula del mapa hasta
	encontrar un muro.
//	Calcula la distancia perpendicular a la pared, determina la franja vertical
	a dibujar, realiza el mapeo de textura y pinta la pared columna a columna con
	la textura adecuada y orientación correcta.

//	@param	player		Puntero a la estructura del jugador.
//	@param	game		Puntero a la estructura principal del juego.
//	@param	start_x		Ángulo del rayo en radianes.
//	@param	i			Columna horizontal de la pantalla donde se pinta
						la pared.
//	@return				N/A
*/
void	draw_line(t_player *player, t_game *game, float start_x, int i)
{
	t_draw_line	draw;

	ft_memset(&draw, 0, sizeof(t_draw_line));
	draw.start_x = start_x;
	draw.pos_x = player->x / BLOCK;
	draw.pos_y = player->y / BLOCK;
	draw.dir_x = cos(draw.start_x);
	draw.dir_y = sin(draw.start_x);
	draw.map_x = (int)draw.pos_x;
	draw.map_y = (int)draw.pos_y;
	draw.delta_x = fabs(1.0 / draw.dir_x);
	draw.delta_y = fabs(1.0 / draw.dir_y);
	distance_to_next_grid(&draw);
	raycast(game, &draw);
	perpendicular_wall_distance(player, &draw);
	wall_hit_x_pct(&draw);
	draw.tex = &game->texture_imgs[game->last_facing];
	if (!draw.tex || !draw.tex->addr
		|| draw.tex->width <= 0 || draw.tex->height <= 0)
		return ;
	render_column(game, &draw, i);
}

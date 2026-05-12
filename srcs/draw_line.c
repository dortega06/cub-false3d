/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 19:52:00 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/05/12 16:46:52 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	render_column(t_game *game, t_draw_line *draw, int i)
{
	int		tex_x;
	int		tex_y;
	int		sy;
	int		color;

	tex_x = (int)(draw->wall_x * draw->tex->width);
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= draw->tex->width)
		tex_x = draw->tex->width - 1;
	if (draw->side == 0 && draw->dir_x > 0)
		tex_x = draw->tex->width - tex_x - 1;
	if (draw->side == 1 && draw->dir_y < 0)
		tex_x = draw->tex->width - tex_x - 1;
	sy = draw->start_y;
	while (sy < draw->end_y)
	{
		tex_y = get_texture_y(sy, draw->height, draw->tex->height);
		color = get_texture_color(draw->tex, tex_x, tex_y);
		put_pixel(i, sy, color, game);
		sy++;
	}
}

void	wall_hit_x_pct(t_draw_line *draw)
{
	if (draw->side == 0)
		draw->wall_x = draw->pos_y + (draw->perp_dist / BLOCK) * draw->dir_y;
	else
		draw->wall_x = draw->pos_x + (draw->perp_dist / BLOCK) * draw->dir_x;
	draw->wall_x -= floor(draw->wall_x);
}

void	perpendicular_wall_distance(t_draw_line *draw)
{
	if (draw->side == 0)
		draw->perp_dist = (draw->side_x - draw->delta_x) * BLOCK;
	else
		draw->perp_dist = (draw->side_y - draw->delta_y) * BLOCK;
	if (draw->perp_dist < 0.1)
		draw->perp_dist = 0.1;
}

void	raycast_which_wall(t_game *game, t_draw_line *draw)
{
	if (draw->side == 0)
	{
		if (draw->step_x > 0)
			game->last_facing = 3;
		else
			game->last_facing = 2;
	}
	else
	{
		if (draw->step_y > 0)
			game->last_facing = 1;
		else
			game->last_facing = 0;
	}
}

void	raycast_colision(t_game *game, t_draw_line *draw)
{
	while (!draw->hit)
	{
		if (draw->side_x < draw->side_y)
		{
			draw->side_x += draw->delta_x;
			draw->map_x += draw->step_x;
			draw->side = 0;
		}
		else
		{
			draw->side_y += draw->delta_y;
			draw->map_y += draw->step_y;
			draw->side = 1;
		}
		if (draw->map_y >= 0 && draw->map_y < game->map_height
			&& game->map[draw->map_y] && draw->map_x >= 0
			&& draw->map_x < (int)ft_strlen(game->map[draw->map_y])
			&& game->map[draw->map_y][draw->map_x] == '1')
			draw->hit = 1;
	}
}

void	raycast(t_game *game, t_draw_line *draw)
{
	raycast_colision(game, draw);
	raycast_which_wall(game, draw);
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
	distance_to_next_grid(&draw);/**/
	raycast(game, &draw);
	perpendicular_wall_distance(&draw);
	draw.height = (int)((BLOCK * HEIGHT) / draw.perp_dist);/**/
	draw.start_y = (HEIGHT - draw.height) / 2;
	draw.end_y = draw.start_y + draw.height;
	wall_hit_x_pct(&draw);/**/
	draw.tex = &game->texture_imgs[game->last_facing];
	if (!draw.tex || !draw.tex->addr
		|| draw.tex->width <= 0 || draw.tex->height <= 0)
		return ;
	render_column(game, &draw, i);/**/
}

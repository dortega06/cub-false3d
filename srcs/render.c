/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dortega- <dortega-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 17:31:32 by dortega-          #+#    #+#             */
/*   Updated: 2026/05/09 13:46:07 by dortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"


//	Dibuja un píxel en la posición (x, y) de la imagen, con el color indicado.
//
//	@param	x		Posición horizontal.
//	@param	y		Posición vertical.
//	@param	color	Color en formato 0xRRGGBB.
//	@param	game	Puntero a la estructura principal del juego.
//	@return	N/A

void	put_pixel(int x, int y, int color, t_game *game)
{
	int	index;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * game->size_line + x * game->bpp / 8;
	game->data[index] = color & 0xFF;
	game->data[index + 1] = (color >> 8) & 0xFF;
	game->data[index + 2] = (color >> 16) & 0xFF;
}


//	Pinta el techo y el suelo de la ventana con sus respectivos colores definidos.
//
//	Recorre todos los píxeles superiores y aplica el color del techo, y los inferiores el del suelo.

void	draw_ceiling_and_floor(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(x, y, game->color[C], game);
		//	put_pixel(x, y, CEILING_COLOR, game);
			x++;
		}
		y++;
	}
	y = HEIGHT / 2;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(x, y, game->color[F], game);
			//put_pixel(x, y, FLOOR_COLOR, game);
			x++;
		}
		y++;
	}
}

//	Dibuja un cuadrado hueco en pantalla en la posición y tamaño especificados.
//
//	Traza los cuatro lados del cuadrado usando el color recibido.
//
//	@param	x		Coordenada X inicial del cuadrado.
//	@param	y		Coordenada Y inicial del cuadrado.
//	@param	size	Tamaño de los lados del cuadrado.
//	@param	color	Color del cuadrado.
//	@param	game	Puntero a la estructura principal del juego.
//	@return	N/A

void	draw_square(int x, int y, int size, int color, t_game *game)//Creo que no lo usa
{
	int	i;

	i = 0;
	while (i < size)
	{
		put_pixel(x + i, y, color, game);
		i++;
	}
	i = 0;
	while (i < size)
	{
		put_pixel(x, y + i, color, game);
		i++;
	}
	i = 0;
	while (i < size)
	{
		put_pixel(x + size, y + i, color, game);
		i++;
	}
	i = 0;
	while (i < size)
	{
		put_pixel(x + i, y + size, color, game);
		i++;
	}
}


//	Dibuja el minimapa representando los muros del mapa del juego como cuadrados.
//
//	@param	game	Puntero a la estructura principal del juego.
//	@return	N/A

/*void	draw_map(t_game *game)//creo que ya no lo usa.
{
	char	**map;
	int		color;
	int		y;
	int		x;

	map = game->map;
	color = 0x0000FF;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				draw_square(x * 64, y * 64, 64, color, game);
			x++;
		}
		y++;
	}
}*/

//	Bucle principal de renderizado del juego. 
//
//	Realiza el movimiento del jugador, limpia la imagen, pinta el techo y el suelo, y recorre la pantalla "WIDTH" veces 
//	lanzando rayos para dibujar las paredes 3D usando la técnica de raycasting.
//
//	@param	game	Puntero a la estructura principal del juego.
//	@return			Devuelve siempre 0.

int draw_loop(t_game *game)
{
	t_player *player = &game->player;
	move_player(player);
	clear_img(game);
	draw_ceiling_and_floor(game);

	double fov = PI / 3.0;
	double angle_step = fov / (double)WIDTH;
	double ray_angle = player->angle - (fov / 2.0);
	int i = 0;
	while (i < WIDTH)
	{
		draw_line(player, game, ray_angle, i);
		ray_angle += angle_step;
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->wnd, game->img, 0, 0);
	(void)player;
//	printf("AQUI\n");
	return (0);
}

//	Lanza un rayo desde la posición del jugador en un ángulo determinado y dibuja la columna de pared correspondiente.
//
//	Utiliza el algoritmo DDA para avanzar en la cuadrícula del mapa hasta encontrar un muro.
//	Calcula la distancia perpendicular a la pared, determina la franja vertical a dibujar, 
//	realiza el mapeo de textura y pinta la pared columna a columna con la textura adecuada y orientación correcta.
//
//	@param	player		Puntero a la estructura del jugador.
//	@param	game		Puntero a la estructura principal del juego.
//	@param	start_x		Ángulo del rayo en radianes.
//	@param	i			Columna horizontal de la pantalla donde se pinta la pared.
//	@return				N/A

void	draw_line(t_player *player, t_game *game, float start_x, int i)
{
	double	pos_x = player->x / BLOCK;
	double	pos_y = player->y / BLOCK;
	double	dir_x = cos(start_x);
	double	dir_y = sin(start_x);
	int		map_x = (int)pos_x;
	int		map_y = (int)pos_y;
	double	delta_x = fabs(1.0 / dir_x);
	double	delta_y = fabs(1.0 / dir_y);
	int		step_x;
	int		step_y;
	double	side_x;
	double	side_y;
	int		side;
	int		hit;

	if (dir_x < 0)
	{
		step_x = -1;
		side_x = (pos_x - map_x) * delta_x;
	}
	else
	{
		step_x = 1;
		side_x = (map_x + 1.0 - pos_x) * delta_x;
	}
	if (dir_y < 0)
	{
		step_y = -1;
		side_y = (pos_y - map_y) * delta_y;
	}
	else
	{
		step_y = 1;
		side_y = (map_y + 1.0 - pos_y) * delta_y;
	}
	hit = 0;
	while (!hit)
	{
		if (side_x < side_y)
		{
			side_x += delta_x;
			map_x += step_x;
			side = 0;
		}
		else
		{
			side_y += delta_y;
			map_y += step_y;
			side = 1;
		}
		if (map_y >= 0 && map_y < game->map_height
			&& game->map[map_y] && map_x >= 0
			&& map_x < (int)strlen(game->map[map_y])
			&& game->map[map_y][map_x] == '1')
			hit = 1;
	}
	if (side == 0)
	{
		if (step_x > 0)
			game->last_facing = 3;
		else
			game->last_facing = 2;
	}
	else
	{
		if (step_y > 0)
			game->last_facing = 1;
		else
			game->last_facing = 0;
	}

	double	perp_dist;
	if (side == 0)
		perp_dist = (side_x - delta_x) * BLOCK;
	else
		perp_dist = (side_y - delta_y) * BLOCK;
	if (perp_dist < 0.1)
		perp_dist = 0.1;

	int		height = (int)((BLOCK * HEIGHT) / perp_dist);
	int		start_y = (HEIGHT - height) / 2;
	int		end_y = start_y + height;
	double	wall_x;
	if (side == 0)
		wall_x = pos_y + (perp_dist / BLOCK) * dir_y;
	else
		wall_x = pos_x + (perp_dist / BLOCK) * dir_x;
	wall_x -= floor(wall_x);

	t_image	*tex = &game->texture_imgs[game->last_facing];
	if (!tex || !tex->addr || tex->width <= 0 || tex->height <= 0)
		return ;

	int		tex_x = (int)(wall_x * tex->width);
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= tex->width)
		tex_x = tex->width - 1;
	if (side == 0 && dir_x > 0)
		tex_x = tex->width - tex_x - 1;
	if (side == 1 && dir_y < 0)
		tex_x = tex->width - tex_x - 1;

	int		sy = start_y;
	while (sy < end_y)
	{
		int tex_y = get_texture_y(sy, height, tex->height);
		int color = get_texture_color(tex, tex_x, tex_y);
		put_pixel(i, sy, color, game);
		sy++;
	}
}

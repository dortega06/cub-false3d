/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dortega- <dortega-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 17:31:32 by dortega-          #+#    #+#             */
/*   Updated: 2026/05/13 16:16:31 by dortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

/*
//	Dibuja un píxel en la posición (x, y) de la imagen, con el color indicado.

//	@param	x		Posición horizontal.
//	@param	y		Posición vertical.
//	@param	color	Color en formato 0xRRGGBB.
//	@param	game	Puntero a la estructura principal del juego.
//	@return	N/A
*/
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

/*
//	Pinta el techo y el suelo de la ventana con sus respectivos colores
	definidos.

//	Recorre todos los píxeles superiores y aplica el color del techo, y los
	inferiores el del suelo.
*/
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
			x++;
		}
		y++;
	}
}

/*
//	Dibuja un cuadrado hueco en pantalla en la posición y tamaño especificados.

//	Traza los cuatro lados del cuadrado usando el color recibido.

//	@param	x		Coordenada X inicial del cuadrado.
//	@param	y		Coordenada Y inicial del cuadrado.
//	@param	size	Tamaño de los lados del cuadrado.
//	@param	color	Color del cuadrado.
//	@param	game	Puntero a la estructura principal del juego.
//	@return	N/A
*/
/*void	draw_square(int x, int y, int size, int color, t_game *game)
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
}*/
/*
//	Dibuja el minimapa representando los muros del mapa del juego como
	cuadrados.

//	@param	game	Puntero a la estructura principal del juego.
//	@return	N/A
*/
/*void	draw_map(t_game *game)
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

/*
//	Bucle principal de renderizado del juego. 
//
//	Realiza el movimiento del jugador, limpia la imagen, pinta el techo y el
	suelo, y recorre la pantalla "WIDTH" veces lanzando rayos para dibujar las
	paredes 3D usando la técnica de raycasting.

//	@param	game	Puntero a la estructura principal del juego.
//	@return			Devuelve siempre 0.
*/
int	draw_loop(t_game *game)
{
	t_player	*player;
	double		fov;
	double		angle_step;
	double		ray_angle;
	int			i;

	player = &game->player;
	fov = PI / 3.0;
	angle_step = fov / (double)WIDTH;
	ray_angle = player->angle - (fov / 2.0);
	i = 0;
	move_player(game);
	clear_img(game);
	draw_ceiling_and_floor(game);
	while (i < WIDTH)
	{
		draw_line(player, game, ray_angle, i);
		ray_angle += angle_step;
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->wnd, game->img, 0, 0);
	return (0);
}

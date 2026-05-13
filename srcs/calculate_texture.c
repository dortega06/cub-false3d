/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dortega- <dortega-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 18:08:20 by dortega-          #+#    #+#             */
/*   Updated: 2026/05/09 16:26:54 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/*	Calcula la coordenada X de la textura correspondiente al punto de impacto
	del rayo en la pared.

//	@param	ray_x			Coordenada X donde impacta el rayo.
//	@param	ray_y			Coordenada Y donde impacta el rayo.
//	@param	texture_width	Ancho de la textura.
//	@param	facing			Dirección de la pared 
	(0: Norte, 1: Sur, 2: Oeste, 3: Este).
//	@return					Índice X de la textura a usar.
*/
int	get_texture_x(double ray_x, double ray_y, int texture_width, int facing)
{
	double	wall_pos;
	int		tex_x;

	if (facing == 0 || facing == 1)
		wall_pos = ray_x - (int)ray_x;
	else
		wall_pos = ray_y - (int)ray_y;
	if (wall_pos < 0)
		wall_pos += 1.0;
	tex_x = (int)(wall_pos * texture_width);
	if (tex_x >= texture_width)
		tex_x = texture_width - 1;
	if (tex_x < 0)
		tex_x = 0;
	return (tex_x);
}

/*	Calcula la coordenada Y de la textura correspondiente a un punto específico
	de la pared en pantalla.
//
//	@param	screen_y			Coordenada Y en la pantalla.
//	@param	wall_height			Altura de la pared proyectada.
//	@param	texture_height		Altura de la textura.
//	@return						Índice Y de la textura a usar.
*/
int	get_texture_y(int screen_y, int wall_height, int texture_height)
{
	int	tex_y;
	int	start_y;

	if (wall_height <= 0)
		return (0);
	start_y = (HEIGHT - wall_height) / 2;
	if (screen_y < start_y)
		return (0);
	tex_y = (screen_y - start_y) * texture_height / wall_height;
	if (tex_y >= texture_height)
		tex_y = texture_height - 1;
	if (tex_y < 0)
		tex_y = 0;
	return (tex_y);
}

/*	Devuelve la estructura de la textura de la pared según la última dirección
	en la que se detectó una pared.
//
//	@param	game	Puntero a la estructura principal del juego.
//	@return			Puntero a la imagen de la textura correspondiente.
*/
/*t_image	*get_wall_texture(t_game *game)
{
	return (&game->texture_imgs[game->last_facing]);
}*/

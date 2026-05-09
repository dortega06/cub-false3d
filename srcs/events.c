/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dortega- <dortega-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 19:07:38 by dortega-          #+#    #+#             */
/*   Updated: 2026/05/09 19:49:42 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/*
//	Libera la memoria reservada para las rutas de las texturas de la estructura
	game.
*/
/*static void	free_texture_paths(t_game *game)
{
	if (game->textures.north)
		ft_free(game->textures.north);
	if (game->textures.south)
		ft_free(game->textures.south);
	if (game->textures.west)
		ft_free(game->textures.west);
	if (game->textures.east)
		ft_free(game->textures.east);
	
}*/

/*
//	Libera la memoria de una textura individual destruyéndola con
	mlx_destroy_image.

//	@param	game	Puntero a la estructura principal del juego.
//	@param	index	Índice de la textura a liberar.
//	@return	N/A
*/
static void	destroy_single_texture(t_game *game, int index)
{
	if (game->texture_imgs[index].img_ptr)
		mlx_destroy_image(game->mlx, game->texture_imgs[index].img_ptr);
	game->texture_imgs[index].img_ptr = NULL;
	game->texture_imgs[index].addr = NULL;
}

/*
//	Libera toda la memoria reservada para las texturas y resetea punteros.

//	@param	game	Puntero a la estructura principal del juego.
//	@return	N/A
*/
void	free_textures(t_game *game)
{
	if (!game || !game->texture_imgs)
		return ;
	destroy_single_texture(game, 0);
	destroy_single_texture(game, 1);
	destroy_single_texture(game, 2);
	destroy_single_texture(game, 3);
	free(game->texture_imgs);
	game->texture_imgs = NULL;
	game->textures_loaded = 0;
}

/*
	Libera todos los recursos asociados al juego, como imágenes, ventanas,
	mapas y texturas.
*/
static void	free_game_resources(t_game *game)
{
	if (game->texture_imgs)
		free_textures(game);
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	if (game->wnd)
		mlx_destroy_window(game->mlx, game->wnd);
	//if (game->map)
	//	ft_free_2ptr(game->map);
	//free_texture_paths(game);
}

/*
//	Cierra el juego de forma segura liberando todos los recursos y cerrando la
	ventana.
*/
int	close_game(t_game *game)
{
	if (!game)
	{
		clean_data_cube(game->parse);
		exit(0);
	}
	free_game_resources(game);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}	
	clean_data_cube(game->parse);
	exit(0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dortega- <dortega-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 17:51:49 by dortega-          #+#    #+#             */
/*   Updated: 2026/05/09 17:26:55 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/*
//	Inicializa los valores de una textura (t_img) a cero o NULL.

//	@param	texture	Puntero a la estructura de textura a inicializar.
//	@return	N/A
*/
static void	init_single_texture(t_image *texture)
{
	texture->img_ptr = NULL;
	texture->addr = NULL;
	texture->bpp = 0;
	texture->size_line = 0;
	texture->endian = 0;
	texture->width = 0;
	texture->height = 0;
}

/*
//	Reserva memoria para el array de texturas y las inicializa.

//	@param	game	Puntero a la estructura principal del juego.
//	@return	N/A
*/
void	init_textures(t_game *game)
{
	if (!game)
		return ;
	game->texture_imgs = malloc(sizeof(t_img) * 4);/*se puede hacer en local*/
	if (!game->texture_imgs)
	{
		/*FPRINTF no puede usarse*/
		fprintf(stderr, "ERROR: malloc failed for textures\n");
		exit(1);/*LEAKS?*/
	}
	init_single_texture(&game->texture_imgs[0]);
	init_single_texture(&game->texture_imgs[1]);
	init_single_texture(&game->texture_imgs[2]);
	init_single_texture(&game->texture_imgs[3]);
	/*int	j;
	j = 0;
	while (j < 4)
		init_single_texture(&game->texture_imgs[j++]);*/
	game->textures_loaded = 0;
}

/*
//	Establece las dimensiones width y height de una textura.

//	@param	tex		Puntero a la textura.
//	@param	w		Ancho de la textura.
//	@param	h		Alto de la textura.
//	@return	N/A
*/
static void	set_texture_data(t_image *tex, int w, int h)
{
	tex->width = w;
	tex->height = h;
}

/*
//	Carga una textura desde un archivo y la almacena en el índice indicado.

//	@param	game	Puntero a la estructura principal del juego.
//	@param	index	Índice de la textura a cargar (0-3).
//	@param	path	Ruta del archivo XPM de la textura.
//	@return	N/A
*/
int	load_texture(t_game *game, int index, char *path)
{
	int	width;
	int	height;

	if (!game || !path || index < 0 || index > 3)
		return (ERR);
	width = 64;
	height = 64;
	game->texture_imgs[index].img_ptr
		= mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	if (!game->texture_imgs[index].img_ptr) /*LEAK si sale mal porque continuar?
										   	 no devuelve un valor de error*/
		return (printf("WARNING: Failed to load texture from %s\n", path), ERR);
	game->texture_imgs[index].addr = mlx_get_data_addr(
			game->texture_imgs[index].img_ptr,
			&game->texture_imgs[index].bpp,
			&game->texture_imgs[index].size_line,
			&game->texture_imgs[index].endian);
	if (!game->texture_imgs[index].addr)
		return (printf("WARNING: Failed to get data address"
				"for texture %d\n", index), ERR);
	set_texture_data(&game->texture_imgs[index], width, height);
	game->textures_loaded++;
	return (OK);
}

/*
//	Limita una coordenada al rango [0, max-1] para evitar desbordamientos.

//	@param	coord	Coordenada a limitar.
//	@param	max		Valor máximo permitido.
//	@return	Coordenada limitada.
*/
static int	clamp_coord(int coord, int max)
{
	if (coord < 0)
		return (0);
	if (coord >= max)
		return (max - 1);
	return (coord);
}

/*
//	Obtiene el color de un píxel concreto en la textura.

//	@param	texture	Puntero a la textura de la que se obtiene el color.
//	@param	x		Coordenada X en la textura.
//	@param	y		Coordenada Y en la textura.
//	@return	Color en formato unsigned int.
*/
int	get_texture_color(t_image *texture, int x, int y)
{
	unsigned char	*ptr;
	int				offset;

	if (!texture || !texture->addr)
		return (0);
	x = clamp_coord(x, texture->width);
	y = clamp_coord(y, texture->height);
	offset = y * texture->size_line + x * (texture->bpp / 8);
	ptr = (unsigned char *)texture->addr + offset;
	return (*(unsigned int *)ptr);
}

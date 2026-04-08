/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_to_images.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 18:06:42 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/04/08 19:11:20 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "mlx.h"
#include "mlx_int.h"

void	textures_to_image(t_cube *root_nd, char **textu_lines)
{
	int		j;
	char	*tmp;

	j = 0;
	while (j < 4)
	{
		tmp = textu_lines[j] + 3;
		root_nd->textu[j].image = mlx_xpm_file_to_image(root_nd->sys,
				tmp,
				&root_nd->textu[j].width,
				&root_nd->textu[j].height);
		j++;
	}
}

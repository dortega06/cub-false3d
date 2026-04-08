/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_data_cube.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 19:01:39 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/04/08 14:07:27 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "libftprintf.h"
#include "mlx.h"
#include "mlx_int.h"

void	clean_data_cube(t_cube *root_nd)
{
	int	j;

	j = 0;
	if (root_nd->file)
		ft_free_2ptr(root_nd->file);
	if (root_nd->fd != -1)
		close(root_nd->fd);
	while (root_nd->textu[j].image && j < 4)
	{
		mlx_destroy_image(root_nd->sys, root_nd->textu[j].image);
		j++;
	}
	//mlx_destroy_window(root_nd->sys, root_nd->win);
	mlx_destroy_display(root_nd->sys);
	free(root_nd->sys);
	root_nd->sys = NULL;
}

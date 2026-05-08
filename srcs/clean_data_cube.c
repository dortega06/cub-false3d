/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_data_cube.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 19:01:39 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/05/08 18:43:46 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "libftprintf.h"
#include "mlx.h"
#include "mlx_int.h"

void	clean_data_cube(t_cube *root_nd)
{
	if (root_nd->file)
		ft_free_2ptr(root_nd->file);
	if (root_nd->fd != -1)
		close(root_nd->fd);
	if (root_nd->textu_path)
		ft_free_2ptr(root_nd->textu_path);
}

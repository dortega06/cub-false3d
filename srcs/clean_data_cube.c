/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_data_cube.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 19:01:39 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/04/02 19:06:32 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	clean_data_cube(t_cube *root_nd)
{
	if (root_nd->file)
		ft_free_2ptr(root_nd->file);
}

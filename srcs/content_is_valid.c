/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_is_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 15:15:00 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/04/17 16:57:58 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_bool	content_is_valid(t_cube *root_nd)
{
	int	j;

	j = 0;
	if (!textures_are_valid(root_nd, &j))
		return (FALSE);
	if (!colors_are_valid(root_nd, &j))
		return (FALSE);
	if (!map_is_valid(root_nd, &j))
		return (FALSE);
	return (TRUE);
}

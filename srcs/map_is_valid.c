/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 13:25:14 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/04/10 17:00:02 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "libft.h"
#include "libftprintf.h"

t_bool	there_is_map(char **corner)
{
	if (!corner)
		return (FALSE);
	else if (!*corner)
		return(FALSE);
	else if (ft_strchr(*corner, '\n'))
		return(FALSE);
	return (TRUE);
}

t_bool	map_is_valid(t_cube *root_nd)
{
	char	**corner;

	if (!there_is_map(&root_nd->file[8]))
		return (FALSE);
	corner = &root_nd->file[8];
	root_nd->rsp = rsp((const char **)corner, &root_nd->rsp);
	if (root_nd->rsp.y == -1 || root_nd->rsp.x == -1)
		return (FALSE);
	else if (!only_one_rsp(corner, &root_nd->rsp))
		return (FALSE);
	if (floodfill(corner,
		root_nd->rsp.type,
		root_nd->rsp.x,
		root_nd->rsp.y) == SPC)
		return (FALSE);
	return (TRUE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 12:52:57 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/04/18 17:37:46 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "libftprintf.h"

t_ff	floodfill(int x, int y, t_cube *root_nd, char **visited)
{
	char	rsp_type;
	char	**map;

	rsp_type = root_nd->rsp.type;
	map = root_nd->map;
	if (map[y][x] != '\0'
		&& (map[y][x] == '0' || (map[y][x] == rsp_type && x != 0))
		&& visited[y][x] != 'v')
	{
		visited[y][x] = 'v';
		if (floodfill(x, y + 1, root_nd, visited) == SPC)
			return (SPC);
		if (floodfill(x + 1, y, root_nd, visited) == SPC)
			return (SPC);
		if (floodfill(x, y - 1, root_nd, visited) == SPC)
			return (SPC);
		if (floodfill(x - 1, y, root_nd, visited) == SPC)
			return (SPC);
	}
	else if (map[y][x] != '\0' && (map[y][x] == '1' || visited[y][x] == 'v'))
		return (WALL);
	else
		return (SPC);
	return (FLOOR);
}

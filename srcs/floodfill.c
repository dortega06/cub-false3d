/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 12:52:57 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/05/14 13:51:44 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "libftprintf.h"

t_bool	is_outside_map(int x, int y, char **map)
{
	int	len;

	if (y < 0 || x < 0)
		return (TRUE);
	if (!map[y])
		return (TRUE);
	len = ft_strlen(map[y]);
	if (x >= len)
		return (TRUE);
	return (FALSE);
}

t_ff	floodfill(int x, int y, t_cube *root_nd, char **visited)
{
	char	**map;

	map = root_nd->map;
	if (is_outside_map(x, y, map))
		return (SPC);
	if (map[y][x] == '1' || visited[y][x] == 'v')
		return (WALL);
	if (map[y][x] != '0' && map[y][x] != root_nd->rsp.type)
		return (SPC);
	visited[y][x] = 'v';
	if (floodfill(x, y + 1, root_nd, visited) == SPC)
		return (SPC);
	if (floodfill(x + 1, y, root_nd, visited) == SPC)
		return (SPC);
	if (floodfill(x, y - 1, root_nd, visited) == SPC)
		return (SPC);
	if (floodfill(x - 1, y, root_nd, visited) == SPC)
		return (SPC);
	return (FLOOR);
}

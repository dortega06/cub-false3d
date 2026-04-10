/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 12:52:57 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/04/10 17:35:58 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_ff	floodfill(char **map, char rsp_type, int x, int y)
{
	if (map[x][y] == '0' || map[x][y] == rsp_type)
	{
		if (floodfill(map, rsp_type, x, y + 1) == SPC)
			return (SPC);
		if (floodfill(map, rsp_type, x + 1, y) == SPC)
			return (SPC);
		if (floodfill(map, rsp_type, x, y - 1) == SPC)
			return (SPC);
		if (floodfill(map, rsp_type, x - 1, y) == SPC)
			return (SPC);
	}
	else if (map[x][y] == '1')
		return (WALL);
	else
		return (SPC);
	return (FLOOR);
}

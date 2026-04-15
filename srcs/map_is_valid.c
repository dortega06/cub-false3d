/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 13:25:14 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/04/15 18:40:15 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "libft.h"
#include "libftprintf.h"

char	**dup_map(char **map)
{
	int		k;
	int		j;
	char	**copy_map;

	if (!map || (map && !*map))
		return (NULL);
	j = 0;
	while (map[j])
		j++;
	copy_map = (char **)ft_calloc(j + 1, sizeof(char *));
	if (!copy_map)
		return (NULL);
	k = 0;
	while (k < j)
	{
		copy_map[k] = ft_strdup(map[k]);
		if (!copy_map[k])
			return (ft_free_2ptr(copy_map), NULL);
		k++;
	}
	copy_map[k] = NULL;
	return (copy_map);
}

t_bool	there_is_map(char **corner)
{
	if (!corner)
		return (FALSE);
	else if (!*corner)
		return (FALSE);
	return (TRUE);
}

/*AQUI no basarnos en que el mapa comienza en la linea 8*/
t_bool	map_is_valid(t_cube *root_nd)
{
	char	**corner;
	char	**visited;

	if (!there_is_map(&root_nd->file[8]))
		return (ft_printf("There is not map.\n"), FALSE);
	corner = &root_nd->file[8];
	/*if (!there_is_empty_line(corner)) AQUI crear esta funcion
		return (ft_printf("There are empty line.\n"))*/
	root_nd->rsp = rsp((const char **)corner, &root_nd->rsp);
	if (root_nd->rsp.y == -1 || root_nd->rsp.x == -1)
		return (ft_printf("Only 1 player box.\n"), FALSE);
	else if (!only_one_rsp(corner, &root_nd->rsp))
		return (FALSE);
	root_nd->map = corner;
	visited = dup_map(root_nd->map);
	if (!visited)
		return (FALSE);
	if (floodfill(root_nd->rsp.x, root_nd->rsp.y,
			root_nd, visited) == SPC)
		return (ft_printf("Something is wrong with map.\n"),
			ft_free_2ptr(visited), FALSE);
	ft_free_2ptr(visited);
	return (TRUE);
}

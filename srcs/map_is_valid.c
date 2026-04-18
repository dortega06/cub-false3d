/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 13:25:14 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/04/18 17:37:26 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "libft.h"
#include "libftprintf.h"

char	*check_visited(t_vex *vec, char **visited)
{
	char	*tmp;
	int		j;

	j = 0;
	tmp = NULL;
	while (visited[j])
	{
		tmp = ft_strchr(visited[j], vec->type);
		if (!tmp)
			tmp = ft_strchr(visited[j], '0');
		if (tmp)
		{
			vec->x = tmp - visited[j];
			vec->y = j;
			break ;
		}
		j++;
	}
	return (tmp);
}

t_bool	map_lakes_islands_are_closed(t_cube *root_nd, char **visited)
{
	t_vex	tmp;

	tmp.type = root_nd->rsp.type;
	tmp.x = root_nd->rsp.x;
	tmp.y = root_nd->rsp.y;
	while (check_visited(&tmp, visited))
	{
		if (floodfill(tmp.x, tmp.y, root_nd, visited) == SPC)
			return (FALSE);
	}
	return (TRUE);
}

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

t_bool	there_is_map(t_cube *root_nd, int *j)
{
	while (root_nd->file[*j] && ft_isbreakline(root_nd->file[*j]))
		(*j)++;
	if (!root_nd->file[*j])
		return (FALSE);
	return (TRUE);
}

t_bool	map_is_valid(t_cube *root_nd, int *j)
{
	char	**top_left_corner;
	char	**visited;

	if (!there_is_map(root_nd, j))
		return (ft_printf("There is not map.\n"), FALSE);
	top_left_corner = &root_nd->file[*j];
	root_nd->rsp = rsp((const char **)top_left_corner, &root_nd->rsp);
	if (root_nd->rsp.y == -1 || root_nd->rsp.x == -1)
		return (ft_printf("There is not player box.\n"), FALSE);
	else if (!only_one_rsp(top_left_corner, &root_nd->rsp))
		return (ft_printf("There are many player box.\n"), FALSE);
	root_nd->map = top_left_corner;
	visited = dup_map(root_nd->map);
	if (!visited)
		return (FALSE);
	if (!map_lakes_islands_are_closed(root_nd, visited))
		return (ft_printf("Something is wrong with map.\n"),
			ft_free_2ptr(visited), FALSE);
	ft_free_2ptr(visited);
	return (TRUE);
}

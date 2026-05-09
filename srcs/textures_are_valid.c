/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_are_valid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 18:34:12 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/05/09 17:09:08 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	**only_path(char **full_str)
{
	int		j;

	j = 0;
	while (j < 4)
	{
		ft_strlcpy(full_str[j], &(full_str[j][3]), ft_strlen(full_str[j]) - 2);
		j++;
	}
	return (full_str);
}

t_bool	xmp_check_loop(char **texture_lines, t_cube *root_nd)
{
	char	*tmp;
	int		j;

	j = 0;
	while (texture_lines[j] && j < 4)
	{
		tmp = texture_lines[j] + 3;
		if (!check_mng(tmp, "xpm", root_nd))
			return (FALSE);
		j++;
	}
	return (TRUE);
}

static t_bool	check_nomen(char **texture_lines)
{
	if (ft_strncmp(texture_lines[0], "NO ", 3) != 0)
		return (ft_printf("NO nomenclature is wrong.\n"), FALSE);
	else if (ft_strncmp(texture_lines[1], "SO ", 3) != 0)
		return (ft_printf("SO nomenclature is wrong.\n"), FALSE);
	else if (ft_strncmp(texture_lines[2], "WE ", 3) != 0)
		return (ft_printf("WE nomenclature is wrong.\n"), FALSE);
	else if (ft_strncmp(texture_lines[3], "EA ", 3) != 0)
		return (ft_printf("EA nomenclature is wrong.\n"), FALSE);
	return (TRUE);
}

t_bool	textures_are_valid(t_cube *root_nd, int *j)
{
	char	**tmp;

	tmp = extract_lines(root_nd, 4, j);
	if (!tmp)
		return (FALSE);
	if (!check_nomen(tmp))
		return (ft_free_2ptr(tmp), FALSE);
	else if (!xmp_check_loop(tmp, root_nd))
		return (ft_free_2ptr(tmp), FALSE);
	root_nd->textu_path = only_path(tmp);
	return (TRUE);
}

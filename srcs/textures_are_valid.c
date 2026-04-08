/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_are_valid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 18:34:12 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/04/08 13:41:00 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_bool	xmp_loop_extension(char **texture_lines, t_cube *root_nd)
{
	char	*tmp;
	int		j;

	j = 0;
	while (texture_lines[j] && j < 4)
	{
		tmp = texture_lines[j] + 3;
		if (!extension(tmp, "xpm", root_nd))
			return (FALSE);
		j++;
	}
	return (TRUE);
}

static t_bool	check_nomen(char **texture_lines)
{
	if (ft_strncmp(texture_lines[0], "NO ", 3) != 0)
		return (FALSE);
	else if (ft_strncmp(texture_lines[1], "SO ", 3) != 0)
		return (FALSE);
	else if (ft_strncmp(texture_lines[2], "WE ", 3) != 0)
		return (FALSE);
	else if (ft_strncmp(texture_lines[3], "EA ", 3) != 0)
		return (FALSE);
	return (TRUE);
}

char	**extract_texture_lines(t_cube *root_nd)
{
	int		j;
	char	**tmp;

	j = 0;
	tmp = ft_calloc(4 + 1, sizeof(char *));
	if (!tmp)
		return (NULL);
	while (j < 4)
	{
		tmp[j] = ft_strdup(root_nd->file[j]);
		if (!tmp[j])
			return (ft_free_2ptr(tmp), NULL);
		j++;
	}
	tmp[j] = NULL;
	return (tmp);
}

t_bool	textures_are_valid(t_cube *root_nd)
{
	char	**tmp;

	tmp = extract_texture_lines(root_nd);
	if (!tmp)
		return (FALSE);
	if (!check_nomen(tmp))
		return (ft_free_2ptr(tmp), FALSE);
	else if (!xmp_loop_extension(tmp, root_nd))
		return (ft_free_2ptr(tmp), FALSE);
	textures_to_image(root_nd, tmp);
	ft_free_2ptr(tmp);
	return (TRUE);
}

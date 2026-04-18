/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 15:04:24 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/04/17 15:08:04 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	**extract_lines(t_cube *root_nd, int len, int *j)
{
	int		k;
	char	**tmp;

	k = 0;
	tmp = (char **)ft_calloc(len + 1, sizeof(char *));
	if (!tmp)
		return (NULL);
	while (root_nd->file[*j] && k < len)
	{
		while (root_nd->file[*j] && ft_isbreakline(root_nd->file[*j]))
			(*j)++;
		if (!root_nd->file[*j])
			return (ft_printf("There are not colors or textures.\n"),
				ft_free_2ptr(tmp), NULL);
		tmp[k] = ft_normalize_dy_str(root_nd->file[*j]);
		if (!tmp[k])
			return (ft_free_2ptr(tmp), NULL);
		(*j)++;
		k++;
	}
	tmp[k] = NULL;
	return (tmp);
}

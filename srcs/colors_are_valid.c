/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_are_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 13:37:16 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/04/18 17:38:56 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "libft.h"
#include "libftprintf.h"

int	get_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b << 0);
}

t_bool	check_int_errors(char nomen, char *s, int *color, char **ptr)
{
	if (!ft_isdigit(**ptr))
		return (ft_printf("%c %s color \'%c\' is misplaced.\n",
				nomen, s, **ptr), FALSE);
	else
	{
		if (**ptr == '0')
		{
			if ((*ptr)[1] && ft_isdigit((*ptr)[1]))
				return (ft_printf("%c %s "
						"color invalid number format.\n", nomen, s), FALSE);
		}
	}
	*color = ft_atoi(*ptr);
	while (*ptr && ft_isdigit(**ptr))
		(*ptr)++;
	if (**ptr != ',' && **ptr != '\0')
		return (ft_printf("%c %s color is not properly set.\n", nomen, s),
			FALSE);
	else if (*color < 0 || *color > 255)
		return (ft_printf("%c %s color is not in range.\n", nomen, s), FALSE);
	return (TRUE);
}

t_bool	is_int_in_range(char nomen, char *buf, t_color *color)
{
	char	*tmp;

	tmp = &buf[2];
	if (!check_int_errors(nomen, "red", &color->r, &tmp))
		return (FALSE);
	tmp++;
	if (!check_int_errors(nomen, "green", &color->g, &tmp))
		return (FALSE);
	tmp++;
	if (!check_int_errors(nomen, "blue", &color->r, &tmp))
		return (FALSE);
	if (tmp && *tmp != '\0')
		return (ft_printf("Color must be the \'%c n,n,n\'.\n", nomen), FALSE);
	return (TRUE);
}

static t_bool	check_nomen(char **color_lines)
{
	if (ft_strncmp(color_lines[F], "F", 1) != 0)
		return (ft_printf("F nomenclature is wrong.\n"), FALSE);
	else if (ft_strncmp(color_lines[C], "C", 1) != 0)
		return (ft_printf("C nomenclature is wrong.\n"), FALSE);
	return (TRUE);
}

t_bool	colors_are_valid(t_cube *root_nd, int *j)
{
	char	**tmp;
	t_color	color[2];

	tmp = extract_lines(root_nd, 2, j);
	if (!tmp)
		return (ft_free_2ptr(tmp), FALSE);
	if (!check_nomen(tmp))
		return (ft_free_2ptr(tmp), FALSE);
	else if (!is_int_in_range('F', tmp[F], &color[F])
		|| !is_int_in_range('C', tmp[C], &color[C]))
		return (ft_free_2ptr(tmp), FALSE);
	root_nd->f = get_rgb(color[F].r, color[F].g, color[F].b);
	root_nd->c = get_rgb(color[C].r, color[C].g, color[C].b);
	ft_free_2ptr(tmp);
	return (TRUE);
}

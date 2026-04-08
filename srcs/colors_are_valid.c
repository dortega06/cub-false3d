/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_are_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 13:37:16 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/04/08 19:11:47 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "libft.h"
#include "libftprintf.h"

int	get_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b << 0);
}

t_bool	is_int_in_range(char *buf, t_color *color)
{
	int		i;
	char	*tmp;

	i = 2;
	tmp = buf;
	color->r = ft_atoi(&tmp[i]);
	i += ft_countnum(color->r);
	if (color->r < 0 || color->r > 255
		|| tmp[i] != ',' || !ft_isdigit(tmp[i + 1]))
		return (FALSE);
	i++;
	color->g = ft_atoi(&tmp[i]);
	i += ft_countnum(color->g);
	if (color->g < 0 || color->g > 255
		|| tmp[i] != ',' || !ft_isdigit(tmp[i + 1]))
		return (FALSE);
	tmp++;
	color->b = ft_atoi(&tmp[i]);
	i += ft_countnum(color->b);
	if (color->b < 0 || color->b > 255)
		return (FALSE);
	ft_jump_space(tmp, &i);
	if (tmp[i])
		return (ft_printf("da da dance\n"), FALSE);
	return (TRUE);
}

static t_bool	check_nomem(char buf[2][15])
{
	if (ft_strncmp(buf[F], "F ", 2) != 0)
		return (FALSE);
	else if (ft_strncmp(buf[C], "C ", 2) != 0)
		return (FALSE);
	return (TRUE);
}

t_bool	extract_colors_lines(t_cube *root_nd, char buf[2][15])
{
	if (root_nd->file[4][0] != '\n' || root_nd->file[7][0] != '\n')
		return (FALSE);
	if (ft_strlcpy(buf[F], root_nd->file[5], 14) > 14)
		return (FALSE);
	if (ft_strlcpy(buf[C], root_nd->file[6], 14) > 14)
		return (FALSE);
	return (TRUE);
}

t_bool	colors_are_valid(t_cube *root_nd)
{
	char	buf[2][15];
	t_color	color[2];

	if (!extract_colors_lines(root_nd, buf))
		return (FALSE);
	if (!check_nomem(buf))
		return (FALSE);
	else if (!is_int_in_range(buf[F], &color[F])
		|| !is_int_in_range(buf[C], &color[C]))
		return (FALSE);
	root_nd->f = get_rgb(color[F].r, color[F].g, color[F].b);
	root_nd->c = get_rgb(color[C].r, color[C].g, color[C].b);
	return (TRUE);
}

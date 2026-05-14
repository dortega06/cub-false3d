/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_nomen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:41:51 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/05/14 12:05:25 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	sort_colors(char **color_lines, char *nomen[3])
{
	if (ft_strncmp(color_lines[0], nomen[0], 1) != 0)
		ft_swap(&color_lines[0], &color_lines[1]);
}

int	check_color_nomen3(char *color_line)
{
	if (ft_strncmp(color_line, "F", 1) == 0)
		return (0);
	else if (ft_strncmp(color_line, "C", 1) == 0)
		return (1);
	return (-1);
}

t_bool	check_color_nomen2(char **color_lines, t_bool check[2], char *nomen[3])
{
	int		j;
	int		tmp;

	j = 0;
	while (color_lines[j] && j < 2)
	{
		tmp = check_color_nomen3(color_lines[j]);
		if (tmp > 2 || tmp < 0)
			return (ft_printf("Error: Some color nomenclature is wrong.\n"),
				FALSE);
		if (check[tmp] == FALSE)
			check[tmp] = TRUE;
		else
			return (ft_printf("Error: Color %s is duplicated.\n", nomen[tmp]),
				FALSE);
		j++;
	}
	j = 0;
	while (j < 2)
	{
		if (check[j] != TRUE)
			return (ft_printf("Error: %s not founded.\n", nomen[j]), FALSE);
		j++;
	}
	return (TRUE);
}

t_bool	check_color_nomen(char **color_lines)
{
	char	*nomen[3];
	t_bool	check[2];

	check[F] = FALSE;
	check[C] = FALSE;
	nomen[F] = "F";
	nomen[C] = "C";
	nomen[2] = NULL;
	if (!check_color_nomen2(color_lines, check, nomen))
		return (FALSE);
	sort_colors(color_lines, nomen);
	return (TRUE);
}

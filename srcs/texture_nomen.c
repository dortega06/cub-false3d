/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_nomen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:26:02 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/05/14 12:06:28 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	sort_textures(char **texture_lines, char *nomen[5])
{
	int	j;
	int	k;

	j = 0;
	while (j < 4)
	{
		if (ft_strncmp(texture_lines[j], nomen[j], 2) != 0)
		{
			k = j + 1;
			while (k < 4)
			{
				if (ft_strncmp(texture_lines[k], nomen[j], 2) == 0)
				{
					ft_swap(&texture_lines[j], &texture_lines[k]);
					break ;
				}
				k++;
			}
		}
		j++;
	}
}

int	check_textu_nomen3(char *texture_line)
{
	if (ft_strncmp(texture_line, "NO ", 3) == 0)
		return (NO);
	else if (ft_strncmp(texture_line, "SO ", 3) == 0)
		return (SO);
	else if (ft_strncmp(texture_line, "WE ", 3) == 0)
		return (WE);
	else if (ft_strncmp(texture_line, "EA ", 3) == 0)
		return (EA);
	return (-1);
}

t_bool	check_textu_nomen2(char **texture_lines,
			t_bool check[4], char *nomen[5])
{
	int		j;
	int		tmp;

	j = 0;
	while (texture_lines[j] && j < 4)
	{
		tmp = check_textu_nomen3(texture_lines[j]);
		if (tmp > 3 || tmp < 0)
			return (ft_printf("Error: Some texture nomenclature is wrong.\n"),
				FALSE);
		if (check[tmp] == FALSE)
			check[tmp] = TRUE;
		else
			return (ft_printf("Error: Texture %s is duplicated.\n", nomen[tmp]),
				FALSE);
		j++;
	}
	j = 0;
	while (j < 4)
	{
		if (check[j] != TRUE)
			return (ft_printf("Error: %s not founded.\n", nomen[j]), FALSE);
		j++;
	}
	return (TRUE);
}

t_bool	check_textu_nomen(char **texture_lines)
{
	char	*nomen[5];
	t_bool	check[4];

	check[NO] = FALSE;
	check[SO] = FALSE;
	check[WE] = FALSE;
	check[EA] = FALSE;
	nomen[NO] = "NO";
	nomen[SO] = "SO";
	nomen[WE] = "WE";
	nomen[EA] = "EA";
	nomen[4] = NULL;
	if (!check_textu_nomen2(texture_lines, check, nomen))
		return (FALSE);
	sort_textures(texture_lines, nomen);
	return (TRUE);
}

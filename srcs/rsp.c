/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 13:18:08 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/04/10 13:43:57 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "libft.h"
#include "libftprintf.h"

t_bool	only_one_rsp(char **map, t_vex *rsp)
{
	int		j;
	int		k;
	int		nomen_count[4];
	char	*player_nomen;

	k = 0;
	while (k < 4)
		nomen_count[k++] = 0;
	k = 0;
	player_nomen = "NSWE";
	while (player_nomen[k])
	{
		j = 0;
		while (map[j])
		{
			nomen_count[k] += ft_count_c_char(map[j], player_nomen[k]);
			if ((rsp->type != player_nomen[k] && nomen_count[k] > 0)
				|| (rsp->type == player_nomen[k] && nomen_count[k] > 1))
				return (FALSE);
			j++;
		}
		k++;
	}
	return (TRUE);
}

void	check_rsp_vals(const char **map, int j, char *start, t_vex *rsp)
{
	if (start)
		rsp->x = start - map[j];
	else
		rsp->x = -1;
	if (map[j])
		rsp->y = j;
	else
		rsp->y = -1;
	if (rsp->x != -1 && rsp->y != -1)
		rsp->type = *start;
}

t_vex	rsp(const char **map, t_vex *rsp)
{
	int		j;
	int		k;
	char	*start;
	char	*player_nomen;

	k = 0;
	start = NULL;
	player_nomen = "NSWE";
	while (!start && player_nomen[k])
	{
		j = 0;
		while (map[j])
		{
			start = ft_strchr(map[j], player_nomen[k]);
			if (start)
				break ;
			j++;
		}
		k++;
	}
	check_rsp_vals(map, j, start, rsp);
	return (*rsp);
}

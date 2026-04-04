/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:56:08 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/04/04 19:53:58 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9' )
		return (1);
	else
		return (0);
}

int	ft_str_isdigit(const char *str)
{
	int	i;

	i = 0;
	ft_jump_space(str, &i);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (!(ft_isdigit(str[i])))
		{
			ft_jump_space(str, &i);
			if (str[i])
				return (0);
			else
				return (1);
		}
		i++;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:00:09 by mcuenca-          #+#    #+#             */
/*   Updated: 2024/12/16 12:46:06 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int	alpha;
	int	digit;

	alpha = ft_isalpha(c);
	digit = ft_isdigit(c);
	if (alpha == 1 || digit == 1)
		return (1);
	else
		return (0);
}

int	ft_str_isalnum(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(ft_isalnum(str[i])))
			return (0);
		i++;
	}
	return (1);
}

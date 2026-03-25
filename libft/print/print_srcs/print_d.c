/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:33:55 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/03/21 14:00:14 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_d(long int d)
{
	int		i;
	int		counter;
	char	*c;

	counter = ft_countnum(d);
	i = counter;
	c = ft_calloc (i + 1, sizeof(char));
	if (!c)
		return (-1);
	if (d == 0)
		c[0] = '0';
	if (d < 0)
	{
		c[0] = '-';
		d *= -1;
	}
	c[i--] = '\0';
	while (d)
	{
		c[i--] = d % 10 + '0';
		d = d / 10;
	}
	if (print_s(c) < 0)
		return (free(c), -1);
	return (free(c), counter);
}

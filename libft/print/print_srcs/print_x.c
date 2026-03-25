/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:30:58 by mcuenca-          #+#    #+#             */
/*   Updated: 2024/08/28 15:10:45 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_x_lowercase(unsigned int x)
{
	int		counter;
	int		check;
	char	*str;

	counter = 0;
	str = "0123456789abcdef";
	if (x >= 16)
	{
		check = print_x_lowercase(x / 16);
		if (check < 0)
			return (-1);
		counter += check;
	}
	check = print_c(str[x % 16]);
	if (check < 0)
		return (-1);
	counter += check;
	return (counter);
}

int	print_x_uppercase(unsigned int x)
{
	int		counter;
	int		check;
	char	*str;

	counter = 0;
	str = "0123456789ABCDEF";
	if (x >= 16)
	{
		check = print_x_uppercase(x / 16);
		if (check < 0)
			return (-1);
		counter += check;
	}
	check = print_c(str[x % 16]);
	if (check < 0)
		return (-1);
	counter += check;
	return (counter);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:09:52 by mcuenca-          #+#    #+#             */
/*   Updated: 2024/08/28 15:08:29 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	print_s(char *s)
{
	int	counter;
	int	check;
	int	i;

	i = 0;
	counter = 0;
	check = 0;
	if (!s)
		s = "(null)";
	while (s[i] != '\0')
	{
		check = print_c(s[i++]);
		if (check < 0)
			return (-1);
		counter += check;
	}
	return (counter);
}

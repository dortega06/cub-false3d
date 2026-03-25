/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:17:17 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/03/21 14:04:29 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	long int	nlong;
	long int	i;
	char		*c;

	nlong = n;
	i = ft_countnum(nlong);
	c = ft_calloc(i + 1, sizeof(char));
	if (!c)
		return (NULL);
	if (nlong == 0)
		c[0] = '0';
	if (n < 0)
	{
		c[0] = '-';
		nlong *= -1;
	}
	c[i--] = '\0';
	while (nlong)
	{
		c[i--] = nlong % 10 + '0';
		nlong = nlong / 10;
	}
	return (c);
}

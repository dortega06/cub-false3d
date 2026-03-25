/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:29:29 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/03/21 14:01:46 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_ptoh(long int x, long long int count)
{
	long int	i;
	char		*c;

	i = count;
	c = ft_calloc(i + 1, sizeof(char));
	if (!c)
		return (NULL);
	if (x == 0)
		c[0] = '0';
	c[i--] = '\0';
	while (x)
	{
		c[i] = x % 16 + '0';
		if (c[i] >= ':' && c[i] <= '?')
			c[i] = c[i] + 39;
		i--;
		x = x / 16;
	}
	c[0] = '0';
	c[1] = 'x';
	return (c);
}

int	print_p(void *p)
{
	long long int	t_p;
	int				counter;
	int				check;
	char			*str;

	t_p = (long long int)p;
	if (p == NULL)
	{
		if (print_s("(nil)") < 0)
			return (-1);
		return (5);
	}
	counter = ft_countnumhexa(t_p) + 2;
	str = ft_ptoh(t_p, counter);
	if (!str)
		return (-1);
	check = print_s(str);
	free(str);
	if (check < 0)
		return (-1);
	return (counter);
}

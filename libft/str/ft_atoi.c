/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:42:12 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/04/08 14:22:22 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "libftprintf.h"

int	is_overflow(char *str)
{
	int		sign;
	int		len;
	char	*start;

	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	start = str;
	while (ft_isdigit(*str))
		str++;
	len = str - start;
	if (len > 10)
		return (1);
	if (len == 10
		&& ((sign == 1 && ft_strcmp(start, MAX_INT_CHAR) > 0)
			|| (sign == -1 && ft_strcmp(start, MIN_INT_CHAR) > 0)))
		return (1);
	return (0);
}

int	ft_full_str_atoi(const char *nptr)
{
	int			i;
	long int	num;
	int			mul;

	i = 0;
	num = 0;
	mul = 1;
	if (!nptr || !ft_str_isdigit(nptr))
		return (0);
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		nptr++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			mul = -1;
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		num = nptr[i++] - '0' + num * 10;
		if ((num * mul) < -2147483648 || (num * mul) > 2147483647)
			return (0);
	}
	return (mul * num);
}

int	ft_atoi(const char *nptr)
{
	int	index;
	int	num;
	int	mul;

	index = 0;
	num = 0;
	mul = 1;
	while (nptr[index] == 32 || (nptr[index] >= 9 && nptr[index] <= 13))
		index++;
	if (nptr[index] == '-' || nptr[index] == '+')
	{
		if (nptr[index] == '-')
			mul = -1;
		index++;
	}
	while (nptr[index] > 47 && nptr[index] < 58)
	{
		num = nptr[index] - '0' + num * 10;
		index++;
	}
	return (mul * num);
}

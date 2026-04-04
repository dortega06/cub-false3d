/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:11:00 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/04/04 14:57:59 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if ((c >= 0) && (c <= 127))
		return (1);
	else
		return (0);
}

int	ft_str_isascii(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(ft_isascii(str[i])))
			return (0);
		i++;
	}
	return (1);
}

int	ft_str_what_is(const	char *str)
{
	if (ft_str_isdigit(str))
		return (1);
	else if (ft_str_isalpha(str))
		return (2);
	else if (ft_str_isalnum(str))
		return (3);
	else if (ft_str_isprint(str))
		return (4);
	else if (ft_str_isascii(str))
		return (5);
	return (0);
}

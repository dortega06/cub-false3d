/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:44:05 by mcuenca-          #+#    #+#             */
/*   Updated: 2024/08/28 14:59:46 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	ft_type(va_list *varlst, char format)
{
	int	i;

	i = 0;
	if (format == 'c')
		i = print_c(va_arg(*varlst, int));
	else if (format == 's')
		i = print_s(va_arg(*varlst, char *));
	else if (format == 'p')
		i = print_p(va_arg(*varlst, void *));
	else if (format == 'd' || format == 'i')
		i = print_d(va_arg(*varlst, int));
	else if (format == 'u')
		i = print_u(va_arg(*varlst, unsigned int));
	else if (format == 'x')
		i = print_x_lowercase(va_arg(*varlst, unsigned int));
	else if (format == 'X')
		i = print_x_uppercase(va_arg(*varlst, unsigned int));
	else if (format == '%')
		i = print_c('%');
	else if (format == '\0')
		return (0);
	return (i);
}

int	ft_iter(va_list *varlst, char const *str, int i, int j)
{
	int	check;

	while (str[i])
	{
		if (str[i] == '%')
		{
			check = ft_type(varlst, str[++i]);
			if (check < 0)
				return (-1);
			j += check;
			if (str[i])
				i++;
		}
		else
		{
			if (print_c(str[i++]) == -1)
				return (-1);
			j++;
		}
	}
	return (j);
}

int	ft_printf(char const *str, ...)
{
	va_list	varlst;
	int		i;
	int		j;
	int		check;

	va_start(varlst, str);
	i = 0;
	j = 0;
	check = ft_iter(&varlst, str, i, j);
	if (check < 0)
		return (va_end(varlst), -1);
	j = check;
	va_end(varlst);
	return (j);
}

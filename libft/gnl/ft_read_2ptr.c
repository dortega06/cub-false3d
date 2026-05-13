/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_2ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 17:53:46 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/05/13 13:47:45 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_read_2ptr(char **content, char c)
{
	int	i;

	i = 0;
	if (!content)
		return ;
	if (c == '\n')
	{
		while (content[i])
		{
			ft_printf("%s\n", content[i]);
			i++;
		}
	}
	else if (c == '\0')
	{
		while (content[i])
		{
			ft_printf("%s", content[i]);
			i++;
		}
	}
	else
		ft_printf("Char have to be '\\n' or '\\0'.\n");
}

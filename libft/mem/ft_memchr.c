/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:08:52 by mcuenca-          #+#    #+#             */
/*   Updated: 2024/07/25 14:55:51 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*t_s;
	unsigned char	t_c;

	index = 0;
	t_s = (unsigned char *)s;
	t_c = (unsigned char)c;
	while (index < n)
	{
		if (t_s[index] == t_c)
			return ((void *)&t_s[index]);
		index++;
	}
	return (NULL);
}

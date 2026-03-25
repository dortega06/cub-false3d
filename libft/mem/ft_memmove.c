/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:50:19 by mcuenca-          #+#    #+#             */
/*   Updated: 2024/07/24 18:04:08 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			index;
	unsigned char	*t_dst;
	unsigned char	*t_src;

	if ((!dst && !src) || n == 0)
		return (dst);
	index = 0;
	t_dst = (unsigned char *)dst;
	t_src = (unsigned char *)src;
	if (t_dst < t_src)
	{
		while (n > index)
		{
			t_dst[index] = t_src[index];
			index++;
		}
	}
	else
	{
		while (0 < n--)
			t_dst[n] = t_src[n];
	}
	return ((void *)t_dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:06:07 by mcuenca-          #+#    #+#             */
/*   Updated: 2024/07/06 15:23:49 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			index;
	unsigned char	*t_dst;
	unsigned char	*t_src;

	if (!dst && !src)
		return (0);
	index = 0;
	t_dst = (unsigned char *) dst;
	t_src = (unsigned char *) src;
	while (index < n)
	{
		t_dst[index] = t_src[index];
		index++;
	}
	return (dst);
}

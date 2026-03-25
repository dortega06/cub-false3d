/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:39:25 by mcuenca-          #+#    #+#             */
/*   Updated: 2024/07/25 12:23:53 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	len;

	index = 0;
	len = ft_strlen(src);
	if (size != 0)
	{
		while (src[index] && size - 1 > index)
		{
			dst[index] = src[index];
			index++;
		}
		dst[index] = '\0';
	}
	return (len);
}

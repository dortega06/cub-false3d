/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:17:31 by mcuenca-          #+#    #+#             */
/*   Updated: 2024/07/28 20:47:51 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*t_s;
	unsigned char	t_c;

	index = 0;
	t_s = (unsigned char *)s;
	t_c = (unsigned char)c;
	if (n == 0)
		return (((void *)t_s));
	while (index < n)
	{
		t_s[index] = t_c;
		index++;
	}
	return ((void *)t_s);
}

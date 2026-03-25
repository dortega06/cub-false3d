/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 09:33:59 by mcuenca-          #+#    #+#             */
/*   Updated: 2024/07/28 19:08:07 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;
	unsigned char	*t_s1;
	unsigned char	*t_s2;

	if ((!s1 && !s2) || n == 0)
		return (0);
	index = 0;
	t_s1 = (unsigned char *)s1;
	t_s2 = (unsigned char *)s2;
	while (t_s1[index] == t_s2[index] && index < n - 1)
		index++;
	if (t_s1[index] != t_s2[index])
		return (t_s1[index] - t_s2[index]);
	else
		return (0);
}

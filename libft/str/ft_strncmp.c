/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:36:23 by mcuenca-          #+#    #+#             */
/*   Updated: 2024/07/28 20:52:54 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			asciidiff;
	size_t			index;
	unsigned char	*t_s1;
	unsigned char	*t_s2;

	if ((!s1 && !s2) || n == 0)
		return (0);
	index = 0;
	t_s1 = (unsigned char *)s1;
	t_s2 = (unsigned char *)s2;
	while (index < n)
	{
		if (t_s1[index] != t_s2[index]
			|| t_s1[index] == '\0' || t_s2[index] == '\0')
		{
			asciidiff = t_s1[index] - t_s2[index];
			return ((int)asciidiff);
		}
		index++;
	}
	return (0);
}

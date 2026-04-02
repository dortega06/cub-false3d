/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:46:54 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/03/31 17:44:50 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*space;

	if (size != 0)
		if (nmemb > ULLONG_MAX / size)
			return (NULL);
	space = malloc(nmemb * size);
	if (!space)
		return (NULL);
	ft_bzero(space, nmemb * size);
	return (space);
}

//gnl
/*void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t		i;
	char		*space;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (NULL);
	space = malloc(nmemb * size);
	if (!space)
		return (NULL);
	while (i < nmemb * size)
		space[i++] = '\0';
	return (space);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:23:11 by mcuenca-          #+#    #+#             */
/*   Updated: 2024/12/16 16:00:40 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_intdup(int num)
{
	int	*copy;

	copy = ft_calloc(1, sizeof(int));
	*copy = num;
	if (!copy || *copy != num)
		return (NULL);
	return (copy);
}

char	*ft_strdup(const char *s)
{
	int		index;
	char	*copy;
	char	*t_s;

	index = 0;
	copy = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!copy)
		return (NULL);
	t_s = (char *) s;
	while (t_s[index] != '\0')
	{
		copy[index] = t_s[index];
		index++;
	}
	copy[index] = '\0';
	return (copy);
}

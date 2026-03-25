/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:17:55 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/03/21 14:54:23 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		t;
	char	**newarray;

	i = 0;
	newarray = (char **)ft_calloc(ft_countwords(s, c) + 1, sizeof(char *));
	if (!s || !newarray)
		return (0);
	t = 0;
	while (t < ft_countwords(s, c))
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		newarray[t] = ft_substr(s, j, i - j);
		if (!newarray[t])
			return (ft_free_2parray(newarray), NULL);
		t++;
	}
	newarray[t] = NULL;
	return (newarray);
}

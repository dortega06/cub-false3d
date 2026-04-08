/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_gnl_cube.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 10:44:25 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/04/08 12:25:51 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include "gnl.h"
#include <stdlib.h>

char	**fill_2ptr(char const *s, char c, char **dest, int words)
{
	int		i;
	int		j;
	int		len;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	while (count < words)
	{
		j = i;
		while (s[j] && s[j] != c)
			j++;
		len = j - i;
		if (len == 0)
			len = 1;
		dest[count] = ft_substr(s, i, len);
		if (!dest[count])
			return (NULL);
		i = j + 1;
		count++;
	}
	dest[count] = NULL;
	return (dest);
}

char	**split_gnl_cube(char const *s, char c)
{
	int		words;
	char	**tmp;

	words = ft_count_c_char(s, c);
	tmp = (char **)ft_calloc(words + 1, sizeof(char *));
	if (!tmp)
		return (NULL);
	tmp = fill_2ptr(s, c, tmp, words);
	if (!tmp)
		return (ft_free_2ptr(tmp), NULL);
	return (tmp);
}

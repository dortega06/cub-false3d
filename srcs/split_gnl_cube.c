/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_gnl_cube.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 10:44:25 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/04/18 14:00:17 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include "gnl.h"
#include <stdlib.h>

char	*save_new_line(const char *s, int start, int len, int max_len)
{
	char	*tmp;

	if (len == 0)
	{
		tmp = ft_calloc(max_len, sizeof(char));
		tmp[0] = '\n';
	}
	else
		tmp = ft_substr(s, start, len);
	if (!tmp)
		return (NULL);
	return (tmp);
}

int	substr_max_len(const char *s, char c, int words)
{
	int	i;
	int	j;
	int	count;
	int	max_len;
	int	len;

	i = 0;
	j = 0;
	count = 0;
	max_len = 0;
	len = 0;
	while (count < words)
	{
		j = i;
		while (s[j] && s[j] != c)
			j++;
		len = j - i;
		if (len == 0)
			len = 1;
		if (len > max_len)
			max_len = len;
		i = j + 1;
		count++;
	}
	return (max_len);
}

char	**fill_2ptr(char const *s, char c, int words, int max_len)
{
	int		i;
	int		j;
	int		len;
	int		count;
	char	**tmp;

	i = 0;
	j = 0;
	count = 0;
	tmp = (char **)ft_calloc(words + 1, sizeof(char *));
	if (!tmp)
		return (NULL);
	while (count < words)
	{
		j = i;
		while (s[j] && s[j] != c)
			j++;
		len = j - i;
		tmp[count] = save_new_line(s, i, len, max_len);
		if (!tmp[count])
			return (ft_free_2ptr(tmp), NULL);
		i = j + 1;
		count++;
	}
	return (tmp);
}

char	**split_gnl_cube(char const *s, char c)
{
	int		max_len;
	int		words;
	char	**tmp;

	words = ft_count_c_char(s, c);
	max_len = substr_max_len(s, c, words);
	tmp = fill_2ptr(s, c, words, max_len);
	if (!tmp)
		return (ft_free_2ptr(tmp), NULL);
	return (tmp);
}

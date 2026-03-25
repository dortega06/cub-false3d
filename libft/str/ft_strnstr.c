/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:10:10 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/03/21 15:01:37 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*t_big;
	char	*t_little;

	i = 0;
	t_little = (char *)little;
	t_big = (char *) big;
	if (*little == '\0')
		return ((char *)big);
	while (t_big[i] != '\0' && len > i)
	{
		j = 0;
		while (t_big[i + j] == t_little[j]
			&& t_little[j] != '\0'
			&& len > (i + j))
			j++;
		if (t_little[j] == '\0')
			return (&t_big[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;

	if (!haystack || !needle)
		return (NULL);
	i = 0;
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] && needle[j] && haystack[i + j] == needle[j])
			j++;
		if (!needle[j])
			return ((char *)(&haystack[i]));
		i++;
	}
	return (NULL);
}

char	*ft_strrstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;

	if (!haystack || !needle)
		return (NULL);
	i = 0;
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] && needle[j] && haystack[i + j] == needle[j])
			j++;
		if (!needle[j])
			return ((char *)(&haystack[i + j - 1]));
		i++;
	}
	return (NULL);
}

int	ft_strrstr_count(const char *haystack, const char *needle)
{
	int		count;
	char	*tmp;

	if (!haystack || !needle)
		return (0);
	count = 0;
	tmp = (char *)haystack;
	while (tmp)
	{
		count++;
		tmp++;
		tmp = ft_strrstr(tmp, needle);
	}
	return (count);
}

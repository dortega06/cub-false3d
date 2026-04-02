/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:20:09 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/04/01 10:29:26 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_s;
	char	*substr;

	i = start;
	j = 0;
	len_s = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start >= len_s)
		return (ft_calloc(1, sizeof(char)));
	if (start + len > len_s)
		len = len_s - start;
	while (s[i] != '\0' && i < start + len)
		i++;
	substr = ft_calloc(i - start + 1, sizeof(char));
	if (substr == NULL)
		return (NULL);
	i = start;
	if (start < len_s)
		while (s[i] != '\0' && i < start + len)
			substr[j++] = s[i++];
	substr[j] = '\0';
	return (substr);
}

//gnl
/*char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	char	*newstr;

	i = 0;
	len_s = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start >= len_s)
		return (NULL);
	if (start + len > len_s)
		len = len_s - start;
	newstr = ft_calloc(len + 1, sizeof(char));
	if (!newstr)
		return (NULL);
	while (i < len)
	{
		newstr[i] = s[start + i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}*/

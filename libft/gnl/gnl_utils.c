/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:20:44 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/04/02 17:06:24 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

void	*ft_calloc_gnl(size_t nmemb, size_t size)
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
}

size_t	ft_strlen_gnl(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	int				i;
	char			*chr_s;
	unsigned char	un_c;

	i = 0;
	chr_s = (char *)s;
	un_c = (unsigned char)c;
	while (chr_s[i] != '\0')
	{
		if (chr_s[i] == un_c)
			return (&chr_s[i]);
		i++;
	}
	if (chr_s[i] == '\0' && un_c == '\0')
		return (&chr_s[i]);
	return (NULL);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	char	*newstr;

	i = 0;
	len_s = ft_strlen_gnl(s);
	if (!s)
		return (NULL);
	if (start >= len_s)
		return (NULL);
	if (start + len > len_s)
		len = len_s - start;
	newstr = ft_calloc_gnl(len + 1, sizeof(char));
	if (!newstr)
		return (NULL);
	while (i < len)
	{
		newstr[i] = s[start + i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*s3;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	s3 = ft_calloc_gnl(len + 1, sizeof(char));
	if (!s3)
		return (NULL);
	while (s1[i] != '\0')
		s3[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		s3[j++] = s2[i++];
	s3[j] = '\0';
	return (s3);
}

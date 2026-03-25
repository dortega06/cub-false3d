/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:29:12 by mcuenca-          #+#    #+#             */
/*   Updated: 2025/01/31 14:43:48 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*newstr;

	i = 0;
	j = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	while (s1 && s1[i] != '\0')
		i++;
	while (s2 && s2[j] != '\0')
		j++;
	newstr = ft_calloc(i + j + 1, sizeof(char));
	if (!newstr)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i] != '\0')
		newstr[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i] != '\0')
		newstr[j++] = s2[i++];
	newstr[j] = '\0';
	return (newstr);
}

//gnl
/*char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*s3;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	s3 = ft_calloc(len + 1, sizeof(char));
	if (!s3)
		return (NULL);
	while (s1 && s1[i] != '\0')
		s3[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i] != '\0')
		s3[j++] = s2[i++];
	s3[j] = '\0';
	return (s3);
}*/

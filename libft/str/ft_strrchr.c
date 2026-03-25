/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:02:21 by mcuenca-          #+#    #+#             */
/*   Updated: 2024/07/25 15:55:33 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			index;
	char			*t_s;
	unsigned char	t_c;

	t_s = (char *)s;
	t_c = (unsigned) c;
	index = ft_strlen(t_s);
	while (t_s[index] != t_c && index != 0)
		index--;
	if (t_s[index] == t_c)
		return (&t_s[index]);
	else
		return (0);
}

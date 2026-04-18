/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 14:46:16 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/04/17 15:03:27 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fill_str(char *dest, char *s, int len)
{
	int		h;
	int		i;
	t_bool	space;

	h = 0;
	i = 0;
	space = TRUE;
	while (s[i] && h < len)
	{
		ft_jump_space(s, &i);
		while (s[i] && !ft_isspace(s[i]))
		{
			if (space == FALSE)
			{
				dest[h] = ' ';
				h++;
				space = TRUE;
			}
			dest[h] = s[i];
			h++;
			i++;
		}
		space = FALSE;
	}
	dest[h] = '\0';
}

int	required_mem(char *s)
{
	int		i;
	int		tmp;
	t_bool	space;

	i = 0;
	tmp = 0;
	space = TRUE;
	while (s && s[i])
	{
		ft_jump_space(s, &i);
		while (s[i] && !ft_isspace(s[i]))
		{
			if (space == FALSE)
			{
				tmp++;
				space = TRUE;
			}
			i++;
			tmp++;
		}
		space = FALSE;
	}
	return (tmp);
}

t_mem	ft_normalize_st_str(char *dest, char *s, int dest_len)
{
	int	count;

	count = required_mem(s);
	if (count > dest_len)
		return (LACK);
	fill_str(dest, s, dest_len);
	if (count < dest_len)
		return (TOO);
	return (FIT);
}

char	*ft_normalize_dy_str(const char *s)
{
	int		len;
	char	*tmp;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	tmp = ft_calloc(len + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	fill_str(tmp, (char *)s, len);
	return (tmp);
}

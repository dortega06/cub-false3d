/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 12:03:06 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/04/02 18:08:35 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"
#include "libft.h"
#include "libftprintf.h"
#include <stdlib.h>

int	keep_and_remain(char *tmp, char **dest, char **rem, int return_val)
{
	int		tmp_len;
	int		start;
	char	*ptr_start;

	ptr_start = ft_strchr_gnl(tmp, '\n');
	if (ptr_start)
		start = ptr_start - tmp + 1;
	else
		return (ENDOF);
	tmp_len = ft_strlen_gnl(tmp);
	*dest = ft_substr_gnl(tmp, 0, start);
	if (!*dest)
		return (MALLOC);
	*rem = ft_substr_gnl(tmp, start, tmp_len);
	if (!*rem && return_val != ENDOF)
		return (ft_free(*dest), MALLOC);
	return (OK);
}

char	*concat_reading_lines(char **tmp, const char *buf)
{
	int	tmp_len;
	int	buf_len;

	tmp_len = ft_strlen_gnl(*tmp);
	buf_len = ft_strlen_gnl(buf);
	*tmp = ft_realloc(*tmp, tmp_len + buf_len + 1);
	if (!tmp)
		return (NULL);
	(*tmp)[tmp_len] = '\0';
	ft_strlcat(*tmp, buf, tmp_len + buf_len + 1);
	return (*tmp);
}

static int	loop(int fd, char **tmp)
{
	int		bytes;
	char	buf[BUFFER_SIZE + 1];

	bytes = 0;
	buf[0] = '\0';
	while (!(ft_strchr_gnl(buf, '\n')))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
			return (ft_printf("ERROR\n"), ERR);
		if (bytes == 0)
			return (ENDOF);
		buf[bytes] = '\0';
		if (!concat_reading_lines(tmp, buf))
			return (ft_printf("MALLOC"), MALLOC);
	}
	return (OK);
}

int	gnl(int fd, char **dest)
{
	int			return_val;
	char		*tmp;
	static char	*rem;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483646)
		return (ERR);
	if (rem)
		tmp = rem;
	else
	{
		tmp = ft_calloc(1, sizeof(char));
		if (!tmp)
			return (MALLOC);
	}
	return_val = loop(fd, &tmp);
	if (return_val != OK && return_val != ENDOF)
		return (ft_free(tmp), return_val);
	return_val = keep_and_remain(tmp, dest, &rem, return_val);
	if (return_val != OK)
		return (ft_free(tmp), return_val);
	ft_free(tmp);
	return (OK);
}

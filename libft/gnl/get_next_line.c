/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:49:27 by mcuenca-          #+#    #+#             */
/*   Updated: 2024/10/07 14:58:59 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

char	*keep_and_remain(char *keepit, int wc)
{
	int		start;	
	char	*new_keepit;

	start = ft_strchr(keepit, '\n') - keepit + 1;
	if (wc == 0)
		new_keepit = ft_substr(keepit, wc, start);
	else
		new_keepit = ft_substr(keepit, start, wc);
	if (!new_keepit)
		return (NULL);
	return (new_keepit);
}

char	*fill_phrase(int fd, char *buffer, char *concat)
{
	ssize_t	bytes;
	char	*tmp;

	while (!(ft_strchr(buffer, '\n')))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buffer), concat);
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		tmp = concat;
		concat = ft_strjoin(tmp, buffer);
		if (tmp[0] != '\0')
			free(tmp);
		if (!concat)
			return (NULL);
	}
	free(buffer);
	return (concat);
}

char	*get_next_line(int fd)
{
	char		*tmp;
	char		*concat;
	static char	*buffer;

	concat = "\0";
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483646)
		return (NULL);
	if (buffer)
	{
		concat = ft_strjoin(concat, buffer);
		free(buffer);
	}
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer || !concat)
		return (NULL);
	tmp = fill_phrase(fd, buffer, concat);
	if (!tmp)
		return (NULL);
	buffer = keep_and_remain(tmp, ft_strlen(tmp));
	concat = keep_and_remain(tmp, 0);
	if (tmp[0] != '\0')
		free(tmp);
	if (!concat)
		return (NULL);
	return (concat);
}

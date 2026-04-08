/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub_extension.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 16:49:01 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/04/08 13:25:34 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include "gnl.h"
#include "cube3d.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

t_bool	read_sample(char **content, int sample)
{
	int	i;
	int	j;

	if (!content || (content && !*content) || sample < 0)
		return (FALSE);
	j = 0;
	while (content[j] && j < sample)
	{
		i = 0;
		while (content[j][i])
		{
			if (!ft_isprint(content[j][i]) && !ft_isspace(content[j][i]))
				return (FALSE);
			i++;
		}
		j++;
	}
	return (TRUE);
}

char	*loop_concat(char **one_line, char *tmp)
{
	int		one_line_len;
	int		tmp_len;

	one_line_len = ft_strlen(*one_line);
	tmp_len = ft_strlen(tmp);
	*one_line = ft_realloc(*one_line, one_line_len + tmp_len + 1);
	if (!*one_line)
		return (NULL);
	(*one_line)[one_line_len] = '\0';
	ft_strlcat(*one_line, tmp, one_line_len + tmp_len + 1);
	ft_free(tmp);
	return (*one_line);
}

static char	*loop(int fd)
{
	int		return_val;
	char	*one_line;
	char	*tmp;

	one_line = ft_calloc(1, 1);
	if (!one_line)
		return (NULL);
	while (one_line)
	{
		return_val = gnl(fd, &tmp);
		if (return_val == MALLOC)
			return (ft_free(one_line), NULL);
		else if (return_val == ENDOF)
			return (one_line);
		if (!loop_concat(&one_line, tmp))
			return (ft_free(one_line), ft_free(tmp), NULL);
	}
	return (one_line);
}

char	**read_content(int fd)
{
	char	*tmp;
	char	**content;

	tmp = loop(fd);
	if (!tmp)
		return (NULL);
	content = split_gnl_cube(tmp, '\n');
	if (!content)
		return (ft_free(tmp), NULL);
	ft_free(tmp);
	return (content);
}

t_bool	check_cub_extension(char *file, t_cube *root_nd)
{
	int		full_len;
	char	**content;

	full_len = ft_strlen(file);
	if (file[full_len - 4] != '.'
		|| file[full_len - 3] != 'c'
		|| file[full_len - 2] != 'u'
		|| file[full_len - 1] != 'b')
		return (ft_printf("Wrong extension.\n"), FALSE);
	content = read_content(root_nd->fd);
	if (!content)
		return (FALSE);
	if (!read_sample(content, 8))
		return (ft_free_2ptr(content), FALSE);
	root_nd->file = content;
	return (TRUE);
}

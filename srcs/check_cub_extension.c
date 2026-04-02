/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub_extension.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 16:49:01 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/04/02 19:12:33 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include "cube3d.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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

/*static char	*loop(int fd)
{
	int		return_val;
	int		one_line_len;
	int		tmp_len;
	char	*one_line;
	char	*tmp;

	one_line = ft_calloc(1, 1);
	if (!one_line)
		return (NULL);
	tmp = "";
	while (tmp)//while (one_line)
	{
		return_val = gnl(fd, &tmp);
		if (return_val == MALLOC)
			return (ft_free(one_line), NULL);
		else if (return_val == ENDOF)
			return (printf("patata\n"), one_line);
		one_line_len = ft_strlen(one_line);
		tmp_len = ft_strlen(tmp);
		one_line = ft_realloc(one_line, one_line_len + tmp_len + 1);
		if (!one_line)
			return (ft_free(one_line), ft_free(tmp), NULL);
		one_line[one_line_len] = '\0';
		ft_strlcat(one_line, tmp, one_line_len + tmp_len + 1);
		ft_free(tmp);
	}
	return (one_line);
}*/

char	**read_content(int fd)
{
	char	*tmp;
	char	**content;

	tmp = loop(fd);
	if (!tmp)
		return (NULL);
	content = ft_split(tmp, '\n');
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
	root_nd->file = content;
	return (TRUE);
}
/*hacer gnl
 * guarda el contenido ojo a los leaks y punteros
 * liberar si falla
 * comproba en un muestra que todo son chars printeables*/

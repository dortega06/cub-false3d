/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 15:25:33 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/04/04 21:31:45 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "cube3d.h"
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

int	file_err(char *file_name, t_cube *root_nd)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (perror("Error"), -1);
	root_nd->fd = fd;
	return (fd);
}

t_bool	parse_cub(char *file_name, t_cube *root_nd)
{
	int	fd;

	if (!file_name && file_name[0] == '\0')
		return (ft_printf("File does not exist"), FALSE);
	fd = file_err(file_name, root_nd);
	if (fd < 0)
		return (FALSE);
	if (!extension(file_name, "cub", root_nd))
		return (FALSE);
	close(fd);
	root_nd->fd = -1;
	if (!content_is_valid(root_nd))
		return (FALSE);
	return (TRUE);
}

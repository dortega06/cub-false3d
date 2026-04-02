/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 15:25:33 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/03/28 19:37:18 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "cube3d.h"
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

int	file_err(char *file, t_cube *root_nd)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (perror("Error"), -1);
	root_nd->fd = fd;
	return (fd);
}

t_bool	parse_cub(char *file, t_cube *root_nd)
{
	int	fd;

	if (!file && file[0] == '\0')
		return (ft_printf("File does not exist"), FALSE);
	fd = file_err(file, root_nd);
	if (fd < 0)
		return (FALSE);
	else if (!extension(file, "cub", root_nd))
		return (FALSE);
	/*else if (!content_is_valid(file, root_nd))
		return (FALSE);*/
	return (TRUE);
}

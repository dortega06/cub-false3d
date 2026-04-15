/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 15:25:33 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/04/15 18:38:54 by mcuenca-         ###   ########.fr       */
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
	if (!check_mng(file_name, "cub", root_nd))
		return (FALSE);
	if (!content_is_valid(root_nd))
		return (FALSE);
	return (TRUE);
}

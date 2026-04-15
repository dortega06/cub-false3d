/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_xpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 20:40:33 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/04/15 17:11:53 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "libftprintf.h"
#include <fcntl.h>

t_bool	check_pattern(char *buf)
{
	int		i;
	int		sample;
	char	*tmp;

	tmp = buf;
	if (ft_strncmp(tmp, "/* XPM */", 9) != 0)
		return (FALSE);
	tmp = ft_strchr(buf, '\n') + 1;
	if (ft_strncmp(tmp, "static char *", 13) != 0)
		return (FALSE);
	i = 0;
	sample = 100;
	tmp = ft_strchr(tmp, '\n') + 1;
	while (i < sample)
	{
		if (!ft_isprint(tmp[i]) && !ft_isspace(tmp[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	check_inside(int fd)
{
	int		bytes;
	char	buf[500 + 1];

	bytes = read(fd, buf, 500);
	if (bytes < 0)
		return (ERR);
	if (bytes == 0)
		return (ENDOF);
	buf[bytes] = '\0';
	if (!check_pattern(buf))
		return (ERR);
	return (OK);
}

t_bool	check_xpm(char *file, t_cube *root_nd)
{
	int	fd;
	int	full_len;

	full_len = ft_strlen(file);
	if (ft_strncmp(&file[full_len - 4], ".xpm", 4) != 0)
		return (ft_printf("Wrong extension for texture.\n"), FALSE);
	fd = file_err(file, root_nd);
	if (fd < 0)
		return (FALSE);
	if (check_inside(fd) != OK)
		return (FALSE);
	close(fd);
	return (TRUE);
}

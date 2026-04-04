/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_xpm_extension.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 20:40:33 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/04/04 21:40:07 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "libftprintf.h"

t_bool	check_xpm_extension(char *file, t_cube *root_nd)
{
	int	fd;
	int		full_len;

	full_len = ft_strlen(file);
	if (file[full_len - 4] != '.'
		|| file[full_len - 3] != 'x'
		|| file[full_len - 2] != 'p'
		|| file[full_len - 1] != 'm')
		return (ft_printf("Wrong extension.\n"), FALSE);
	fd = file_err(file, root_nd);
	if (fd < 0)
		return (FALSE);
	//AQUI, leer el xpm? Porque si haces gnl_cube en la var static se te quedara media linea leida.
	close(fd);
	return (TRUE);
}

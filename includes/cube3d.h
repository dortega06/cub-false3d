/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 14:22:28 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/04/04 20:45:32 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//nombre del archivo
//los permisos y abertura del archivo
///// como saber que si .cub i .xpm
///// bandera si leo .cub o .xpm
///// si es cub leo todo, analizo una muestra y lo guardo
///// si es xpm lego una muestra, analizo la muestra y no lo guardo
//el archivo
#ifndef CUBE3D_H
# define CUBE3D_H

# ifndef FULL
#  define FULL -1
# endif

# include "libft.h"
# include "libftprintf.h"
# include "gnl.h"

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

typedef struct s_cube
{
	int		fd;
	char	**file;
}	t_cube;


t_bool	parse_cub(char *file, t_cube *root_nd);
int		file_err(char *name_file, t_cube *root_nd);
t_bool	extension(char *file, char *flag, t_cube *root_nd);
t_bool	check_cub_extension(char *file, t_cube *root_nd);
t_bool	check_xpm_extension(char *file, t_cube *root_nd);
t_bool	content_is_valid(t_cube *root_nd);
t_bool	textures_are_valid(t_cube *root_nd);
void	clean_data_cube(t_cube *root_nd);

#endif

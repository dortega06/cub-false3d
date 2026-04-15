/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 14:22:28 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/04/15 18:37:05 by mcuenca-         ###   ########.fr       */
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
# include "mlx.h"
# include "mlx_int.h"
# include <stdint.h>

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

typedef	enum e_textu
{
	NO = 0,
	SO,
	WE,
	EA
}	t_textu;

typedef	enum e_floor_cealing
{
	F = 0,
	C
}	t_floor_cealing;

typedef	enum e_ff
{
	SPC = -1,
	FLOOR = 0,
	WALL = 1
}	t_ff;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_vex
{
	char	type;
	int		x;
	int		y;
}	t_vex;

typedef struct s_cube
{
	int			fd;
	char		**file;
	char		**map;
	void		*sys;
	int			width;
	int			height;
	t_img		textu[4];
	uint32_t	f;
	uint32_t	c;
	t_vex		rsp;
}	t_cube;


t_bool	parse_cub(char *file, t_cube *root_nd);
int		file_err(char *name_file, t_cube *root_nd);
t_bool	check_mng(char *file, char *flag, t_cube *root_nd);
char	**split_gnl_cube(char const *s, char c);
t_bool	check_cub(char *file, t_cube *root_nd);
t_bool	check_xpm(char *file, t_cube *root_nd);
t_bool	content_is_valid(t_cube *root_nd);
t_bool	textures_are_valid(t_cube *root_nd);
void	textures_to_image(t_cube *root_nd, char **textu_lines);
t_bool	colors_are_valid(t_cube *root_nd);
t_bool	map_is_valid(t_cube *root_nd);
t_vex	rsp(const char **map, t_vex *rsp);
t_bool	only_one_rsp(char **map, t_vex *rsp);
//t_ff	floodfill(char **map, char rsp, int x, int y);
t_ff	floodfill(int x, int y, t_cube *root_nd, char **visited);
void	clean_data_cube(t_cube *root_nd);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 14:22:28 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/05/13 14:24:49 by dortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

/********************************[ libs ]**************************************/
# include "libft.h"
# include "libftprintf.h"
# include "gnl.h"
# include "mlx.h"
# include "mlx_int.h"

# include <stdint.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <math.h>
# include <string.h>

/********************************[ macros ]************************************/

# define PI 	3.1415926535
# define BLOCK  64
# define CEILING_COLOR 0xADD8E6
# define FLOOR_COLOR 0xFFFDD0

/*******************************[ enums ]************************************/

typedef enum e_wid_hei
{
	WIDTH = 1280,
	HEIGHT = 720
}	t_wid_hei;

typedef enum e_ri_le
{
	RIGHT = 65363,
	LEFT = 65361
}	t_ri_le;

typedef enum e_textu
{
	NO = 0,
	SO,
	WE,
	EA
}	t_textu;

typedef enum e_floor_cealing
{
	F = 0,
	C
}	t_floor_cealing;

typedef enum e_xyz
{
	X = 0,
	Y = 1,
	Z = 2
}	t_xyz;

typedef enum e_ff
{
	SPC = -1,
	FLOOR = 0,
	WALL = 1
}	t_ff;

typedef enum e_key
{
	A = 97,
	W = 119,
	S = 115,
	D = 100,
	ESC = 65307
}	t_key;

/*******************************[ structs ]************************************/

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_vex
{
	char	type;
	int		color;
	int		x;
	int		y;
}	t_vex;

typedef struct s_image
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}	t_image;

typedef struct s_cube
{
	int			fd;
	char		**file;
	char		**map;
	char		**textu_path;
	uint32_t	f;
	uint32_t	c;
	t_vex		rsp;
}	t_cube;

// paths de las texturas
/*typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
}	t_textures;*/

typedef struct s_draw_line
{
	float	start_x;
	int		start_y;
	int		end_y;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	double	delta_x;
	double	delta_y;
	int		step_x;
	int		step_y;
	double	side_x;
	double	side_y;
	int		side;
	int		hit;
	double	perp_dist;
	int		height;
	double	wall_x;
	t_image	*tex;
}	t_draw_line;

typedef struct s_move_update
{
	double	speed;
	double	angle_speed;
	double	cos_angle;
	double	sin_angle;
	float	new_x;
	float	new_y;
}	t_move_update;

typedef struct s_player
{
	float	x;
	float	y;
	float	angle;

	bool	key_up;
	bool	key_down;
	bool	key_left;
	bool	key_right;

	bool	left_rotate;
	bool	right_rotate;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*wnd;
	void		*img;

	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	t_player	player;

	t_cube		*parse;
	char		**map;
	int			map_height;

	int			last_facing;

	//t_textures	textures;
	t_image		*texture_imgs;
	int			textures_loaded;

	uint32_t	color[2];
}	t_game;

/********************************[ parser ft ]*********************************/
t_bool	parse_cub(char *file, t_cube *root_nd);
int		file_err(char *name_file, t_cube *root_nd);
t_bool	check_mng(char *file, char *flag, t_cube *root_nd);
char	**split_gnl_cube(char const *s, char c);
t_bool	check_cub(char *file, t_cube *root_nd);
t_bool	check_xpm(char *file, t_cube *root_nd);
t_bool	content_is_valid(t_cube *root_nd);
t_bool	textures_are_valid(t_cube *root_nd, int *j);
char	**extract_lines(t_cube *root_nd, int len, int *j);
t_bool	colors_are_valid(t_cube *root_nd, int *j);
t_bool	map_is_valid(t_cube *root_nd, int *j);
t_vex	rsp(const char **map, t_vex *rsp);
t_bool	only_one_rsp(char **map, t_vex *rsp);
t_ff	floodfill(int x, int y, t_cube *root_nd, char **visited);
void	clean_data_cube(t_cube *root_nd);

/********************************[ excute ft ]*********************************/
int		execute(t_cube *parse);
void	init_player(t_player *player, t_vex *rsp);
int		key_realese(int keycode, t_game *game);
int		key_press(int keycode, t_game *game);
void	move_player(t_game *game);//(t_player *player);
//double	distance(double dx, double dy);
void	clear_img(t_game *game);
/*bool	touch(double px, double py, t_game *game);
double	fixed_distance(double x1, double y1,
			double x2, double y2, t_game *game);*/
int		close_game(t_game *game);

/**********************************[ render ]**********************************/
int		draw_loop(t_game *game);
//void	draw_map(t_game *game);
//void	draw_square(int x, int y, int size, int color, t_game *game);
void	put_pixel(int x, int y, int color, t_game *game);
void	draw_line(t_player *player, t_game *game, float start_x, int i);
void	draw_ceiling_and_floor(t_game *game);

/*********************************[ textures ]*********************************/
void	init_textures(t_game *game);
int		load_texture(t_game *game, int index, char *path);
int		get_texture_color(t_image *texture, int x, int y);
void	free_textures(t_game *game);
int		clamp_coord(int coord, int max);

/*****************************[ calculate_texture ]****************************/
int		get_texture_x(double ray_x, double ray_y,
			int texture_width, int facing);
int		get_texture_y(int screen_y, int wall_height, int texture_height);
//t_image	*get_wall_texture(t_game *game);

void	raycast(t_game *game, t_draw_line *draw);
void	raycast_colision(t_game *game, t_draw_line *draw);
void	raycast_which_wall(t_game *game, t_draw_line *draw);
int		draw_loop(t_game *game);
void	move_player(t_game *game);
bool	collision(char **map, float new_x, float new_y);
void	draw_line(t_player *player, t_game *game, float start_x, int i);
#endif

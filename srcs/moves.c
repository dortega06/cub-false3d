/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 12:43:26 by dortega-          #+#    #+#             */
/*   Updated: 2026/05/12 16:41:57 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/*
//	Calcula la distancia euclidiana entre dos puntos dados sus desplazamientos
	en X e Y.
//
//	@param	dx		Diferencia en X.
//	@param	dy		Diferencia en Y.
//	@return			Distancia entre los dos puntos.
*/
/*double	distance(double dx, double dy)// CReo que no se usa ya
{
	return (sqrtf(dx * dx + dy * dy));
}*/

/*
//	Inicializa la estructura del jugador con las posiciones, ángulo y estados de
	teclas a valores por defecto.
//
//	@param	player	Puntero a la estructura del jugador a inicializar.
//	@return			N/A
*/
void	init_player(t_player *player, t_vex *rsp)
{
	/*Convertir posición del mapa (celdas) a coordenadas del mundo (píxeles).*/
	player->x = (rsp->x + 0.5) * BLOCK;
	player->y = (rsp->y + 0.5) * BLOCK;
	/*Establecer ángulo según orientación del jugador en el mapa.*/
	if (rsp->type == 'N')
		player->angle = 3 * PI / 2;
	else if (rsp->type == 'S')
		player->angle = PI / 2;
	else if (rsp->type == 'E')
		player->angle = 0;
	else if (rsp->type == 'W')
		player->angle = PI;
	player->key_up = false;
	player->key_down = false;
	player->key_left = false;
	player->key_right = false;
	player->left_rotate = false;
	player->right_rotate = false;
}

/*
//	Gestiona el evento de liberación de una tecla, poniendo el estado
	correspondiente del jugador a falso.
//
//	@param	keycode	Código de la tecla liberada.
//	@param	game		Puntero a la estructura principal del juego.
//	@return			Siempre devuelve 0.
*/
int	key_realese(int keycode, t_game *game)
{
	t_player	*player;

	player = &game->player;
	if (keycode == W)
		player->key_up = false;
	if (keycode == S)
		player->key_down = false;
	if (keycode == A)
		player->key_left = false;
	if (keycode == D)
		player->key_right = false;
	if (keycode == LEFT)
		player->left_rotate = false;
	if (keycode == RIGHT)
		player->right_rotate = false;
	return (0);
}

/*
//	Gestiona el evento de pulsación de una tecla, poniendo el estado
	correspondiente del jugador a verdadero.
//	Si se pulsa ESC se cierra el juego.
//
//	@param	keycode	Código de la tecla presionada.
//	@param	game		Puntero a la estructura principal del juego.
//	@return			Siempre devuelve 0, salvo si se pulsa ESC donde se cierra
	el juego.
*/
int	key_press(int keycode, t_game *game)
{
	t_player	*player;

	player = &game->player;
	if (keycode == ESC)
		return (close_game(game));
	if (keycode == W)
		player->key_up = true;
	if (keycode == S)
		player->key_down = true;
	if (keycode == A)
		player->key_left = true;
	if (keycode == D)
		player->key_right = true;
	if (keycode == LEFT)
		player->left_rotate = true;
	if (keycode == RIGHT)
		player->right_rotate = true;
	return (0);
}

/*
//	Actualiza la posición y el ángulo del jugador según las teclas presionadas
	para movimiento y rotación.
*/

bool	collision(char **map, float new_x, float new_y)
{
	int	px;
	int	py;

	px = (int) new_x / BLOCK;
	py = (int) new_y / BLOCK;

	if (py < 0 || map[py] == NULL)
		return (true);
	if (px < 0 || px >= (int)ft_strlen(map[py]))
		return (true);

	if (map[py][px] == '1')
		return (true);
	return (false);
}

void	move_rotation(t_player *player, t_move_update *up_data)
{
	if (player->left_rotate)
		player->angle -= up_data->angle_speed;
	if (player->right_rotate)
		player->angle += up_data->angle_speed;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;
}

void	move_position_right_left(t_player *player, t_move_update *up_data)
{
	if (player->key_right)
	{
		up_data->new_x += cos(player->angle + PI / 2) * up_data->speed;
		up_data->new_y += sin(player->angle + PI / 2) * up_data->speed;
	}
	if (player->key_left)
	{
		up_data->new_x += cos(player->angle - PI / 2) * up_data->speed;
		up_data->new_y += sin(player->angle - PI / 2) * up_data->speed;
	}
}

void	move_position_up_down(t_player *player, t_move_update *up_data)
{
	if (player->key_up)
	{
		up_data->new_x += up_data->cos_angle * up_data->speed;
		up_data->new_y += up_data->sin_angle * up_data->speed;
	}
	if (player->key_down)
	{
		up_data->new_x -= up_data->cos_angle * up_data->speed;
		up_data->new_y -= up_data->sin_angle * up_data->speed;
	}
}

void	move_position(t_player *player, t_move_update *up_data, char **map)
{
	if (player->key_up || player->key_down)
		move_position_up_down(player, up_data);
	if (player->key_right || player->key_left)
		move_position_right_left(player, up_data);

	if (!collision(map, up_data->new_x, player->y))
		player->x = up_data->new_x;
	if (!collision(map, player->x, up_data->new_y))
		player->y = up_data->new_y;
}

void	move_player(t_game *game)
{
	t_move_update	up_data;
	t_player		*player;

	player = &game->player;
	up_data.speed = 2;
	up_data.angle_speed = 0.03;
	up_data.cos_angle = cos(player->angle);
	up_data.sin_angle = sin(player->angle);

	up_data.new_x = player->x;
	up_data.new_y = player->y;
	move_rotation(player, &up_data);
	move_position(player, &up_data, game->map);
}

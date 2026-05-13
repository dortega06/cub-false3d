/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 12:43:26 by dortega-          #+#    #+#             */
/*   Updated: 2026/05/13 15:10:22 by dortega-         ###   ########.fr       */
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
	player->x = (rsp->x + 0.5) * BLOCK;
	player->y = (rsp->y + 0.5) * BLOCK;
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
static bool	collision_point(char **map, float px, float py)
{
	int	x;
	int	y;

	x = (int)(px / BLOCK);
	y = (int)(py / BLOCK);
	if (py < 0 || map[y] == NULL)
		return (true);
	if (px < 0 || x >= (int)ft_strlen(map[y]))
		return (true);
	if (map[y][x] == '1')
		return (true);
	return (false);
}

bool	collision(char **map, float new_x, float new_y)
{
	float	margin = 2.0;

	if (collision_point(map, new_x - margin, new_y - margin))
		return (true);
	if (collision_point(map, new_x + margin, new_y - margin))
		return (true);
	if (collision_point(map, new_x - margin, new_y + margin))
		return (true);
	if (collision_point(map, new_x + margin, new_y + margin))
		return (true);
	return (false);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dortega- <dortega-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 12:43:26 by dortega-          #+#    #+#             */
/*   Updated: 2026/05/08 19:45:37 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
/*
//	Calcula la distancia euclidiana entre dos puntos dados sus desplazamientos en X e Y.
//
//	@param	dx		Diferencia en X.
//	@param	dy		Diferencia en Y.
//	@return			Distancia entre los dos puntos.

double	distance(double dx, double dy)// CReo que no se usa ya
{
	return (sqrtf(dx * dx + dy * dy));
}
*/

//	Inicializa la estructura del jugador con las posiciones, ángulo y estados de teclas a valores por defecto.
//
//	@param	player	Puntero a la estructura del jugador a inicializar.
//	@return			N/A
/*
void	init_player(t_player *player, t_vex *rsp)
{
	player->x = WIDTH / 2;
	player->y = HEIGHT / 2;
	player->angle = PI / 2;
	player->key_up = false;
	player->key_down = false;
	player->key_left = false;
	player->key_right = false;
	player->left_rotate = false;
	player->right_rotate = false;
}*/

// En moves.c
void init_player(t_player *player, t_vex *rsp)
{
    // Convertir posición del mapa (celdas) a coordenadas del mundo (píxeles)
    player->x = (rsp->x + 0.5) * BLOCK;
    player->y = (rsp->y + 0.5) * BLOCK;
    
    // Establecer ángulo según orientación del jugador en el mapa
    if (rsp->type == 'N')
        player->angle = 3 * PI / 2;  // Mirando al norte
    else if (rsp->type == 'S')
        player->angle = PI / 2;      // Mirando al sur
    else if (rsp->type == 'E')
        player->angle = 0;           // Mirando al este
    else if (rsp->type == 'W')
        player->angle = PI;          // Mirando al oeste
    
    player->key_up = false;
    player->key_down = false;
    player->key_left = false;
    player->key_right = false;
    player->left_rotate = false;
    player->right_rotate = false;
}


//	Gestiona el evento de liberación de una tecla, poniendo el estado correspondiente del jugador a falso.
//
//	@param	keycode	Código de la tecla liberada.
//	@param	game		Puntero a la estructura principal del juego.
//	@return			Siempre devuelve 0.

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


//	Gestiona el evento de pulsación de una tecla, poniendo el estado correspondiente del jugador a verdadero.
//	Si se pulsa ESC se cierra el juego.
//
//	@param	keycode	Código de la tecla presionada.
//	@param	game		Puntero a la estructura principal del juego.
//	@return			Siempre devuelve 0, salvo si se pulsa ESC donde se cierra el juego.

int	key_press(int keycode, t_game *game)
{
	t_player	*player = &game->player;

	if (keycode == ESC)
		return (close_game(game));
	if (keycode == W) player->key_up = true;
	if (keycode == S) player->key_down = true;
	if (keycode == A) player->key_left = true;
	if (keycode == D) player->key_right = true;
	if (keycode == LEFT) player->left_rotate = true;
	if (keycode == RIGHT) player->right_rotate = true;
	return (0);
}


//Actualiza la posición y el ángulo del jugador según las teclas presionadas para movimiento y rotación.

void	move_player(t_player *player)
{
	double	speed;
	double	angle_speed;
	double	cos_angle;
	double	sin_angle;

	speed = 2;
	angle_speed = 0.03;
	cos_angle = cos(player->angle);
	sin_angle = sin(player->angle);
	if (player->left_rotate)
		player->angle -= angle_speed;
	if (player->right_rotate)
		player->angle += angle_speed;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;
	if (player->key_up)
	{
		player->x += cos_angle * speed;
		player->y += sin_angle * speed;
	}
	if (player->key_down)
	{
		player->x -= cos_angle * speed;
		player->y -= sin_angle * speed;
	}
	if (player->key_right)
	{
		player->x += cos(player->angle + PI / 2) * speed;
		player->y += sin(player->angle + PI / 2) * speed;
	}
	if (player->key_left)
	{
		player->x += cos(player->angle - PI / 2) * speed;
		player->y += sin(player->angle - PI / 2) * speed;
	}
}

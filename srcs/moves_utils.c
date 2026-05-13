/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dortega- <dortega-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 14:15:40 by dortega-          #+#    #+#             */
/*   Updated: 2026/05/13 14:17:32 by dortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

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

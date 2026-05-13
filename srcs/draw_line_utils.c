/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dortega- <dortega-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 14:18:49 by dortega-          #+#    #+#             */
/*   Updated: 2026/05/13 14:20:04 by dortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	raycast_which_wall(t_game *game, t_draw_line *draw)
{
	if (draw->side == 0)
	{
		if (draw->step_x > 0)
			game->last_facing = 3;
		else
			game->last_facing = 2;
	}
	else
	{
		if (draw->step_y > 0)
			game->last_facing = 1;
		else
			game->last_facing = 0;
	}
}

void	raycast_colision(t_game *game, t_draw_line *draw)
{
	while (!draw->hit)
	{
		if (draw->side_x < draw->side_y)
		{
			draw->side_x += draw->delta_x;
			draw->map_x += draw->step_x;
			draw->side = 0;
		}
		else
		{
			draw->side_y += draw->delta_y;
			draw->map_y += draw->step_y;
			draw->side = 1;
		}
		if (draw->map_y >= 0 && draw->map_y < game->map_height
			&& game->map[draw->map_y] && draw->map_x >= 0
			&& draw->map_x < (int)ft_strlen(game->map[draw->map_y])
			&& game->map[draw->map_y][draw->map_x] == '1')
			draw->hit = 1;
	}
}

void	raycast(t_game *game, t_draw_line *draw)
{
	raycast_colision(game, draw);
	raycast_which_wall(game, draw);
}

void	wall_hit_x_pct(t_draw_line *draw)
{
	if (draw->side == 0)
		draw->wall_x = draw->pos_y + draw->perp_dist * draw->dir_y;
	else
		draw->wall_x = draw->pos_x + draw->perp_dist * draw->dir_x;
	draw->wall_x -= floor(draw->wall_x);
}

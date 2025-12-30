/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: your_login <your_login@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 00:00:00 by your_login        #+#    #+#             */
/*   Updated: 2025/12/30 00:00:00 by your_login       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	update_animation(t_game *game)
{
	game->frame_count++;
	if (game->frame_count >= 5000)
	{
		game->frame_count = 0;
		game->current_frame = (game->current_frame + 1) % ANIM_FRAMES;
		render_map(game);
	}
	if (game->frame_count % ENEMY_SPEED == 0)
	{
		move_enemies(game);
		if (check_enemy_collision(game))
		{
			ft_putstr_fd("💀 Game Over! Enemy caught you!\n", 1);
			close_game(game);
		}
		render_map(game);
	}
	return (0);
}

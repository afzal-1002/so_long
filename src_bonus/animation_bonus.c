/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 00:00:00 by your_login        #+#    #+#             */
/*   Updated: 2025/12/31 00:42:33 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	update_animation(t_game *game)
{
	static int	enemy_counter = 0;

	game->frame_count++;
	enemy_counter++;
	if (game->frame_count >= 5000)
	{
		game->frame_count = 0;
		game->current_frame = (game->current_frame + 1) % ANIM_FRAMES;
		render_map(game);
	}
	if (enemy_counter >= ENEMY_SPEED)
	{
		enemy_counter = 0;
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

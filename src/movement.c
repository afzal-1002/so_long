/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: your_login <your_login@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 00:00:00 by your_login        #+#    #+#             */
/*   Updated: 2025/12/30 00:00:00 by your_login       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_valid_move(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->map.width || y >= game->map.height)
		return (0);
	if (game->map.grid[y][x] == '1')
		return (0);
	if (game->map.grid[y][x] == 'E'
		&& game->map.collected != game->map.collectibles)
		return (0);
	return (1);
}

void	move_player(t_game *game, int new_x, int new_y)
{
	if (!is_valid_move(game, new_x, new_y))
		return ;
	if (game->map.grid[new_y][new_x] == 'C')
	{
		game->map.grid[new_y][new_x] = '0';
		game->map.collected++;
	}
	if (game->map.grid[new_y][new_x] == 'E'
		&& game->map.collected == game->map.collectibles)
	{
		game->player.moves++;
		print_moves(game->player.moves);
		ft_putstr_fd("🎉 Congratulations! You won!\n", 1);
		close_game(game);
		return ;
	}
	game->player.x = new_x;
	game->player.y = new_y;
	game->player.moves++;
	print_moves(game->player.moves);
	render_map(game);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		close_game(game);
	else if (keycode == W_KEY || keycode == UP_KEY)
		move_player(game, game->player.x, game->player.y - 1);
	else if (keycode == S_KEY || keycode == DOWN_KEY)
		move_player(game, game->player.x, game->player.y + 1);
	else if (keycode == A_KEY || keycode == LEFT_KEY)
		move_player(game, game->player.x - 1, game->player.y);
	else if (keycode == D_KEY || keycode == RIGHT_KEY)
		move_player(game, game->player.x + 1, game->player.y);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: your_login <your_login@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 00:00:00 by your_login        #+#    #+#             */
/*   Updated: 2025/12/30 00:00:00 by your_login       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	put_image(t_game *game, t_img img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img.img,
		x * TILE_SIZE, y * TILE_SIZE);
}

static void	render_enemies(t_game *game)
{
	t_enemy	*current;

	current = game->enemies;
	while (current)
	{
		put_image(game, game->enemy_img, current->x, current->y);
		current = current->next;
	}
}

void	render_tile(t_game *game, int x, int y)
{
	char	tile;

	tile = game->map.grid[y][x];
	put_image(game, game->floor, x, y);
	if (tile == '1')
		put_image(game, game->wall, x, y);
	else if (tile == 'C')
		put_image(game, game->collectible[game->current_frame], x, y);
	else if (tile == 'E')
		put_image(game, game->exit, x, y);
}

void	render_move_counter(t_game *game)
{
	char	*moves_str;
	char	*temp;

	moves_str = ft_strjoin("Moves: ", ft_itoa(game->player.moves));
	temp = moves_str;
	mlx_string_put(game->mlx, game->win, 10, 20, 0xFFFFFF, moves_str);
	free(temp);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			render_tile(game, x, y);
			x++;
		}
		y++;
	}
	render_enemies(game);
	put_image(game, game->player_img[game->current_frame],
		game->player.x, game->player.y);
	render_move_counter(game);
}

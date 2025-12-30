/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: your_login <your_login@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 00:00:00 by your_login        #+#    #+#             */
/*   Updated: 2025/12/30 00:00:00 by your_login       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_image(t_game *game, t_img img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img.img,
		x * TILE_SIZE, y * TILE_SIZE);
}

void	render_tile(t_game *game, int x, int y)
{
	char	tile;

	tile = game->map.grid[y][x];
	put_image(game, game->floor, x, y);
	if (tile == '1')
		put_image(game, game->wall, x, y);
	else if (tile == 'C')
		put_image(game, game->collectible, x, y);
	else if (tile == 'E')
		put_image(game, game->exit, x, y);
	if (x == game->player.x && y == game->player.y)
		put_image(game, game->player_img, x, y);
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
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 00:00:00 by mafzal            #+#    #+#             */
/*   Updated: 2026/01/01 20:57:30 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	init_map_data(t_game *game, char *map_file)
{
	ft_memset(game, 0, sizeof(t_game));
	game->map.exit_x = -1;
	game->map.exit_y = -1;
	game->map.grid = parse_map(map_file, game);
	if (!game->map.grid)
		return (0);
	find_player(game);
	count_collectibles(game);
	if (!validate_map(game))
	{
		free_map(game->map.grid);
		game->map.grid = NULL;
		return (0);
	}
	return (1);
}

int	init_graphics(t_game *game)
{
	if (!init_mlx(game))
	{
		free_map(game->map.grid);
		game->map.grid = NULL;
		return (0);
	}
	if (!load_textures(game))
	{
		free_map(game->map.grid);
		game->map.grid = NULL;
		return (0);
	}
	return (1);
}

int	init_game(t_game *game, char *map_file)
{
	if (!init_map_data(game, map_file))
		return (0);
	if (!init_graphics(game))
		return (0);
	game->frame_count = 0;
	game->current_frame = 0;
	return (1);
}

int	init_mlx(t_game *game)
{
	int	win_width;
	int	win_height;

	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	win_width = game->map.width * TILE_SIZE;
	win_height = game->map.height * TILE_SIZE;
	game->win = mlx_new_window(game->mlx, win_width, win_height,
			"so_long_bonus");
	if (!game->win)
		return (0);
	return (1);
}

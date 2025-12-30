/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: your_login <your_login@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 00:00:00 by your_login        #+#    #+#             */
/*   Updated: 2025/12/30 00:00:00 by your_login       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_game(t_game *game, char *map_file)
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
	if (!init_mlx(game))
	{
		ft_putstr_fd("Error\nFailed to initialize MLX\n", 2);
		free_map(game->map.grid);
		game->map.grid = NULL;
		return (0);
	}
	if (!load_textures(game))
	{
		ft_putstr_fd("Error\nFailed to load textures\n", 2);
		free_map(game->map.grid);
		game->map.grid = NULL;
		return (0);
	}
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
	game->win = mlx_new_window(game->mlx, win_width, win_height, "so_long");
	if (!game->win)
		return (0);
	return (1);
}

int	load_textures(t_game *game)
{
	game->wall.img = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &game->wall.width, &game->wall.height);
	game->floor.img = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &game->floor.width, &game->floor.height);
	game->collectible.img = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm",
			&game->collectible.width, &game->collectible.height);
	game->exit.img = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &game->exit.width, &game->exit.height);
	game->player_img.img = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm",
			&game->player_img.width, &game->player_img.height);
	if (!game->wall.img || !game->floor.img || !game->collectible.img
		|| !game->exit.img || !game->player_img.img)
		return (0);
	return (1);
}

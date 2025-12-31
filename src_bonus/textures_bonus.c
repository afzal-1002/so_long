/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 00:00:00 by mafzal            #+#    #+#             */
/*   Updated: 2025/12/31 01:05:03 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static int	load_player_textures(t_game *game)
{
	game->player_img[0].img = mlx_xpm_file_to_image(game->mlx,
			"Resources/right-1-40.xpm", &game->player_img[0].width,
			&game->player_img[0].height);
	game->player_img[1].img = mlx_xpm_file_to_image(game->mlx,
			"Resources/right-2-40.xpm", &game->player_img[1].width,
			&game->player_img[1].height);
	game->player_img[2].img = mlx_xpm_file_to_image(game->mlx,
			"Resources/left-1-40.xpm", &game->player_img[2].width,
			&game->player_img[2].height);
	game->player_img[3].img = mlx_xpm_file_to_image(game->mlx,
			"Resources/left-2-40.xpm", &game->player_img[3].width,
			&game->player_img[3].height);
	if (!game->player_img[0].img || !game->player_img[1].img
		|| !game->player_img[2].img || !game->player_img[3].img)
		return (0);
	return (1);
}

static int	load_collectible_textures(t_game *game)
{
	game->collectible[0].img = mlx_xpm_file_to_image(game->mlx,
			"Resources/Estrellita.xpm", &game->collectible[0].width,
			&game->collectible[0].height);
	game->collectible[1].img = mlx_xpm_file_to_image(game->mlx,
			"Resources/Estrellita.xpm", &game->collectible[1].width,
			&game->collectible[1].height);
	game->collectible[2].img = mlx_xpm_file_to_image(game->mlx,
			"Resources/Estrellita.xpm", &game->collectible[2].width,
			&game->collectible[2].height);
	game->collectible[3].img = mlx_xpm_file_to_image(game->mlx,
			"Resources/Estrellita.xpm", &game->collectible[3].width,
			&game->collectible[3].height);
	if (!game->collectible[0].img || !game->collectible[1].img
		|| !game->collectible[2].img || !game->collectible[3].img)
		return (0);
	return (1);
}

static int	load_exit_textures(t_game *game)
{
	game->exit_closed.img = mlx_xpm_file_to_image(game->mlx,
			"Resources/door.xpm", &game->exit_closed.width,
			&game->exit_closed.height);
	game->exit_open.img = mlx_xpm_file_to_image(game->mlx, "Resources/door.xpm",
			&game->exit_open.width, &game->exit_open.height);
	if (!game->exit_closed.img || !game->exit_open.img)
		return (0);
	return (1);
}

int	load_textures(t_game *game)
{
	game->wall.img = mlx_xpm_file_to_image(game->mlx, "Resources/wall.xpm",
			&game->wall.width, &game->wall.height);
	game->floor.img = mlx_xpm_file_to_image(game->mlx, "Resources/empty.xpm",
			&game->floor.width, &game->floor.height);
	game->enemy_img.img = mlx_xpm_file_to_image(game->mlx,
			"Resources/enemy.xpm", &game->enemy_img.width,
			&game->enemy_img.height);
	if (!game->wall.img || !game->floor.img || !game->enemy_img.img)
		return (0);
	if (!load_exit_textures(game))
		return (0);
	if (!load_player_textures(game))
		return (0);
	if (!load_collectible_textures(game))
		return (0);
	return (1);
}

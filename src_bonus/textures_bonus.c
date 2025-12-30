/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 00:00:00 by mafzal            #+#    #+#             */
/*   Updated: 2025/12/30 20:49:36 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static int	load_player_textures(t_game *game)
{
	game->player_img[0].img = mlx_xpm_file_to_image(game->mlx,
			"textures/player_0.xpm",
			&game->player_img[0].width, &game->player_img[0].height);
	game->player_img[1].img = mlx_xpm_file_to_image(game->mlx,
			"textures/player_1.xpm",
			&game->player_img[1].width, &game->player_img[1].height);
	game->player_img[2].img = mlx_xpm_file_to_image(game->mlx,
			"textures/player_2.xpm",
			&game->player_img[2].width, &game->player_img[2].height);
	game->player_img[3].img = mlx_xpm_file_to_image(game->mlx,
			"textures/player_3.xpm",
			&game->player_img[3].width, &game->player_img[3].height);
	if (!game->player_img[0].img || !game->player_img[1].img
		|| !game->player_img[2].img || !game->player_img[3].img)
		return (0);
	return (1);
}

static int	load_collectible_textures(t_game *game)
{
	game->collectible[0].img = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible_0.xpm",
			&game->collectible[0].width, &game->collectible[0].height);
	game->collectible[1].img = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible_1.xpm",
			&game->collectible[1].width, &game->collectible[1].height);
	game->collectible[2].img = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible_2.xpm",
			&game->collectible[2].width, &game->collectible[2].height);
	game->collectible[3].img = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible_3.xpm",
			&game->collectible[3].width, &game->collectible[3].height);
	if (!game->collectible[0].img || !game->collectible[1].img
		|| !game->collectible[2].img || !game->collectible[3].img)
		return (0);
	return (1);
}

int	load_textures(t_game *game)
{
	game->wall.img = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &game->wall.width, &game->wall.height);
	game->floor.img = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &game->floor.width, &game->floor.height);
	game->exit.img = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &game->exit.width, &game->exit.height);
	game->enemy_img.img = mlx_xpm_file_to_image(game->mlx,
			"textures/enemy.xpm",
			&game->enemy_img.width, &game->enemy_img.height);
	if (!game->wall.img || !game->floor.img
		|| !game->exit.img || !game->enemy_img.img)
		return (0);
	if (!load_player_textures(game))
		return (0);
	if (!load_collectible_textures(game))
		return (0);
	return (1);
}

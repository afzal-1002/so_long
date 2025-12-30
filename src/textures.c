/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 00:00:00 by mafzal            #+#    #+#             */
/*   Updated: 2025/12/30 23:26:03 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	load_basic_textures(t_game *game)
{
	game->wall.img = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&game->wall.width, &game->wall.height);
	if (!game->wall.img)
		return (0);
	game->floor.img = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			&game->floor.width, &game->floor.height);
	if (!game->floor.img)
		return (0);
	game->collectible.img = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &game->collectible.width,
			&game->collectible.height);
	if (!game->collectible.img)
		return (0);
	return (1);
}

static int	load_exit_textures(t_game *game)
{
	game->exit_closed.img = mlx_xpm_file_to_image(game->mlx,
			"textures/exit_closed.xpm", &game->exit_closed.width,
			&game->exit_closed.height);
	if (!game->exit_closed.img)
		return (0);
	game->exit_open.img = mlx_xpm_file_to_image(game->mlx,
			"textures/exit_open.xpm", &game->exit_open.width,
			&game->exit_open.height);
	if (!game->exit_open.img)
		return (0);
	return (1);
}

int	load_textures(t_game *game)
{
	if (!load_basic_textures(game))
		return (0);
	if (!load_exit_textures(game))
		return (0);
	game->player_img.img = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &game->player_img.width,
			&game->player_img.height);
	if (!game->player_img.img)
		return (0);
	return (1);
}

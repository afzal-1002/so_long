/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 00:00:00 by your_login        #+#    #+#             */
/*   Updated: 2025/12/30 23:23:52 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_enemies(t_enemy *enemies)
{
	t_enemy	*temp;

	while (enemies)
	{
		temp = enemies;
		enemies = enemies->next;
		free(temp);
	}
}

void	destroy_images(t_game *game)
{
	int	i;

	if (game->wall.img)
		mlx_destroy_image(game->mlx, game->wall.img);
	if (game->floor.img)
		mlx_destroy_image(game->mlx, game->floor.img);
	if (game->exit_closed.img)
		mlx_destroy_image(game->mlx, game->exit_closed.img);
	if (game->exit_open.img)
		mlx_destroy_image(game->mlx, game->exit_open.img);
	if (game->enemy_img.img)
		mlx_destroy_image(game->mlx, game->enemy_img.img);
	i = 0;
	while (i < ANIM_FRAMES)
	{
		if (game->collectible[i].img)
			mlx_destroy_image(game->mlx, game->collectible[i].img);
		if (game->player_img[i].img)
			mlx_destroy_image(game->mlx, game->player_img[i].img);
		i++;
	}
}

int	close_game(t_game *game)
{
	destroy_images(game);
	if (game->enemies)
		free_enemies(game->enemies);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->map.grid)
		free_map(game->map.grid);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
	return (0);
}

void	exit_error(char *message, t_game *game)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	if (game && game->map.grid)
		free_map(game->map.grid);
	if (game && game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(1);
}

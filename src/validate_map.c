/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: your_login <your_login@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 00:00:00 by your_login        #+#    #+#             */
/*   Updated: 2025/12/30 00:00:00 by your_login       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	validate_map(t_game *game)
{
	if (!check_rectangular(game))
	{
		ft_putstr_fd("Error\nMap is not rectangular\n", 2);
		return (0);
	}
	if (!check_walls(game))
	{
		ft_putstr_fd("Error\nMap is not surrounded by walls\n", 2);
		return (0);
	}
	if (!check_elements(game))
	{
		ft_putstr_fd("Error\nInvalid map elements\n", 2);
		return (0);
	}
	if (!check_path(game))
	{
		ft_putstr_fd("Error\nNo valid path in map\n", 2);
		return (0);
	}
	return (1);
}

int	check_rectangular(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(game->map.grid[0]);
	while (i < game->map.height)
	{
		if ((int)ft_strlen(game->map.grid[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	check_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.width)
	{
		if (game->map.grid[0][i] != '1'
			|| game->map.grid[game->map.height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->map.height)
	{
		if (game->map.grid[i][0] != '1'
			|| game->map.grid[i][game->map.width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_elements(t_game *game)
{
	int	i;
	int	j;
	int	player;
	int	exit;

	player = 0;
	exit = 0;
	game->map.collectibles = 0;
	i = -1;
	while (++i < game->map.height)
	{
		j = -1;
		while (++j < game->map.width)
		{
			if (game->map.grid[i][j] == 'P')
				player++;
			else if (game->map.grid[i][j] == 'E')
				exit++;
			else if (game->map.grid[i][j] == 'C')
				game->map.collectibles++;
			else if (game->map.grid[i][j] != '0'
				&& game->map.grid[i][j] != '1')
				return (0);
		}
	}
	if (player != 1 || exit != 1 || game->map.collectibles == 0)
		return (0);
	return (1);
}

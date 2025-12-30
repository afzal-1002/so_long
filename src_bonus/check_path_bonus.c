/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: your_login <your_login@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 00:00:00 by your_login        #+#    #+#             */
/*   Updated: 2025/12/30 00:00:00 by your_login       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	flood_fill(char **map, int x, int y, t_game *game)
{
	if (x < 0 || y < 0 || x >= game->map.width || y >= game->map.height)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'C')
		game->map.collected++;
	if (map[y][x] == 'E')
	{
		game->map.exit_x = x;
		game->map.exit_y = y;
	}
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, game);
	flood_fill(map, x - 1, y, game);
	flood_fill(map, x, y + 1, game);
	flood_fill(map, x, y - 1, game);
}

static char	**copy_map(t_game *game)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (game->map.height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < game->map.height)
	{
		copy[i] = ft_strdup(game->map.grid[i]);
		if (!copy[i])
		{
			while (i > 0)
				free(copy[--i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

int	check_path(t_game *game)
{
	char	**map_copy;
	int		result;

	game->map.collected = 0;
	map_copy = copy_map(game);
	if (!map_copy)
		return (0);
	flood_fill(map_copy, game->player.x, game->player.y, game);
	result = (game->map.collected == game->map.collectibles
			&& game->map.exit_x != -1);
	game->map.collected = 0;
	free_map(map_copy);
	return (result);
}

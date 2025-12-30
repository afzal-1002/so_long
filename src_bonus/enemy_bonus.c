/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: your_login <your_login@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 00:00:00 by your_login        #+#    #+#             */
/*   Updated: 2025/12/30 00:00:00 by your_login       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	add_enemy(t_game *game, int x, int y)
{
	t_enemy	*new;
	t_enemy	*temp;

	new = malloc(sizeof(t_enemy));
	if (!new)
		return ;
	new->x = x;
	new->y = y;
	new->dir = 1;
	new->next = NULL;
	if (!game->enemies)
		game->enemies = new;
	else
	{
		temp = game->enemies;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

void	init_enemies(t_game *game)
{
	int	i;
	int	j;

	game->enemies = NULL;
	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.grid[i][j] == 'N')
			{
				add_enemy(game, j, i);
				game->map.grid[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}

static void	move_enemy(t_game *game, t_enemy *enemy)
{
	int	new_x;

	new_x = enemy->x + enemy->dir;
	if (new_x < 0 || new_x >= game->map.width
		|| game->map.grid[enemy->y][new_x] == '1'
		|| game->map.grid[enemy->y][new_x] == 'E'
		|| game->map.grid[enemy->y][new_x] == 'C')
		enemy->dir *= -1;
	else
		enemy->x = new_x;
}

void	move_enemies(t_game *game)
{
	t_enemy	*current;

	current = game->enemies;
	while (current)
	{
		move_enemy(game, current);
		current = current->next;
	}
}

int	check_enemy_collision(t_game *game)
{
	t_enemy	*current;

	current = game->enemies;
	while (current)
	{
		if (current->x == game->player.x && current->y == game->player.y)
			return (1);
		current = current->next;
	}
	return (0);
}

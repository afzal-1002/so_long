/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: your_login <your_login@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 00:00:00 by your_login        #+#    #+#             */
/*   Updated: 2025/12/30 00:00:00 by your_login       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nUsage: ./so_long_bonus <map.ber>\n", 2);
		return (1);
	}
	if (!is_ber_file(argv[1]))
	{
		ft_putstr_fd("Error\nMap file must have .ber extension\n", 2);
		return (1);
	}
	if (!init_game(&game, argv[1]))
	{
		exit_error("Failed to initialize game", &game);
		return (1);
	}
	init_enemies(&game);
	render_map(&game);
	mlx_key_hook(game.win, key_press, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop_hook(game.mlx, update_animation, &game);
	mlx_loop(game.mlx);
	return (0);
}

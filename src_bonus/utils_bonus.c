/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 00:00:00 by your_login        #+#    #+#             */
/*   Updated: 2025/12/31 01:29:33 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	print_moves(int moves)
{
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(moves, 1);
	ft_putstr_fd("\n", 1);
}

int	is_ber_file(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	if (ft_strncmp(&filename[len - 4], ".ber", 4) != 0)
		return (0);
	return (1);
}

int	expose_handler(t_game *game)
{
	render_map(game);
	return (0);
}

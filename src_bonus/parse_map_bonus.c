/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: your_login <your_login@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 00:00:00 by your_login        #+#    #+#             */
/*   Updated: 2025/12/30 00:00:00 by your_login       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static char	*read_file(int fd)
{
	char	*line;
	char	*temp;
	char	*content;

	content = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = content;
		content = ft_strjoin(content, line);
		free(temp);
		free(line);
	}
	return (content);
}

char	**parse_map(char *filename, t_game *game)
{
	int		fd;
	char	*content;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nCannot open map file\n", 2);
		return (NULL);
	}
	content = read_file(fd);
	close(fd);
	if (!content || !*content)
	{
		ft_putstr_fd("Error\nEmpty map file\n", 2);
		free(content);
		return (NULL);
	}
	map = ft_split(content, '\n');
	free(content);
	if (!map)
		return (NULL);
	game->map.height = 0;
	while (map[game->map.height])
		game->map.height++;
	game->map.width = ft_strlen(map[0]);
	return (map);
}

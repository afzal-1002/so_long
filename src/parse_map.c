/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 00:00:00 by mafzal            #+#    #+#             */
/*   Updated: 2025/12/30 22:51:28 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	*read_file_content(int fd)
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

static char	**process_content(char *content, t_game *game)
{
	char	**map;

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

char	**parse_map(char *filename, t_game *game)
{
	int		fd;
	char	*content;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nCannot open map file\n", 2);
		return (NULL);
	}
	content = read_file_content(fd);
	close(fd);
	if (!content || !*content)
	{
		ft_putstr_fd("Error\nEmpty map file\n", 2);
		free(content);
		return (NULL);
	}
	return (process_content(content, game));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 00:00:00 by mafzal            #+#    #+#             */
/*   Updated: 2025/12/30 22:53:28 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strchr_gnl(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

static char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (NULL);
	i = -1;
	while (s1[++i])
		result[i] = s1[i];
	j = 0;
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}

static char	*extract_line(char **buffer, char *newline_pos)
{
	char	*line;
	char	*temp;
	int		len;

	len = newline_pos - *buffer + 1;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	ft_memset(line, 0, len + 1);
	while (len-- > 0)
		line[newline_pos - *buffer - len] = (*buffer)[newline_pos - *buffer
			- len];
	temp = ft_strdup(newline_pos + 1);
	free(*buffer);
	*buffer = temp;
	return (line);
}

static char	*handle_eof(char **buffer)
{
	char	*line;

	if (*buffer && **buffer)
	{
		line = ft_strdup(*buffer);
		free(*buffer);
		*buffer = NULL;
		return (line);
	}
	free(*buffer);
	*buffer = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		read_buf[BUFFER_SIZE + 1];
	char		*temp;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (ft_strchr_gnl(buffer, '\n'))
			return (extract_line(&buffer, ft_strchr_gnl(buffer, '\n')));
		bytes = read(fd, read_buf, BUFFER_SIZE);
		if (bytes <= 0)
			return (handle_eof(&buffer));
		read_buf[bytes] = '\0';
		temp = gnl_strjoin(buffer, read_buf);
		free(buffer);
		buffer = temp;
		if (!buffer)
			return (NULL);
	}
}

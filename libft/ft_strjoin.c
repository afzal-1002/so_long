/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 00:00:00 by mafzal            #+#    #+#             */
/*   Updated: 2025/12/30 22:53:29 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_str(char *dest, const char *src, size_t *pos)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[*pos] = src[i];
		(*pos)++;
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len;
	size_t	pos;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	pos = 0;
	copy_str(result, s1, &pos);
	copy_str(result, s2, &pos);
	result[pos] = '\0';
	return (result);
}

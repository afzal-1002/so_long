/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 00:00:00 by mafzal            #+#    #+#             */
/*   Updated: 2025/12/30 20:40:44 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* String functions */
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);

/* Memory functions */
void	*ft_memset(void *b, int c, size_t len);

/* Output functions */
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/* Conversion functions */
char	*ft_itoa(int n);

/* Get Next Line */
char	*get_next_line(int fd);

#endif
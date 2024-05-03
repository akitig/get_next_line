/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akunimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:54:04 by akunimot          #+#    #+#             */
/*   Updated: 2024/05/03 19:19:23 by akunimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
//# include <stdlib.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_buffer
{
	int		fd;
	int		fds[FOPEN_MAX];
	char	bufs[FOPEN_MAX];
}			t_buffer;

// gnl
char		*get_next_line(int fd);

// utils
size_t		ft_strlen(const char *str);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strchr(const char *s, int c);
char		*ft_gnl_strjoin(char const *s1, char const *s2);

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);

#endif
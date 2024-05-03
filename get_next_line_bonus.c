/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akunimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:55:46 by akunimot          #+#    #+#             */
/*   Updated: 2024/05/03 19:55:16 by akunimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*bond_buffer(char *save_buffer, char *read_buffer)
{
	char	*join_buffer;

	join_buffer = ft_gnl_strjoin(save_buffer, read_buffer);
	if (!join_buffer)
		return (NULL);
	if (save_buffer)
		free(save_buffer);
	return (join_buffer);
}

void	make_next_buffer_from_file(int fd, char **buffer)
{
	ssize_t	read_byte;
	char	*read_buffer;

	if (!*buffer)
		*buffer = ft_calloc(1, 1);
	read_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!read_buffer)
	{
		free(*buffer);
		*buffer = NULL;
		return ;
	}
	read_byte = read(fd, read_buffer, BUFFER_SIZE);
	while (read_byte > 0)
	{
		read_buffer[read_byte] = '\0';
		*buffer = bond_buffer(*buffer, read_buffer);
		if (ft_strchr(read_buffer, '\n'))
			break ;
		read_byte = read(fd, read_buffer, BUFFER_SIZE);
	}
	free(read_buffer);
}

char	*make_new_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
	{
		// free(buffer);
		return (NULL);
	}
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*save_buffer_for_next(char *buffer)
{
	int		i;
	int		next_i;
	char	*next_buffer;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	next_buffer = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	next_i = 0;
	i++;
	while (buffer[i])
		next_buffer[next_i++] = buffer[i++];
	free(buffer);
	return (next_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buf[FOPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd >= FOPEN_MAX)
	{
		if ((fd < 0 || fd >= FOPEN_MAX) && buf[fd])
		{
			free(buf[fd]);
			// buf[fd] = NULL;
		}
		return (NULL);
	}
	make_next_buffer_from_file(fd, &buf[fd]);
	if (!buf[fd])
		return (NULL);
	line = make_new_line(buf[fd]);
	buf[fd] = save_buffer_for_next(buf[fd]);
	if (!line && buf[fd])
		free(buf[fd]);
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:05:51 by rrasezin          #+#    #+#             */
/*   Updated: 2023/01/29 16:17:44 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

static char	*new_line(char	*line)
{
	char	*new;
	int		i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] && line[i] == '\n')
		i++;
	new = ft_calloc_g((i + 1), sizeof(char));
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		new[i] = line[i];
		i++;
	}
	if (line[i] && line[i] == '\n')
		new[i++] = ' ';
	if (*new == '\0')
	{
		free (new);
		return (NULL);
	}
	return (new);
}

static char	*save(char *buffer)
{
	char	*rest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free (buffer);
		return (NULL);
	}
	if (buffer[i] && buffer[i] == '\n')
		i++;
	rest = ft_calloc_g(ft_strlen_g(buffer) - i + 1, sizeof(char));
	while (buffer[i] && buffer[i] != '\0')
		rest[j++] = buffer[i++];
	free (buffer);
	return (rest);
}

char	*get_next_line(int fd, int buffer_size)
{
	static char	*line;
	char		*buffer;
	int			read_size;

	read_size = 1;
	if (fd == -1 || fd == 1 || fd == 2 || buffer_size <= 0)
		return (NULL);
	if (!line)
		line = ft_calloc_g(1, 1);
	buffer = ft_calloc_g(buffer_size + 1, sizeof(char));
	while (!(ft_strchr_g(buffer, '\n')) && read_size != 0)
	{
		read_size = read(fd, buffer, buffer_size);
		if (read_size <= 0)
			break ;
		buffer[read_size] = '\0';
		line = ft_strjoin_g(line, buffer);
	}
	free (buffer);
	buffer = new_line(line);
	line = save(line);
	return (buffer);
}

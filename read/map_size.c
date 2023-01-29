/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:11:46 by rrasezin          #+#    #+#             */
/*   Updated: 2023/01/29 15:12:52 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static	int	word_count(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s[i] != '\0' && s[i] != c)
		count = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			if (s[i] != '\0')
				count++;
		}
		if (s[i] != '\0')
			i++;
	}
	return (count);
}

void	map_size(char *titel, int *y, int *x)
{
	int		fd;
	char	*line;
	int		m;

	fd = open(titel, O_RDONLY);
	line = get_next_line(fd, 1);
	(*x) = word_count(line, ' ');
	m = (*x);
	while (line != NULL)
	{
		(*y)++;
		if (line)
			free(line);
		line = get_next_line(fd, 100);
		if (line && m != word_count(line, ' '))
		{
			write (1, "Found wrong line length.\n", 25);
			free(line);
			exit(0);
		}
	}
	close (fd);
}

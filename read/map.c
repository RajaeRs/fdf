/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:54:36 by rrasezin          #+#    #+#             */
/*   Updated: 2023/01/28 19:49:39 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdio.h>

t_map	*map_line(char *line, int y, int col_nb)
{
	char			**data;
	char			*color;
	t_map			*map;
	int				x;

	x = 0;
	data = ft_split(line, ' ');
	map = (t_map *)malloc(col_nb * sizeof(t_map));
	while (x < col_nb)
	{
		map[x].x = x;
		map[x].y = y;
		map[x].z = ft_atoi(data[x]);
		color = ft_strnstr(data[x], "0x", 10);
		if (color == NULL && map[x].z >= 2 && map[x].z <= 5)
			map[x].c = 0xFC5F6A;
		else if (color == NULL && map[x].z >= 5)
			map[x].c = 0x820202;
		else
			map[x].c = hex_to_int(color);
		free(data[x++]);
	}
	free(data);
	return (map);
}

t_map	**read_map(char *titel, int line_nb, int col_nb)
{
	t_map	**map;
	char	*line;
	int		fd;
	int		y;

	fd = open(titel, O_RDONLY);
	y = 0;
	map = (t_map **)ft_calloc((line_nb), sizeof(t_map *));
	while (y < line_nb)
	{
		line = get_next_line(fd, 100);
		map[y] = map_line(line, y, col_nb);
		y++;
	}
	close(fd);
	return (map);
}

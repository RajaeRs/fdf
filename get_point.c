/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:56:02 by rrasezin          #+#    #+#             */
/*   Updated: 2022/12/18 17:15:50 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

l_point	*new_point(int x, int y, int z, int color)
{
	l_point	*map_point;

	map_point = malloc(sizeof(l_point));
	if (!map_point)
		return (NULL);
	map_point -> x_map = x;
	map_point -> y_map = y;
	map_point -> z_map = z;
	map_point -> color = color;
	map_point -> next_point = NULL;
	map_point -> bottom_point = NULL;
	return (map_point);
}
static int hex_to_int(const char *hex_str)
{
	int	color;
	int	tmp;
	int	size;
	
	color = 0;
	if (hex_str == NULL)
		return (65535);
	else
	{
		hex_str = hex_str + 2;
		size = ft_strlen(hex_str) - 1;
		while(*hex_str)
		{
			if ((int)*hex_str >= 'A' && (int)*hex_str <= 'F')
				tmp = (int)(*hex_str) - 'A' + 10;
			else 
				tmp = (int)(*hex_str) - '0';
			color = color + tmp*(int)(pow((double)16,(double)size));
			size--;
			hex_str++;
		}
	}
	return (color);
}

// i pass the variabl save as argument just because i cant declar mor than 5 variabls;
l_point	*get_point(char *map_id, int y, int x, int save, int BUFFER_SIZE)
{
	l_point	*point;
	l_point	*next_point;
	l_point	*bottom_point;
	char	**line;
	int		fd;
	
	save = y+1;
	fd = open(map_id, O_RDONLY);
	while (save > 0)
	{
		line = ft_split(get_next_line(fd, BUFFER_SIZE), ' ');
		save--;
	}
	point = new_point(x, y, ft_atoi(line[x]), hex_to_int(ft_strnstr(line[x], "0x", 6)));
	if (line[x+1] != '\0')
	{
		next_point = new_point(x+1, y, ft_atoi(line[x+1]), hex_to_int(ft_strnstr(line[x+1], "0x", 6)));
		add_next_point(&point, next_point);
	}
	line = ft_split(get_next_line(fd, BUFFER_SIZE), ' ');
	if (line != NULL)
	{
		bottom_point = new_point(x, y+1, ft_atoi(line[x]), hex_to_int(ft_strnstr(line[x], "0x", 6)));
		add_bottom_point(&point, bottom_point);
	}
	free (line);
	close(fd);
	return (point);
}
// int	main()
// {
// 	l_point *line;
// 	int		save;

// 	save = 1;
// 	line = get_point("test_maps/elem-col.fdf", 4, 8, save);
// 	printf ("x_map : %f\ny_map : %f\nz_map : %d\ncolor : %d\nnext_point : %p\nbottom_point : %p\n", line->x_map, line->y_map, line->z_map, line->color, line->next_point, line->bottom_point);
// 	line = line ->bottom_point;
// 	printf ("x_map : %f\ny_map : %f\nz_map : %d\ncolor : %d\nnext_point : %p\nbottom_point : %p\n", line->x_map, line->y_map, line->z_map, line->color, line->next_point, line->bottom_point);

// }

// to compile 
// gcc get_point.c ft_split/ft_split.c ft_split/ft_bzero.c ft_split/ft_calloc.c ft_split/ft_strlen.c ft_split/ft_substr.c add_next_point.c ft_atoi.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c add_bottom_point.c
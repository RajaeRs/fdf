/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:56:02 by rrasezin          #+#    #+#             */
/*   Updated: 2022/12/31 03:23:41 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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
		return (16764464);
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

l_point	*point_data(char **line, int x, int y)
{
	l_point *point;
	int		z;
	int		color;

	z = ft_atoi(line[x]);
	color = hex_to_int(ft_strnstr(line[x], "0x", 6));
	point = new_point(x, y, z, color);
	return (point);
}

void	free_line(char **line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		free(line[i]);
		i++;
	}
	free(line);
}
l_point	*get_point(int fd, int y, int x)
{
	l_point	*point;
	char	*map;
	static char	**line;
	static char **next_line;

	if (x == 0)
	{
		if (y == 0)
		{
			map = get_next_line(fd, 6000);
			line = ft_split(map, ' ');
			free (map);
		}
		else
			line = next_line;
	}
	point = point_data(line, x, y);
	if (line[x+1] != '\0' )
		add_next_point(point, point_data(line, x+1, y));
	if (x == 0)
	{
		map = get_next_line(fd, 6000);
		next_line = ft_split(map, ' ');
		free (map);
	}
	if (next_line != NULL)
		add_bottom_point(point, point_data(next_line, x, y+1));
	if (line[x+1] == '\0')
		free_line(line);
	return (point);
}
// int	main()
// { 
// 	l_point *line;
// 	// int		save;
// 	int fd = open("test_maps/julia.fdf", O_RDONLY);
// 	int x;
// 	int y;
// 	y = 0;
// 	x = 0;
// 	int yy = get_line_number("test_maps/julia.fdf");
// 	int xx = get_colomn_number("test_maps/julia.fdf");

// 	while (y < yy)
// 	{
// 		while (x < xx)
// 		{
// 			line = get_point(fd, y , x, 19);
// 			printf("%d ", line->color);
// 			//printf("%d\n",x);
// 			// printf ("x_map : %d, y_map : %d, z_map : %d, color : %d, next_point : %p, bottom_point : %p\n", line->x_map, line->y_map, line->z_map, line->color, line->next_point, line->bottom_point);
// 			x++;
// 		}
// 		printf("\n");
// 		x = 0;
// 		y++;
// 	}

// }

// to compile 
// gcc get_point.c ft_split/ft_split.c ft_split/ft_bzero.c ft_split/ft_calloc.c ft_split/ft_strlen.c ft_split/ft_substr.c add_next_point.c ft_atoi.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c add_bottom_point.c
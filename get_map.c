/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:56:02 by rrasezin          #+#    #+#             */
/*   Updated: 2022/12/25 00:12:00 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

l_point	*new_point(int x, int y, int z, int color)
{
	l_point	*map_point;
	float	angle;

	angle = (38 * 3.14) / 180;
	map_point = malloc(sizeof(l_point));
	if (!map_point)
		return (NULL);
	map_point -> x_map = (x*15 - y*15)*cos(angle)+100;
	// map_point -> x_map = x*15;
	map_point -> y_map = (x*15 + y*15)*sin(angle) - z +50;
	// map_point -> y_map = y*15;
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
l_point	*get_point(int fd, int y, int x, int BUFFER_SIZE)
{
	l_point	*point;
	l_point	*next_point;
	l_point	*bottom_point;
	static char	**line;
	static char **next_line;

	if (x == 0)
	{
		if (y == 0)
			line = ft_split(get_next_line(fd, BUFFER_SIZE), ' ');
		else 
			line = next_line;
	}
	point = new_point(x, y, ft_atoi(line[x]), hex_to_int(ft_strnstr(line[x], "0x", 6)));
	if (line[x+1] != '\0')
		next_point = new_point(x+1, y, ft_atoi(line[x+1]), hex_to_int(ft_strnstr(line[x+1], "0x", 6)));
	if (line[x+1] != '\0')
		add_next_point(&point, next_point);
	if (x == 0)
		next_line = ft_split(get_next_line(fd, BUFFER_SIZE), ' ');
	if (next_line != NULL)
		bottom_point = new_point(x, y+1, ft_atoi(next_line[x]), hex_to_int(ft_strnstr(next_line[x], "0x", 6)));
	if (next_line != NULL)
		add_bottom_point(&point, bottom_point);
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
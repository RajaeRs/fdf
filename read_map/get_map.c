/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:56:02 by rrasezin          #+#    #+#             */
/*   Updated: 2023/01/02 10:01:54 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	poww(int num, int pow)
{
	int	tmp;

	tmp = num;
	if (pow == 0)
		return (1);
	while (pow - 1)
	{
		num = tmp * num;
		pow--;
	}
	return (num);
}

static int	hex_to_int(const char *hex_str)
{
	int	color;
	int	tmp;
	int	size;
	int	i;

	color = 0;
	i = 0;
	if (hex_str == NULL)
		return (16764464);
	hex_str = hex_str + 2;
	size = ft_strlen(hex_str) - 1;
	while (size + 1)
	{
		if (hex_str[size] >= 'a' && hex_str[size] <= 'f')
			tmp = hex_str[size] - 87;
		else if (hex_str[size] >= 'A' && hex_str[size] <= 'F')
			tmp = hex_str[size] - 55;
		else
			tmp = hex_str[size] - '0';
		color = color + tmp * poww(16, i);
		size--;
		i++;
	}
	return (color);
}

t_point	*point_data(char **line, int x, int y)
{
	t_point	*point;
	int		z;
	int		color;

	z = ft_atoi(line[x]);
	color = hex_to_int((ft_strnstr(line[x], "0x", 6)));
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

t_point	*get_point(int fd, int y, int x)
{
	t_point		*point;
	char		*map;
	static char	**line;
	static char	**next_line;

	if (y == 0 && x == 0)
	{
		map = get_next_line(fd, 6000);
		line = ft_split(map, ' ');
	}
	else if (x == 0)
			line = next_line;
	point = point_data(line, x, y);
	if (line[x + 1] != '\0' )
		add_next_point(point, point_data(line, x + 1, y));
	if (x == 0)
	{
		map = get_next_line(fd, 6000);
		next_line = ft_split(map, ' ');
	}
	if (next_line != NULL)
		add_bottom_point(point, point_data(next_line, x, y + 1));
	if (line[x + 1] == '\0')
		free_line(line);
	return (point);
}

// int	main(void)
// {
// 	char	*hex;

// 	hex = "FF5";
// 	printf("pow is : %d\n", poww(4, 1));
// 	printf("int : %d\n", hex_to_int(hex));
// }

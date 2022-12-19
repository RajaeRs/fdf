/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_point_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:53:59 by rrasezin          #+#    #+#             */
/*   Updated: 2022/12/18 17:36:49 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//------------ this function return all the map readed ----------
// char	**get_point_info(int fd, int line_number)
// {
// 	char	**map;
// 	int		y;
	
// 	map = malloc(line_number);
// 	y = 0;
// 	map[y] = get_next_line(fd);
// 	while (map[y])
// 	{
// 		y++;
// 		map[y] = get_next_line(fd);
// 	}
// 	return (map);
// }

//------------- the number of line -------------
int		get_line_number(char *map_id)
{
	int fd;
	int line_number;
	
	line_number = 0;
	fd = open(map_id, O_RDONLY);
	while (get_next_line(fd, 6000) != NULL)
		line_number++;
	close(fd);
	return(line_number);
}

// ----------- the number of column ---------------
int	get_colomn_number(char	*map_id)
{
	int		fd;
	int		colomn_number;
	char	*line;
	char	**colomn;

	colomn_number = 0;
	fd = open(map_id, O_RDONLY);
	line = get_next_line(fd, 1);
	close (fd);
	colomn = ft_split(line, ' ');
	while (*colomn)
	{
		colomn_number++;
		colomn++;
	}
	free (line);
	return (colomn_number);
}

// int	main()
// {
// 	char	**point_info;
// 	int		fd;
// 	int		line_number;
// 	int 	colomn_number;
// 	int 	i;
	
// 	i = 0;
// 	colomn_number = 0;
// 	line_number = get_colomn_number("test_maps/50-4.fdf");
// 	printf("number of line : %d\n", line_number);
// }
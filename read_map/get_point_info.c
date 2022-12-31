/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_point_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:53:59 by rrasezin          #+#    #+#             */
/*   Updated: 2022/12/31 02:54:35 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

//------------- the number of line -------------
int		get_line_number(char *map_id)
{
	int fd;
	int line_number;
	char *line;
	
	line_number = 0;
	fd = open(map_id, O_RDONLY);
	line = get_next_line(fd, 6000);
	while (line != NULL)
	{
		free (line);
		line_number++;
		line = get_next_line(fd, 6000);
	}
	// free (line);
	close(fd);
	return(line_number);
}

static	int	word_count(const char *s, char c)
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
// ----------- the number of column ---------------
int	get_colomn_number(char	*map_id)
{
	int		fd;
	int		colomn_number;
	char	*line;
	// char	**colomn;
	// int		i;

	colomn_number = 0;
	// i = 0;
	fd = open(map_id, O_RDONLY);
	line = get_next_line(fd, 1);
	close (fd);
	colomn_number = word_count(line, ' ');
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
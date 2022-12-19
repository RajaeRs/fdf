/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:53:41 by rrasezin          #+#    #+#             */
/*   Updated: 2022/12/19 17:44:19 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H 
# include "libft_utils/libft.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>

typedef struct	m_point{
    int				x_map;
    int				y_map;
	int 			z_map;
    int				color;
	struct	m_point	*next_point;
	struct	m_point	*bottom_point;
}				l_point;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

// typedef struct	d_mlx{
// 	void	*mlx_ptr;
// 	void	*mlx_win;
// 	t_data	mlx_img;
// 	int		x;
// 	int		y;
// }				l_mlx;

int		ft_atoi(const char *str);
l_point	*new_point(int x, int y, int z, int color);
void	add_next_point(l_point **point, l_point *new_point);
void	add_bottom_point(l_point **point, l_point *new_point);
l_point	*get_point(int fd, int y, int x, int BUFFER_SIZE);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int     get_line_number(char *map_id);
int	    get_colomn_number(char	*map_id);
l_point	*get_map(char *map_id, int y, int yy);

#endif

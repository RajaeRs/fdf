/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:53:41 by rrasezin          #+#    #+#             */
/*   Updated: 2022/12/31 03:53:53 by rrasezin         ###   ########.fr       */
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

typedef struct	s_mlx
{
    void    *mlx_ptr;
    void    *win;
    t_data	img;
	int		map_id;
	l_point	*point;
	l_point *n_point;
	int		yy;
	int		xx;
	int		x;
	int		y;
}    			t_mlx;

typedef struct	s_line
{
	float	dx;
	float	dy;
	float	x;
	float	y;
	float	step;
	int		i;
}				t_line;

int		ft_atoi(const char *str);
l_point	*new_point(int x, int y, int z, int color);
void	add_next_point(l_point *point, l_point *new_point);
void	add_bottom_point(l_point *point, l_point *new_point);
l_point	*get_point(int fd, int y, int x);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int     get_line_number(char *map_id);
int	    get_colomn_number(char	*map_id);
void	iso(l_point *p);
void    draw(t_data *data, l_point *p);

#endif

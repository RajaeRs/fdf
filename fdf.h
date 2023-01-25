/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:11:08 by rrasezin          #+#    #+#             */
/*   Updated: 2023/01/25 16:49:30 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIDTH 1000
# define HEIGHT 1000

# include "get_next_line/get_next_line.h"
# include "libft_utiles/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>

typedef struct s_map
{
	int	x;
	int	y;
	int	z;
	int	c;
}			t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_mouve
{
	int			x_scr;
	int			y_scr;
	int			zoom_in;
	int			zoom_out;
	float		xz;
	float		yz;
	float		up;
	float		m_left;
	float		m_up;
	float		angle;
	float		angleb;
}				t_mouve;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	t_data	i;
	t_map	**map;
	t_map	**map_i;
	t_mouve	m;
	int		p_type;
	int		colomn;
	int		line;
}				t_mlx;


typedef struct s_line
{
	float	dx;
	float	dy;
	float	x;
	float	y;
	float	step;
	int		i;
}				t_line;

typedef struct s_rgb
{
	float	r;
	float	g;
	float	b;
	int		rr;
	int		gg;
	int		bb;
	int		color;
}				t_rgb;

t_map	**read_map(char *titel, int line_nb, int col_nb);
int		hex_to_int(const char *hex_str);
void	map_size(char *titel, int *y, int *x);
void	iso(t_mlx *p);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	dda(t_mlx *mlx, t_map **map, int line, int colomn);
void	draw(char *titel);
int		key_control(int key, t_mlx *param);
int		clear(int key, t_mlx *d);
int		esc(int key, t_mlx *d);
t_map	**allocation(t_mlx *d);
void	projection(t_mlx *p, int p_type);
int    mouse_control(int key, int x, int y, t_mlx *p);
void	initialize(t_mlx *mouve);

#endif
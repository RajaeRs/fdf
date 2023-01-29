/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_type.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:46:51 by rrasezin          #+#    #+#             */
/*   Updated: 2023/01/29 14:33:48 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_TYPE_H
# define DATA_TYPE_H

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
	float	ang;
	int		zoom;
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

typedef struct s_rotat
{
	float	i;
	float	j;
	float	z;
	int		x;
	int		y;
	float	r_x;
	float	r_y;
	float	r_ang;
	float	i_ang;
}				t_rotat;
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:11:08 by rrasezin          #+#    #+#             */
/*   Updated: 2023/01/29 00:17:40 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define HEIGHT 1300
# define WIDTH 2000

# include "get_next_line/get_next_line.h"
# include "libft_utiles/libft.h"
# include "data_type.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>

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
int		mouse_control(int key, int x, int y, t_mlx *p);
void	initialize(t_mlx *mouve);
void	rotation(t_mlx *p);

#endif
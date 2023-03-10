/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:48:51 by rrasezin          #+#    #+#             */
/*   Updated: 2023/01/29 14:58:14 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	initialize(t_mlx *mouve)
{
	mouve->m.up = 1;
	mouve->m.m_left = 0;
	mouve->m.m_up = 0;
	mouve->m.xz = 1.8;
	mouve->m.yz = 1.8;
	if (mouve->p_type == 0)
		mouve->p_type = 34;
	mouve->m.x_scr = 0;
	mouve->m.y_scr = 0;
	mouve->m.zoom_in = HEIGHT / 3 - (int)(HEIGHT / 10) + 300;
	mouve->m.zoom_out = WIDTH / 2 - (int)(WIDTH / 6) + 250;
	mouve->ang = 0;
	mouve->zoom = 10;
}

t_map	**allocation(t_mlx *d)
{
	t_map	**map_i;
	int		i;

	i = 0;
	map_i = (t_map **)ft_calloc((d->line), sizeof(t_map *));
	while (i < d->line)
		map_i[i++] = (t_map *)malloc(d->colomn * sizeof(t_map));
	return (map_i);
}

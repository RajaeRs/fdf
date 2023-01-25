/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mondatory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:28:12 by rrasezin          #+#    #+#             */
/*   Updated: 2023/01/25 17:24:32 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw(char *titel)
{
	t_mlx	d;

	d.ptr = mlx_init();
	d.win = mlx_new_window(d.ptr, HEIGHT, WIDTH, titel);
	d.i.img = mlx_new_image(d.ptr, HEIGHT, WIDTH);
	d.i.addr = mlx_get_data_addr(d.i.img, &d.i.bits_per_pixel, &d.i.line_length,
			&d.i.endian);
	map_size(titel, &d.line, &d.colomn);
	d.map = read_map(titel, d.line, d.colomn);
	d.map_i = allocation(&d);
	initialize(&d);
	projection(&d,d.p_type);
	dda(&d, d.map_i, d.line, d.colomn);
	mlx_put_image_to_window(d.ptr, d.win, d.i.img, 0, 0);
	mlx_hook(d.win, 17, 0, clear, &d);
	mlx_key_hook(d.win, esc, &d);
	mlx_loop(d.ptr);
}

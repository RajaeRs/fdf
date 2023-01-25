/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:28:12 by rrasezin          #+#    #+#             */
/*   Updated: 2023/01/25 16:50:12 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw(char *titel)
{
	t_mlx	d;
	// t_mouve	m;
	d.ptr = mlx_init();
	d.win = mlx_new_window(d.ptr, HEIGHT, WIDTH, titel);
	d.i.img = mlx_new_image(d.ptr, HEIGHT*4, WIDTH*4);
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
	mlx_key_hook(d.win, key_control, &d);
	mlx_mouse_hook(d.win, mouse_control, &d);
	mlx_loop(d.ptr);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:28:12 by rrasezin          #+#    #+#             */
/*   Updated: 2023/01/28 17:45:08 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	fdf(t_mlx *p)
{
	char	*str;

	str = " *****  *****   *****";
	mlx_string_put(p->ptr, p->win, 20, 100, 0xCB1C1C, str);
	str = " *      *    *  *    ";
	mlx_string_put(p->ptr, p->win, 20, 110, 0xCF2D2D, str);
	str = " *****  *    *  *****";
	mlx_string_put(p->ptr, p->win, 20, 120, 0xD43F3F, str);
	str = " *      *    *  *    ";
	mlx_string_put(p->ptr, p->win, 20, 130, 0xD85050, str);
	str = " *      *****   *    ";
	mlx_string_put(p->ptr, p->win, 20, 140, 0xDC6262, str);
}

void	guide(t_mlx *p)
{
	mlx_string_put(p->ptr, p->win, 25, 200, 0xDB5C5C, "GUIDE TO USE :");
	mlx_string_put(p->ptr, p->win, 15, 250, 0xE17373, "o Altitud : + or -");
	mlx_string_put(p->ptr, p->win, 15, 280, 0xE58585, "o Rotation :");
	mlx_string_put(p->ptr, p->win, 25, 310, 0xE99696, "~ Axe Z : A & D");
	mlx_string_put(p->ptr, p->win, 15, 340, 0xEEA7A7, "o Shift : < v ^ >");
	mlx_string_put(p->ptr, p->win, 15, 370, 0xF2B9B9, "o Zoom : use the mouse");
	mlx_string_put(p->ptr, p->win, 15, 400, 0xF6CACA, "o Reset : R");
	mlx_string_put(p->ptr, p->win, 15, 430, 0xFBDCDC, "o Projection :");
	mlx_string_put(p->ptr, p->win, 25, 460, 0xFFEDED, "~ Oblique : O");
	mlx_string_put(p->ptr, p->win, 25, 490, 0xFFEEEE, "~ Isometric : I");
}

void	draw(char *titel)
{
	t_mlx	d;

	d.ptr = mlx_init();
	d.win = mlx_new_window(d.ptr, WIDTH, HEIGHT, titel);
	d.i.img = mlx_new_image(d.ptr, WIDTH, HEIGHT);
	d.i.addr = mlx_get_data_addr(d.i.img, &d.i.bits_per_pixel, &d.i.line_length,
			&d.i.endian);
	map_size(titel, &d.line, &d.colomn);
	d.map = read_map(titel, d.line, d.colomn);
	d.map_i = allocation(&d);
	initialize(&d);
	projection(&d, d.p_type);
	dda(&d, d.map_i, d.line, d.colomn);
	guide(&d);
	fdf(&d);
	mlx_put_image_to_window(d.ptr, d.win, d.i.img, 300, 0);
	mlx_hook(d.win, 17, 0, clear, &d);
	mlx_key_hook(d.win, key_control, &d);
	mlx_mouse_hook(d.win, mouse_control, &d);
	mlx_loop(d.ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 02:14:00 by rrasezin          #+#    #+#             */
/*   Updated: 2022/12/19 21:56:37 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    draw_line(int width, int length)
{
	void	*mlx_ptr;
    void	*mlx_win;
    t_data	mlx_img;
	l_point	*point;
	int		y;
	int		x;

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, width, length, "fdf");
	mlx_img.img = mlx_new_image(mlx_ptr, width, length);
	mlx_img.addr = mlx_get_data_addr(mlx_img.img, &mlx_img.bits_per_pixel, &mlx_img.line_length, &mlx_img.endian);

	int yy = get_line_number("test_maps/julia.fdf");
	int	xx = get_colomn_number("test_maps/julia.fdf");
	float x_screen;
    float y_screen;
	float angle = (38 * 3.14) / 180;
	int fd = open("test_maps/julia.fdf", O_RDONLY);
	y = 0;
	x = 0;
	// int	x_m = (width/(xx + 2))/2;
	// int	y_m = (length/(yy + 2))/2;
	while (y < yy)
	{
		while (x < xx)
		{
			point = get_point(fd, y, x, 6000);
        	x_screen = (point->x_map - point->y_map)*cos(angle)+450;
        	y_screen = (point->x_map + point->y_map)*sin(angle) - point->z_map+50;
			printf("x : %d |y : %d |z : %d |color : %d\n", point->x_map, point->y_map, point->z_map, point->color);
            printf("x_screen : %f|y_screen : %f\n", x_screen, y_screen);
			if (point->z_map == 10)
				my_mlx_pixel_put(&mlx_img, x_screen , y_screen , point->z_map);
			else 
				my_mlx_pixel_put(&mlx_img, x_screen , y_screen , 0xFFFFFF);
			x++;
		}
		x = 0;
        y++;
	} 
	mlx_put_image_to_window(mlx_ptr, mlx_win, mlx_img.img, 0, 0);
	mlx_loop(mlx_ptr);
}

int main()
{
	
	// l_point point;
	// point = get_point("test_map/42.fdf", );
    draw_line(2880, 5120);
}
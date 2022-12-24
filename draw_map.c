/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:52:26 by rrasezin          #+#    #+#             */
/*   Updated: 2022/12/25 00:16:23 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <unistd.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// void    draw_line(t_mlx	mlx, l_point *point, l_point *n_point)
// {
// 	t_line	line;
	
// 	line.x1 = point->x_map + 150;
// 	line.y1 = point->y_map + 50;
// 	if (n_point == NULL)
// 		return;
// 	line.x2 = n_point->x_map + 150;
// 	line.y2 = n_point->y_map + 50;
// 	if (point->z_map == 10)
// 		my_mlx_pixel_put(&mlx.img, line.x1 , line.y1 , point->color);
// 	else
// 		my_mlx_pixel_put(&mlx.img, line.x1 , line.y1 , 0xFFF);
// 	// my_mlx_pixel_put(&mlx.img, line.x1 , line.y1 , 0xFFFFFF);
// 	printf ("y1 : %f\ny2 : %f\n", line.y1, line.y2);
// 	printf ("x1 : %f\nx2 : %f\n", line.x1, line.x2);

// }

void line(l_point *p0 , l_point *p1, t_mlx	mlx)
{
	int dx;
	int	dy;
	int d;
	int y;
	int yi;
	int x;
	
	if (p1 == NULL)
		return;
	dx = p1->x_map - p0->x_map;
	dy = p1->y_map - p0->y_map;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = (-1) * dy;
	}
	d = 2*dy - dx;

	x = p0->x_map;
	y =  p0->y_map;
	// x = p0->x_map*15 ;
	// y = p0->y_map*15;
	while (x < p1->x_map)
	{
		if (p0->z_map == 10)
			my_mlx_pixel_put(&mlx.img, x , y , 0xFFFFFF);
		else
			my_mlx_pixel_put(&mlx.img, x , y , p0->color);
		if (d > 0)
		{
			y = y + yi;
			d = d + (2*(dy - dx));
		}
		d = d + 2*dy;
		x++;
	}
}
void line_b(l_point *p0 , l_point *p1, t_mlx	mlx)
{
	int dx;
	int	dy;
	int d;
	int y;
	int xi;
	int x;
	
	if (p1 == NULL)
		return;
	dx = p1->x_map - p0->x_map;
	dy = p1->y_map - p0->y_map;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	d = 2*dx - dy;

	x = p0->x_map;
	y = p0->y_map ;
	while (y < p1->y_map )
	{
		if (p0->z_map == 10)
			my_mlx_pixel_put(&mlx.img, x , y , 0xFFFFFF);
		else
			my_mlx_pixel_put(&mlx.img, x , y , p0->color);
		if (d > 0)
		{
			x = x - xi;
			d = d + (2*(dx - dy));
		}
		d = d + 2*dx;
		y++;
	}
}
void	line_dr(l_point *p0 , l_point *p1, t_mlx	mlx)
{
	if (p1 == NULL)
		return;
	if (fabs(p1->y_map - p0->y_map) < fabs(p1->x_map - p0->x_map))
	{
		if (p0->x_map > p1->x_map)
			line(p1, p0, mlx);
		else
			line(p0, p1, mlx);
	}
	else
	{
		if (p0->y_map > p1->y_map)
			line_b(p1, p0, mlx);
		else
			line_b(p0, p1, mlx);
	}
}
void	mlx_creat(int width, int lenght, char *map, char *title)
{
	t_mlx	mlx;

	mlx.mlx_ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx_ptr, width, lenght, title);
	mlx.img.img = mlx_new_image(mlx.mlx_ptr, width, lenght);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel, &mlx.img.line_length, &mlx.img.endian);
	mlx.map_id = open(map, O_RDONLY);
	mlx.yy = get_line_number(map);
	mlx.xx = get_colomn_number(map);
	mlx.x = 0;
	mlx.y = 0;
	while (mlx.y < mlx.yy)
	{
		while (mlx.x < mlx.xx)
		{
			mlx.point = get_point(mlx.map_id, mlx.y, mlx.x, 6000);
			// draw_line(mlx, mlx.point, mlx.point->next_point);
			// draw_line(mlx, mlx.point, mlx.point->bottom_point);
			line_dr(mlx.point , mlx.point->next_point,mlx);
			line_dr(mlx.point , mlx.point->bottom_point,mlx);
			mlx.x++;
			printf("mlx.x = %d\n", mlx.x);
		}
		mlx.x = 0;
		mlx.y++;
			printf("mlx.y = %d\n", mlx.y);
	}
	close(mlx.map_id);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img.img, 200, 150);
	mlx_loop(mlx.mlx_ptr);
}



int main()
{
	
	// l_point point;
	// point = get_point("test_map/42.fdf", );
	// printf ("hello");
    mlx_creat(1000,1000, "test_maps/42.fdf", "42");
}


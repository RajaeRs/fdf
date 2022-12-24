/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ddddd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:24:51 by rrasezin          #+#    #+#             */
/*   Updated: 2022/12/24 18:24:53 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	dx = (p1->x_map - p1->y_map)*15*cos((38 * 3.14) / 180) - (p0->x_map - p0->y_map)*15*cos((38 * 3.14) / 180)+100;
	dy = (p1->x_map + p1->y_map)*15*sin((38 * 3.14) / 180) - p1->z_map - (p0->x_map + p0->y_map)*15*sin((38 * 3.14) / 180) - p0->z_map+50;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	d = 2*dy - dx;

	x = (p0->x_map - p0->y_map)*15*cos((38 * 3.14) / 180)+100;
	y = (p0->x_map + p0->y_map)*15*sin((38 * 3.14) / 180) - p0->z_map+50;
	// x = p0->x_map*15 ;
	// y = p0->y_map*15;
	while (x < (p1->x_map + p1->y_map)*15*sin((38 * 3.14) / 180) - p1->z_map+50)
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
	dx = (p1->x_map - p1->y_map)*15*cos((38 * 3.14) / 180) - (p0->x_map - p0->y_map)*15*cos((38 * 3.14) / 180)+100;
	dy = (p1->x_map + p1->y_map)*15*sin((38 * 3.14) / 180) - p1->z_map - (p0->x_map + p0->y_map)*15*sin((38 * 3.14) / 180) - p0->z_map+50;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	d = 2*dx - dy;

	// x = p0->x_map*15 ;
	// y = p0->y_map*15;
	x = (p0->x_map - p0->y_map)*15*cos((38 * 3.14) / 180)+100;
	y = (p0->x_map + p0->y_map)*15*sin((38 * 3.14) / 180) - p0->z_map+50;
	while (y < (p1->x_map + p1->y_map)*15*sin((38 * 3.14) / 180) - p1->z_map+50)
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
	int l = (p1->x_map - p1->y_map)*15*cos((38 * 3.14) / 180)+100;
	int k = (p1->x_map + p1->y_map)*15*sin((38 * 3.14) / 180) - p1->z_map+50;;
	 int l1 = (p0->x_map - p0->y_map)*15*cos((38 * 3.14) / 180)+100;
 	int k1 = (p0->x_map + p0->y_map)*15*sin((38 * 3.14) / 180) - p0->z_map+50;;
	if (abs(l - l1) < abs(k- k1))
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
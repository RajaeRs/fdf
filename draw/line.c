/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 23:49:41 by rrasezin          #+#    #+#             */
/*   Updated: 2022/12/31 03:54:28 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
static int	abss(int x)
{
	if (x > 0)
		return (x);
	else
		return(x * (-1));		
}
static int	maxx(int x, int y)
{
	if (x > y)
		return (x);
	else
		return (y);
}
static void	line(t_data *data, l_point *p0, l_point *p1)
{
	t_line  l;

	if (p1 == NULL)
		return;
	l.dx = (float)(p1->x_map - p0->x_map);
	l.dy = (float)(p1->y_map - p0->y_map);
	l.step = maxx(abss(l.dx), abss(l.dy));
	l.dx = l.dx / l.step;
	l.dy = l.dy / l.step;
	l.x = p0->x_map+500;
	l.y = p0->y_map;
	l.i = 1;
	while (l.i <= l.step)
	{
		// if (p0->z_map == 10)
			my_mlx_pixel_put(data, l.x, l.y, p0->color);
		// else 
		// 	my_mlx_pixel_put(data, l.x, l.y, 0xFFFFFF);
		l.x += l.dx;
		l.y += l.dy;
		l.i++;
	}
}

void    draw(t_data *data, l_point *p)
{
    if (p->next_point != NULL)
    {
        line(data, p, p->next_point);
        free(p->next_point);
    }
    if (p->bottom_point != NULL)
    {
        line(data, p, p->bottom_point);
    	free(p->bottom_point);
	}
    free(p);
}

// int	main()
// {
// 	l_point	*p0;
// 	l_point *p1;
// 	void	*ptr;
// 	void	*win;
// 	t_data	data;
// 	ptr = mlx_init();
// 	win = mlx_new_window(ptr, 500, 500, "test_again");
// 	data.img = mlx_new_image(ptr, 500, 500);
// 	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
// 	p0 = new_point(200,100,5, 0xFFFFFF);
// 	p1 = new_point(200,200,5, 0x00e18b);
// 	// mlx_pixel_put(ptr, win, p0->x_map, p0->y_map, p0->color); // drawing p0 
// 	// mlx_pixel_put(ptr, win, p1->x_map, p1->y_map, p1->color); // drawing p1
// 	my_mlx_pixel_put(&data, p1->x_map, p1->y_map, p1->color);
// 	iso_p(p0);
// 	iso_p(p1);
// 	line (&data, p1, p0 );
// 	// mlx_pixel_put(ptr, win, p0->x_map, p0->y_map, p0->color); // drawing p0 after iso
// 	// mlx_pixel_put(ptr, win, p1->x_map, p1->y_map, p1->color); // // drawing p1 after iso
// 	// line (p1, p0, ptr, win);
// 	mlx_put_image_to_window(ptr, win, data.img, 0 , 0);
// 	mlx_loop(ptr);
// }
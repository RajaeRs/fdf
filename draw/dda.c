/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 03:51:47 by rrasezin          #+#    #+#             */
/*   Updated: 2023/01/24 16:15:08 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

//p : position
static int	intp(int lenth, int color0, int color1, int p)
{
	t_rgb	c0;
	t_rgb	c1;
	int		r;
	int		g;
	int		b;

	c0.r = (float)((color0 >> 16) & (0xFF))*((float)(lenth - p) / (float)lenth);
	c0.g = (float)((color0 >> 8) & (0xFF))*((float)(lenth - p) / (float)lenth);
	c0.b = (float)((color0) & (0xFF))*((float)(lenth - p) / (float)lenth);
	c1.r = (float)((color1 >> 16) & (0xFF))*((float)p / (float)lenth);
	c1.g = (float)((color1 >> 8) & (0xFF))*((float)p / (float)lenth);
	c1.b = (float)((color1) & (0xFF))*((float)p / (float)lenth);
	r = (int)(c0.r + c1.r);
	g = (int)(c0.g + c1.g);
	b = (int)(c0.b + c1.b);
	return (r << 16 | g << 8 | b);
}

static void	line_d(t_mlx *mlx, t_map **map, int y, int x)
{
	t_line	l;
	int		color;

	l.dx = (float)(map[y][x + 1].x - map[y][x].x);
	l.dy = (float)(map[y][x + 1].y - map[y][x].y);
	l.step = fmax(fabs(l.dx), fabs(l.dy));
	l.dx = l.dx / l.step;
	l.dy = l.dy / l.step;
	l.x = map[y][x].x  + mlx->m.zoom_out;
	l.y = map[y][x].y + mlx->m.zoom_in;
	l.i = 1;
	while (l.i <= l.step)
	{
		color = intp(l.step - 1, map[y][x].c, map[y][x + 1].c, l.i - 1);
		my_mlx_pixel_put(&mlx->i, l.x+mlx->m.m_left, l.y+mlx->m.m_up, color);
		l.x += l.dx;
		l.y += l.dy;
		l.i++;
	}
}

static void	line_d_d(t_mlx *mlx, t_map **map, int y, int x)
{
	t_line	l;
	int		color;

	l.dx = (float)(map[y + 1][x].x - map[y][x].x);
	l.dy = (float)(map[y + 1][x].y - map[y][x].y);
	l.step = fmax(fabs(l.dx), fabs(l.dy));
	l.dx = l.dx / l.step;
	l.dy = l.dy / l.step;
	l.x = map[y][x].x + mlx->m.zoom_out ;
	l.y = map[y][x].y + mlx->m.zoom_in;
	l.i = 1;
	while (l.i <= l.step)
	{
		if (map[y][x].z == map[y + 1][x].z)
			color = map[y][x].c;
		else
			color = intp(l.step - 1, map[y][x].c, map[y + 1][x].c, l.i - 1);
		my_mlx_pixel_put(&mlx->i, l.x+mlx->m.m_left, l.y+mlx->m.m_up, color);
		l.x += l.dx;
		l.y += l.dy;
		l.i++;
	}
}

void	dda(t_mlx *mlx, t_map **map, int line, int colomn)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < line - 1 )
	{
		while (x < colomn - 1)
		{
			line_d(mlx, map, y, x);
			line_d_d(mlx, map, y, x);
			x++;
		}
		free(map[y]);
		x = 0;
		y++;
	}
	free(map[y]);
	free(map);
}


// void	dda(t_mlx *mlx, t_map **map, int line, int colomn)
// {
// 	int		x;
// 	int		y;

// 	x = mlx->m.m_left;
// 	y = mlx->m.m_up;
// 	while (y < line - 1 && map[y][x].y < HEIGHT/3)
// 	{
// 		while (x < colomn - 1 && map[y][x].x < WIDTH/2)
// 		{
// 			if (map[y][x].x > -(WIDTH/2) && map[y][x].y > -(HEIGHT/3))
// 			{
// 				line_d(mlx, map, y, x);
// 				line_d_d(mlx, map, y, x);
// 			}
// 			x++;
// 		}
// 		x = 0;
// 		y++;
// 	}
// 	free(map[y]);
// 	free(map);
// }
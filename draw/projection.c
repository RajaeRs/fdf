/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 01:09:08 by rrasezin          #+#    #+#             */
/*   Updated: 2023/01/25 23:44:52 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	iso(t_mlx *p)
{
	float	ang1;
	float	ang2;
	float	i;
	float	j;
	int		x;
	int		y;

	x = 0;
	y = 0;
	ang1 = (p->ang1 * 3.14) / 180;
	ang2 = (p->ang2 * 3.14) / 180;
	while (y < p->line)
	{	
		while (x < p->colomn)
		{
			i = p->map[y][x].x * ((float)HEIGHT / (float)(p->m.xz * p->colomn));
			j = p->map[y][x].y * ((float)WIDTH / (float)(p->m.yz * p->line));
			p->map_i[y][x].x = (int)(i*cos(ang1) - j*cos(ang1));
			p->map_i[y][x].y = (int)(i*sin(ang2) + j*sin(ang2)) - p->map[y][x].z * p->m.up;
			p->map_i[y][x].z = p->map[y][x].z;
			p->map_i[y][x].c = p->map[y][x].c;
			x++;
		}
		x = 0;
		y++;
	}
}

void	projection(t_mlx *p, int p_type)
{
	if (p_type == 34)
		iso(p);
	// if (p_type == 35)
	// 	iso(p);
}
// int	main()
// {
	//int y = 0;
	//int	x = 0;
	//while (y < d.line)
	//{
	//	while (x < d.colomn)
	//	{
	//		printf ("x:%d, y:%d, z:%d, c: %d\n", d.map[y][x].x, d.map[y][x].y, d.map[y][x].z, d.map[y][x].c);
	//		x++;
	//	}
	//	x = 0;
	//	y++;
	//}
// }
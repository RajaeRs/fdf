/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:50:09 by rrasezin          #+#    #+#             */
/*   Updated: 2023/01/02 10:06:29 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// t_point	*new_point(int x, int y, int z, int color)
// {
// 	t_point	*map_point;
//
// 	map_point = malloc(sizeof(t_point));
// 	if (!map_point)
// 		return (NULL);
// 	map_point -> x_map = x; 
// 	map_point -> y_map = y;
// 	map_point -> z_map = z;
// 	map_point -> color = color;
// 	map_point -> next_point = NULL;
// 	map_point -> bottom_point = NULL;
// 	return (map_point);
// }

static void	iso_p(t_point *p, t_mlx *mlx)
{
	int		x;
	int		y;
	float	angle;

	if (p == NULL)
		return ;
	angle = (38 * 3.14) / 180;
	x = p->x_map * ((float)LENGTH / (float)(1.5 * mlx->xx));
	y = p->y_map * ((float)WIDTH / (float)(1.5 * mlx->yy));
	p->x_map = (x - y) * cos(angle);
	p->y_map = (x + y) * sin(angle) - p->z_map * 3;
}

void	iso(t_point *p, t_mlx *mlx)
{
	iso_p(p, mlx);
	iso_p(p->next_point, mlx);
	iso_p(p->bottom_point, mlx);
}

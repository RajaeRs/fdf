/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:50:09 by rrasezin          #+#    #+#             */
/*   Updated: 2022/12/31 03:54:12 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// l_point	*new_point(int x, int y, int z, int color)
// {
// 	l_point	*map_point;
//
// 	map_point = malloc(sizeof(l_point));
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
static void	iso_p(l_point *p)
{
	if (p == NULL)
		return;
	int	x;
	int	y;
	float angle;

	angle = (38 * 3.14) / 180;
	x = p->x_map*13;
	y = p->y_map*22;
	p->x_map = (x - y)*cos(angle) ;
	p->y_map = (x + y)*sin(angle) - p->z_map*2 ;
}

void	iso(l_point *p)
{
	iso_p(p);
	iso_p(p->next_point);
	iso_p(p->bottom_point);
}

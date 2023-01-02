/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 02:17:12 by rrasezin          #+#    #+#             */
/*   Updated: 2023/01/02 10:01:18 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_point	*new_point(int x, int y, int z, int color)
{
	t_point	*map_point;

	map_point = malloc(sizeof(t_point));
	if (!map_point)
		return (NULL);
	map_point -> x_map = x;
	map_point -> y_map = y;
	map_point -> z_map = z;
	map_point -> color = color;
	map_point -> next_point = NULL;
	map_point -> bottom_point = NULL;
	return (map_point);
}

void	add_next_point(t_point *point, t_point *new_point)
{
	if (!point)
		return ;
	if (point)
		point ->next_point = new_point;
	else
		point = new_point;
}

void	add_bottom_point(t_point *point, t_point *new_point)
{
	if (!point)
	{
		return ;
	}
	if (point)
		point ->bottom_point = new_point;
	else
		point = new_point;
}

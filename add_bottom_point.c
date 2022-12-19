/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_bottom_point.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 02:17:21 by rrasezin          #+#    #+#             */
/*   Updated: 2022/12/18 22:51:42 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int	y_point_size(l_point *point)
{
	int	size;

	size = 1;
	if (!point)
		return (0);
	while (point -> bottom_point != NULL)
	{
		point = point -> bottom_point;
		size++;
	}
	return (size);
}

static	l_point *y_point_last(l_point *point)
{
	int	i;

	i = y_point_size(point);
	while (i > 1)
	{
		point = point -> bottom_point;
		i--;
	}
	return (point);
}

void	add_bottom_point(l_point **point, l_point *new_point)
{
	l_point	*last;

	if (!point)
	{
		return;
	}
	last = y_point_last(*point);
	if (point)
		last ->bottom_point = new_point;
	else
		*point = new_point;
}
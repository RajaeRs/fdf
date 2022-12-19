/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_next_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 02:17:12 by rrasezin          #+#    #+#             */
/*   Updated: 2022/12/17 14:46:16 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int	x_point_size(l_point *point)
{
	int	size;

	size = 1;
	if (!point)
		return (0);
	while (point -> next_point != NULL)
	{
		point = point -> next_point;
		size++;
	}
	return (size);
}

static	l_point *x_point_last(l_point *point)
{
	int	i;

	i = x_point_size(point);
	while (i > 1)
	{
		point = point -> next_point;
		i--;
	}
	return (point);
}

void	add_next_point(l_point **point, l_point *new_point)
{
	l_point	*last;

	if (!point)
		return ;
	last = x_point_last(*point);
	if (point)
		last ->next_point = new_point;
	else
		*point = new_point;
}
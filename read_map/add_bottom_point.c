/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_bottom_point.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 02:17:21 by rrasezin          #+#    #+#             */
/*   Updated: 2022/12/31 00:37:35 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	add_bottom_point(l_point *point, l_point *new_point)
{
	if (!point)
	{
		return;
	}
	if (point)
		point ->bottom_point = new_point;
	else
		point = new_point;
}
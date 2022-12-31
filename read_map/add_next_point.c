/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_next_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 02:17:12 by rrasezin          #+#    #+#             */
/*   Updated: 2022/12/31 00:37:47 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	add_next_point(l_point *point, l_point *new_point)
{
	if (!point)
		return ;
	if (point)
		point ->next_point = new_point;
	else
		point = new_point;
}
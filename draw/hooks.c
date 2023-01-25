/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:13:03 by rrasezin          #+#    #+#             */
/*   Updated: 2023/01/24 01:01:23 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	clear(int key, t_mlx *d)
{
	(void)key;
	(void)d;
	exit(0);
}

int	esc(int key, t_mlx *d)
{
	int	i;

	i = 0;
	if (key == 53)
	{
		mlx_clear_window(d->ptr, d->win);
		mlx_destroy_image(d->ptr, d->i.img);
		mlx_destroy_window(d->ptr, d->win);
		exit(0);
	}
	return (0);
}
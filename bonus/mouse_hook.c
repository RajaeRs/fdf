/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:03:03 by rrasezin          #+#    #+#             */
/*   Updated: 2023/01/24 17:58:51 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	zoom_in(t_mlx *p)
{
	mlx_clear_window(p->ptr, p->win);
    ft_bzero(p->i.addr, HEIGHT*WIDTH*sizeof(int)*4);
	p->map_i = allocation(p);
	p->m.xz += 0.1;
	p->m.yz += 0.1;
	p->m.zoom_in += (cos(20)*10)/p->m.xz ;
	projection(p, p->p_type);
    dda(p, p->map_i, p->line, p->colomn);
}

void	zoom_out(t_mlx *p)
{
	if (p->m.xz <= 0.4)
		return;
	mlx_clear_window(p->ptr, p->win);
    ft_bzero(p->i.addr, HEIGHT*WIDTH*sizeof(int)*4);
	p->map_i = allocation(p);
	p->m.xz -= 0.1;
	p->m.yz -= 0.1;
	p->m.zoom_in -= (cos(20)*10)/p->m.xz;
	projection(p, p->p_type);
    dda(p, p->map_i, p->line, p->colomn);
}

int    mouse_control(int key, int x, int y, t_mlx *p)
{
	(void)x;
	(void)y;

	if (key == 4)
		zoom_in(p);
	if (key == 5)
		zoom_out(p);
	mlx_put_image_to_window(p->ptr, p->win, p->i.img, 0, 0);
	return (0);
}
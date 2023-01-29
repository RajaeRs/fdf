/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:03:03 by rrasezin          #+#    #+#             */
/*   Updated: 2023/01/29 14:32:40 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	zoom_in(t_mlx *p)
{
	ft_bzero(p->i.addr, HEIGHT * WIDTH * sizeof(int));
	p->map_i = allocation(p);
	p->m.xz += 0.1;
	p->m.yz += 0.1;
	p->zoom -= 10;
	p->m.zoom_in += log10(300) / p->m.xz ;
	projection(p, p->p_type);
	dda(p, p->map_i, p->line, p->colomn);
}

void	zoom_out(t_mlx *p)
{
	ft_bzero(p->i.addr, HEIGHT * WIDTH * sizeof(int));
	if (p->m.xz < 0.1)
		return ;
	p->map_i = allocation(p);
	p->m.xz -= 0.1;
	p->m.yz -= 0.1;
	p->zoom += 10;
	p->m.zoom_in -= log10(300) / p->m.xz;
	projection(p, p->p_type);
	dda(p, p->map_i, p->line, p->colomn);
}

int	mouse_control(int key, int x, int y, t_mlx *p)
{
	(void)x;
	(void)y;
	if (key == 5)
		zoom_in(p);
	if (key == 4)
		zoom_out(p);
	mlx_put_image_to_window(p->ptr, p->win, p->i.img, 300, 0);
	return (0);
}

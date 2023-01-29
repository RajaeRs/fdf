/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:11:00 by rrasezin          #+#    #+#             */
/*   Updated: 2023/01/29 15:04:18 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	altitude(t_mlx *p, int key)
{
	int	i;

	i = 0;
	p->map_i = allocation(p);
	if (key == 69)
	{
		p->m.up += 0.5;
		i = 1;
	}
	if (key == 78)
	{
		p->m.up -= 0.5;
		i = 1;
	}
	if (i == 1)
	{
		ft_bzero(p->i.addr, HEIGHT * WIDTH * sizeof(int));
		projection(p, p->p_type);
		dda(p, p->map_i, p->line, p->colomn);
	}
}

void	mouve(t_mlx *p, int key)
{
	ft_bzero(p->i.addr, HEIGHT * WIDTH * sizeof(int));
	p->map_i = allocation(p);
	if (key == 123)
		p->m.m_left -= p->zoom;
	if (key == 124)
		p->m.m_left += p->zoom;
	if (key == 125)
		p->m.m_up += p->zoom;
	if (key == 126)
		p->m.m_up -= p->zoom;
	projection(p, p->p_type);
	dda(p, p->map_i, p->line, p->colomn);
}

void	rotate(t_mlx *p, int key)
{
	ft_bzero(p->i.addr, HEIGHT * WIDTH * sizeof(int));
	p->map_i = allocation(p);
	if (key == 2)
		p->ang -= 10;
	if (key == 0)
		p->ang += 10;
	projection(p, p->p_type);
	dda(p, p->map_i, p->line, p->colomn);
}

void	p_type(t_mlx *p, int key)
{
	if (key == p->p_type)
		return ;
	ft_bzero(p->i.addr, HEIGHT * WIDTH * sizeof(int));
	p->map_i = allocation(p);
	if (key == 31)
		p->p_type = 31;
	if (key == 34)
		p->p_type = 34;
	projection(p, p->p_type);
	dda(p, p->map_i, p->line, p->colomn);
}

int	key_control(int key, t_mlx *p)
{
	(void)key;
	if (key == 53)
		esc(key, p);
	if (key == 78 || key == 69)
		altitude(p, key);
	if (key >= 123 && key <= 126)
		mouve(p, key);
	if ((key >= 0 && key <= 2) || (key >= 12 && key <= 14))
		rotate(p, key);
	if (key == 31 || key == 34)
		p_type(p, key);
	if (key == 15)
	{
		ft_bzero(p->i.addr, HEIGHT * WIDTH * sizeof(int));
		p->map_i = allocation(p);
		initialize(p);
		projection(p, p->p_type);
		dda(p, p->map_i, p->line, p->colomn);
	}
	mlx_put_image_to_window(p->ptr, p->win, p->i.img, 300, 0);
	return (0);
}

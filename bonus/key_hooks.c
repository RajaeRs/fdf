/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:11:00 by rrasezin          #+#    #+#             */
/*   Updated: 2023/01/25 16:38:06 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void    altitude(t_mlx *p, int key)
{
    int i;

    i = 0;
	p->map_i = allocation(p);
    if (key == 32 && p->m.up <= 4)
    {
        p->m.up += 0.5;
        i = 1;
    }
    if (key == 2 && p->m.up >= -4)
    {
        p->m.up -= 0.5;
        i = 1;
    }
    if (i == 1)
    {
        ft_bzero(p->i.addr, HEIGHT*WIDTH*sizeof(int)*4);
        projection(p, p->p_type);
        dda(p, p->map_i, p->line, p->colomn);     
    }
}

void    mouve(t_mlx *p, int key)
{
    if (p->m.m_up >= -1000 && p->m.m_up <= 2000 && p->m.m_left >= -1000 && p->m.m_left <= 2000)
    {      
        ft_bzero(p->i.addr, HEIGHT*WIDTH*sizeof(int)*4);
        p->map_i = allocation(p);
        if (key == 123 && p->m.m_left >= -1000)
            p->m.m_left -= 10;
        if (key == 124 && p->m.m_left <= 2000)
            p->m.m_left += 10;
        if (key == 125 && p->m.m_up <= 2000)
            p->m.m_up += 10;
        if (key == 126 && p->m.m_up >= -1000)
            p->m.m_up -= 10;
        projection(p, p->p_type);
        dda(p, p->map_i, p->line, p->colomn);
    }
}

int key_control(int key, t_mlx *p)
{
    (void)key;
	if (key == 53)
		esc(key, p);
    if (key == 32 || key == 2)
        altitude(p, key);
    if (key >= 123 && key <= 126)
        mouve(p, key);
	printf("%d\n",key);
	mlx_put_image_to_window(p->ptr, p->win, p->i.img, 0, 0);
    return (0);
}

    // if (key == 34)
    //     projection(p, key);
    // if (key == 35)
    //     projection(p, key);
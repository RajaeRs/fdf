/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 01:09:08 by rrasezin          #+#    #+#             */
/*   Updated: 2023/01/29 15:30:25 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	isometrice(t_mlx *p)
{
	t_rotat	r;

	r.x = 0;
	r.y = 0;
	r.i_ang = (30 * 3.14) / 180;
	r.r_ang = (p->ang * 3.14) / 180;
	while (r.y < p->line)
	{	
		while (r.x < p->colomn)
		{
			r.i = p->map[r.y][r.x].x * ((float)WIDTH
					/ (float)(p->m.xz * p->colomn)) - 500;
			r.j = p->map[r.y][r.x].y * ((float)HEIGHT
					/ (float)(p->m.yz * p->line)) - 325;
			r.z = p->map[r.y][r.x].z * p->m.up;
			r.r_x = (float)r.i * cos(r.r_ang) + (float)r.j * -sin(r.r_ang);
			r.r_y = (float)r.i * sin(r.r_ang) + (float)r.j * cos(r.r_ang);
			p->map_i[r.y][r.x].x = (int)((r.r_x - r.r_y) * cos(r.i_ang));
			p->map_i[r.y][r.x].y = (int)((r.r_x + r.r_y) * sin(r.i_ang) - r.z);
			p->map_i[r.y][r.x].z = r.z;
			p->map_i[r.y][r.x++].c = p->map[r.y][r.x].c;
		}
		r.x = 0;
		r.y++;
	}
}

static void	oblique(t_mlx *p)
{
	t_rotat	r;

	r.x = 0;
	r.y = 0;
	r.i_ang = (30 * 3.14) / 180;
	r.r_ang = (p->ang * 3.14) / 180;
	while (r.y < p->line)
	{	
		while (r.x < p->colomn)
		{
			r.i = p->map[r.y][r.x].x * ((float)WIDTH
					/ (float)(p->m.xz * p->colomn)) - 500;
			r.j = p->map[r.y][r.x].y * ((float)HEIGHT
					/ (float)(p->m.yz * p->line)) - 325;
			r.z = p->map[r.y][r.x].z * p->m.up;
			r.r_x = (float)r.i * cos(r.r_ang) + (float)r.j * -sin(r.r_ang);
			r.r_y = (float)r.i * sin(r.r_ang) + (float)r.j * cos(r.r_ang);
			p->map_i[r.y][r.x].x = (int)(r.r_x + 0.5 * r.z * cos(r.i_ang));
			p->map_i[r.y][r.x].y = (int)(r.r_y + 0.5 * r.z * sin(r.i_ang));
			p->map_i[r.y][r.x].z = r.z;
			p->map_i[r.y][r.x++].c = p->map[r.y][r.x].c;
		}
		r.x = 0;
		r.y++;
	}
}

void	projection(t_mlx *p, int p_type)
{
	if (p_type == 34)
		isometrice(p);
	if (p_type == 31)
		oblique(p);
}

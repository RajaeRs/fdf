/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:52:26 by rrasezin          #+#    #+#             */
/*   Updated: 2022/12/31 03:53:39 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <mlx.h>
#include <unistd.h>

void	mlx_creat(int width, int lenght, char *map, char *title)
{
	t_mlx	mlx;

	mlx.mlx_ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx_ptr, width, lenght, title);
	mlx.img.img = mlx_new_image(mlx.mlx_ptr, width, lenght);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel, &mlx.img.line_length, &mlx.img.endian);
	mlx.map_id = open(map, O_RDONLY);
	mlx.yy = get_line_number(map);
	mlx.xx = get_colomn_number(map);
	mlx.x = 0;
	mlx.y = 0;
	while (mlx.y < mlx.yy)
	{
		while (mlx.x < mlx.xx)
		{
			mlx.point = get_point(mlx.map_id, mlx.y, mlx.x); 
			iso(mlx.point);
			draw(&mlx.img, mlx.point);
			mlx.x++;
		}
		mlx.x = 0;
		mlx.y++;
	}
	close(mlx.map_id);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img.img, 0, 0);
	mlx_loop(mlx.mlx_ptr);
}



int main()
{
    mlx_creat(1000,1000, "maps/42.fdf", "42");
	while(1)
		;
}


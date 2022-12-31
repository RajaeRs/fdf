/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ok.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:35:03 by rrasezin          #+#    #+#             */
/*   Updated: 2022/12/17 11:02:39 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main()
{
    void    *mlx_ptr;
    void    *mlx_win;
    t_data  mlx_img;

    // int map[10][10] = {{0,0,0,0,0,0,0,0,0,0},
    //                    {0,0,0,0,0,0,0,0,0,0},
    //                    {0,1,1,1,0,1,1,1,0,0},
    //                    {0,1,0,1,0,1,0,1,0,0},
    //                    {0,1,1,1,0,1,1,1,0,0},
    //                    {0,0,0,0,1,0,0,0,0,0},
    //                    {0,0,0,1,1,1,0,0,0,0},
    //                    {0,1,0,0,0,0,0,1,0,0},
    //                    {0,1,1,1,1,1,1,1,0,0},
    //                    {0,0,0,0,0,0,0,0,0,0}};
    int map42[11][19] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 10, 10, 0, 0, 10, 10, 0, 0, 0, 10, 10, 10, 10, 10, 0, 0, 0},
                        {0, 0, 10, 10, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0, 0, 10, 10, 0, 0},
                        {0, 0, 10, 10, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0, 0, 10, 10, 0, 0},
                        {0, 0, 10, 10, 10, 10, 10, 10, 0, 0, 0, 0, 10, 10, 10, 10, 0, 0, 0},
                        {0, 0, 0, 10, 10, 10, 10, 10, 0, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 10, 10, 0, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 10, 10, 0, 0, 0, 10, 10, 10, 10, 10, 10, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};


mlx_ptr = mlx_init();
mlx_win = mlx_new_window(mlx_ptr, 1024, 1080, "isometric projection");
mlx_img.img = mlx_new_image(mlx_ptr, 1024, 1080);
mlx_img.addr = mlx_get_data_addr(mlx_img.img, &mlx_img.bits_per_pixel, &mlx_img.line_length, &mlx_img.endian);

    float x_screen;
    float y_screen;
    int   x = 0;
    int   y = 0;
    float angle = (38 * 3.14) / 180;
    
    int k = x;
    int l = y;
    
    while (y < 11)
    {
        while (x < 19)
        {
            l = y*15;
            k = x*15;
            x_screen = (k - l) * cos(angle)  + 200;
            y_screen = (k + l)*sin(angle) - map42[y][x] + 200;
            printf("x : %d |y : %d |z : %d |color : %d\n", x, y, map42[y][x], 0x0000FA9A);
            printf("x_screen : %f|y_screen : %f\n", x_screen, y_screen);
            if (map42[y][x] == 10)
                my_mlx_pixel_put(&mlx_img, x_screen, y_screen, 0x0000FA9A);
            else
                my_mlx_pixel_put(&mlx_img, x_screen, y_screen, 0x0077B5EF);   
            x++;
        }
        x = 0;
        y++;  
    }

    
mlx_put_image_to_window(mlx_ptr, mlx_win, mlx_img.img, 0, 0);
mlx_loop(mlx_ptr);
}
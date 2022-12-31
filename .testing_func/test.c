/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:35:03 by rrasezin          #+#    #+#             */
/*   Updated: 2022/12/09 20:09:02 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <math.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

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
    // void    *mlx_img;
    int map[10][10] = {{0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0},
                       {0,1,1,1,0,1,1,1,0,0},
                       {0,1,0,1,0,1,0,1,0,0},
                       {0,1,1,1,0,1,1,1,0,0},
                       {0,0,0,0,1,0,0,0,0,0},
                       {0,0,0,1,1,1,0,0,0,0},
                       {0,1,0,0,0,0,0,1,0,0},
                       {0,1,1,1,1,1,1,1,0,0},
                       {0,0,0,0,0,0,0,0,0,0}};
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
    int x;
    int y;
    int pixel;
    
    x = 0;
    y = 0;
    // printf("%d\n", map[y][x]);

    mlx_ptr = mlx_init();
    
/*------------ in windows --------------*/
    mlx_win = mlx_new_window(mlx_ptr, 500, 500, "smile :)");
    // while (x < 10)
    // {
    //     while (y < 10)
    //     {
    //         if (map[y][x] == 1)
    //         {
    //             pixel = mlx_pixel_put(mlx_ptr, mlx_win, x+100, y+100, 0x00FFF012);
                
    //         }
    //         y++;
    //         // printf("%d\n", map[y][x]);
    //     }
    //     x++;
    //     y = 0;
    // }

/*------------ in image --------------*/
float x_screen = 500 / (19 );
float y_screen = 500 / (11 );


mlx_img.img = mlx_new_image(mlx_ptr, 500, 500);
mlx_img.addr = mlx_get_data_addr(mlx_img.img, &mlx_img.bits_per_pixel, &mlx_img.line_length, &mlx_img.endian);

//my_mlx_pixel_put(&mlx_img, x_start + x*x_screen, y_start + y*y_screen, 0x0000FA9A);
    
    // int previous_x = x_start + x*x_screen;
    // int previous_y = y_start + y*y_screen;
    // int m = (previous_x - previous_y) * cos(0.523599);
    // int n = -map42[y][x] + (previous_x + previous_y) * sin(0.523599);
    // my_mlx_pixel_put(&mlx_img, m, n, 0x0000FA9A);



while (x < 19)
{
    y_screen = x + 100;
    while (y < 11)
    {
        x_screen = y + 100;
        if (map42[y][x] == 10)
            my_mlx_pixel_put(&mlx_img, y_screen + x*15, x_screen + y*15, 0x00E1AD01);
        // if (map42[y][x] == 0)
            // my_mlx_pixel_put(&mlx_img, y_screen + x*15, x_screen + y*15, 0x0077B5EF);
        y++;
    }
    x++;
    y = 0;
}
mlx_put_image_to_window(mlx_ptr, mlx_win, mlx_img.img, 0, 0);
mlx_loop(mlx_ptr);
}
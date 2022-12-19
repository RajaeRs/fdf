
// cc -I /usr/local/include test.c -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit --> to compile
#include <mlx.h>

int main()
{
    void *mlx_ptr;
    void *win_ptr;
    char *titel;
    int all;
    int color1;
    int color2;
    int helf;
    int x;
    int y;


    helf = 100;
    x = 200;
    y = 200;
    color1 = 0x00FFF012;
    color2 = 0x00FF3FFF;
    titel = "my first window";
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, titel);
    all = mlx_string_put(mlx_ptr, win_ptr, 560, 450, color1, "hello world ...");
    all = mlx_string_put(mlx_ptr, win_ptr, 560, 480, color1, "my name is rajae");
    while (helf)
    {
        all = mlx_pixel_put(mlx_ptr, win_ptr, x, y, color2);
        y = y + 1;
        helf = helf - 1;
    }  
    helf = 100;
    y = y - 100;
    x = x + 100;
    while (helf)
    {
        all = mlx_pixel_put(mlx_ptr, win_ptr, x, y, color2);
        y = y + 1;
        helf = helf - 1;
    }
    helf = 100;
    x = x - 100;
    while (helf)
    {
        all = mlx_pixel_put(mlx_ptr, win_ptr, x, y, color2);
        x = x + 1;
        helf = helf - 1;
    } 
    helf = 100;
    y =  y - 100;
    x = x - 100;
    while (helf)
    {
        all = mlx_pixel_put(mlx_ptr, win_ptr, x, y, color2);
        x = x + 1;
        helf = helf - 1;
    }
    // second -----------------
    x = x + 200;
    // y = y + 100;
    helf = 100;
    while (helf)
    {
        all = mlx_pixel_put(mlx_ptr, win_ptr, x, y, color2);
        y = y + 1;
        helf = helf - 1;
    }  
    helf = 100;
    y = y - 100;
    x = x + 100;
    while (helf)
    {
        all = mlx_pixel_put(mlx_ptr, win_ptr, x, y, color2);
        y = y + 1;
        helf = helf - 1;
    }
    helf = 100;
    x = x - 100;
    while (helf)
    {
        all = mlx_pixel_put(mlx_ptr, win_ptr, x, y, color2); 
        x = x + 1;
        helf = helf - 1;
    } 
    helf = 100;
    y =  y - 100;
    x = x - 100;
    while (helf)
    {
        all = mlx_pixel_put(mlx_ptr, win_ptr, x, y, color2); 
        x = x + 1;
        helf = helf - 1;
    }
    y += 300;
    x -= 300;
    helf = 200;
    while (helf)
    {
        all = mlx_pixel_put(mlx_ptr, win_ptr, x, y, color2); 
        x = x + 1;
        helf = helf - 1;
    }
    mlx_loop(mlx_ptr);
}

    // int map42[11][19] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    //                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    //                     {0, 0, 10, 10, 0, 0, 10, 10, 0, 0, 0, 10, 10, 10, 10, 10, 0, 0, 0},
    //                     {0, 0, 10, 10, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0, 0, 10, 10, 0, 0},
    //                     {0, 0, 10, 10, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0, 0, 10, 10, 0, 0},
    //                     {0, 0, 10, 10, 10, 10, 10, 10, 0, 0, 0, 0, 10, 10, 10, 10, 0, 0, 0},
    //                     {0, 0, 0, 10, 10, 10, 10, 10, 0, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0},
    //                     {0, 0, 0, 0, 0, 0, 10, 10, 0, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0},
    //                     {0, 0, 0, 0, 0, 0, 10, 10, 0, 0, 0, 10, 10, 10, 10, 10, 10, 0, 0},
    //                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    //                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
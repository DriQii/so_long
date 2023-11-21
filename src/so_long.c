
//#include "../minilibx-linux/mlx_int.h"
#include "../minilibx-linux/mlx.h"
#include <stdio.h>

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

int main(void)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;
    int     i;
    int     x;
    int     y;
    int j;

    j = 0;
    x = 800;
    y = 800;
    i = 0;
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "So long");
    img.img = mlx_new_image(mlx, 1980, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    //my_mlx_pixel_put(&img, 5, 5, 0x00FFFF00);

    while (j < 13)   
    {   
        my_mlx_pixel_put(&img, x, y, 0x00F1C284);
        x++;
        j++;
    }
    x -= j;
    j = 0;
    y++;
    while (j < 5)   
    {   
        my_mlx_pixel_put(&img, x, y, 0x00C97E4F);
        x++;
        j++;
    }
    my_mlx_pixel_put(&img, x, y, 0x00F1C284);
    x++;
    j++;
    while (j < 12)   
    {   
        my_mlx_pixel_put(&img, x, y, 0x0F1F0EE);
        x++;
        j++;
    }

    x -= j;
    j = 0;
    y++;

    
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

//#include "../minilibx-linux/mlx_int.h"
#include "../minilibx-linux/mlx.h"
#include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*relative_path;
    int		img_width;
    int		img_height;
}				t_data;

int main(void)
{
    void    *mlx;
    void    *mlx_win;
    t_data  sasuke;
    t_data  naruto;
    t_data  grass;

    sasuke.relative_path = "images/char/sasuke_front.xpm";
    naruto.relative_path = "images/char/naruto_front.xpm";
    grass.relative_path = "images/char/grass.xpm";
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "So long");
    sasuke.img = mlx_xpm_file_to_image(mlx, sasuke.relative_path, &sasuke.img_width, &sasuke.img_height);
    naruto.img = mlx_xpm_file_to_image(mlx, naruto.relative_path, &naruto.img_width, &naruto.img_height);
    grass.img = mlx_xpm_file_to_image(mlx, grass.relative_path, &grass.img_width, &grass.img_height);
    mlx_put_image_to_window(mlx, mlx_win, sasuke.img, 500, 500);
    mlx_put_image_to_window(mlx, mlx_win, grass.img, 801, 801);
    mlx_put_image_to_window(mlx, mlx_win, naruto.img, 800, 800);

	mlx_loop(mlx);
}

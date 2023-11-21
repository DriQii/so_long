
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
    t_data  img;

    img.relative_path = "images/test.xpm";
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "So long");
    img.img = mlx_xpm_file_to_image(mlx, img.relative_path, &img.img_width, &img.img_height);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 500, 500);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 800, 800);
	mlx_loop(mlx);
}

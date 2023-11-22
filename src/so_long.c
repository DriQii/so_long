
#include "../include/so_long.h"

t_data    ft_get_image_transparance(void *mlx, t_data bg, char *path)
{
    int i;
    int j;
    t_data  c;

    j = 0;
    i = 0;
    c.img = mlx_xpm_file_to_image(mlx, path, &c.img_width, &c.img_height);
    c.addr = mlx_get_data_addr(c.img, &c.bits_per_pixel, &c.line_length, &c.endian);
    while(i < (c.line_length / 4))
    {
        while (j <= (c.line_length / 4))
        {
            if(c.addr[(i * c.line_length) + (j * (c.bits_per_pixel / 8))] == 0)
            {
                c.addr[(i * c.line_length) + (j * (c.bits_per_pixel / 8))] = 
                bg.addr[(i * c.line_length) + (j * (c.bits_per_pixel / 8))]; 
                c.addr[(i * c.line_length) + (j * (c.bits_per_pixel / 8)) + 1] = 
                bg.addr[(i * c.line_length) + (j * (c.bits_per_pixel / 8)) + 1];
                c.addr[(i * c.line_length) + (j * (c.bits_per_pixel / 8)) + 2] = 
                bg.addr[(i * c.line_length) + (j * (c.bits_per_pixel / 8)) + 2];
            }
            j++;
        }
        j = 0;
        i++;
    }
    return(c);
}

int	ft_hook(int keycode, t_win *win)
{
    printf("%d\n", keycode);
	if(keycode == 119)
    {   
        mlx_put_image_to_window(win->mlx, win->mlx_win, win->grass.img, win->sasuke.x, win->sasuke.y);
        win->sasuke.y -= 65;
        mlx_put_image_to_window(win->mlx, win->mlx_win, win->sasuke.img, win->sasuke.x, win->sasuke.y);   
    }
    else if (keycode == 97)
    {
        mlx_put_image_to_window(win->mlx, win->mlx_win, win->grass.img, win->sasuke.x, win->sasuke.y);
        win->sasuke.x -= 65;
        mlx_put_image_to_window(win->mlx, win->mlx_win, win->sasuke.img, win->sasuke.x, win->sasuke.y);
    }
    else if (keycode == 115)
    {
        mlx_put_image_to_window(win->mlx, win->mlx_win, win->grass.img, win->sasuke.x, win->sasuke.y);
        win->sasuke.y += 65;
        mlx_put_image_to_window(win->mlx, win->mlx_win, win->sasuke.img, win->sasuke.x, win->sasuke.y);
    }
    else if (keycode == 100)
    {
        mlx_put_image_to_window(win->mlx, win->mlx_win, win->grass.img, win->sasuke.x, win->sasuke.y);
        win->sasuke.x += 65;
        mlx_put_image_to_window(win->mlx, win->mlx_win, win->sasuke.img, win->sasuke.x, win->sasuke.y);
    }
	return (0);
}

void    ft_put_bg(t_win win, int x, int y , int img_size)
{   
    t_index i;

    i.j = 0;
    i.x = 0;
    i.y = 0;
    i.i = 0;
    while(i.i <= (x / img_size))
    {
        while(i.j <= (y / img_size))
        {
            mlx_put_image_to_window(win.mlx, win.mlx_win, win.grass.img, i.x, i.y);
            i.y += 65;
            i.j++;
        }
        i.y -= i.y;
        i.j = 0;       
        i.x += img_size;
        i.i++;
    }
}
int main(void)
{
    t_win win;

    win.grass.relative_path = "images/char/grass.xpm";
    win.mlx = mlx_init();
    win.mlx_win = mlx_new_window(win.mlx, 1920, 1080, "So long");
    win.grass.img = mlx_xpm_file_to_image(win.mlx, win.grass.relative_path,
    &win.grass.img_width, &win.grass.img_height);
    win.grass.addr = mlx_get_data_addr(win.grass.img, &win.grass.bits_per_pixel,
    &win.grass.line_length, &win.grass.endian);
    ft_put_bg(win, 1920, 1080, 65);
    
    win.sasuke = ft_get_image_transparance(win.mlx, win.grass, "images/char/sasuke_front.xpm");
    win.sasuke.x = 500;
    win.sasuke.y = 500;
    mlx_put_image_to_window(win.mlx, win.mlx_win, win.sasuke.img, win.sasuke.x, win.sasuke.y);
    mlx_key_hook(win.mlx_win, ft_hook, &win);

	mlx_loop(win.mlx);
}

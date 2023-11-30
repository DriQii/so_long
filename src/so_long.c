
#include "../include/so_long.h"
#include "../include/libft.h"

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

int main(int argc, char **argv)
{
    int fd;
    char **map;
    (void)argc;
    int i;

    i = 0;
    fd = open(argv[1], O_RDONLY);
    map = ft_get_map(fd);
    while(map[i])
    {
        ft_printf("%s", map[i]);
        i++;
    }
    ft_map_verif(map);
    ft_freetabtabb(i, map);
}

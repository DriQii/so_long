/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:10:28 by evella            #+#    #+#             */
/*   Updated: 2023/12/12 16:33:54 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/libft.h"

void ft_tabtablen(t_win *win)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while(win->map[i])
	{
		j = 0;
		while(win->map[i][j])
			j++;
		i++;
	}
	win->y = i;
	win->x = j - 1;
}
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
            if((c.addr[(i * c.line_length) + (j * (c.bits_per_pixel / 8))] == 0)
			&& (c.addr[(i * c.line_length) + (j * (c.bits_per_pixel / 8)) + 1] == 0)
			&& (c.addr[(i * c.line_length) + (j * (c.bits_per_pixel / 8)) + 2] == 0))
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
int ft_print_character(t_win *win, void *img, char c)
{
	t_index i;

	i.y = 0;
	i.x = 0;
	while (i.y < win->y)
	{
		while(i.x < win->x)
		{
			if (c == '0')
				mlx_put_image_to_window(win->mlx, win->mlx_win, img, i.x * 64, i.y * 64);
			else if (win->map[i.y][i.x] == c)
				mlx_put_image_to_window(win->mlx, win->mlx_win, img, i.x * 64, i.y * 64);
			i.x++;
		}
		i.x = 0;
		i.y++;
	}
	return(0);
}
t_coords *ft_get_coords(char **map, int c)
{
	t_index		i;
	t_coords	*coords;

	i.y = 0;
	i.x = 0;
	while (map[i.y])
	{
		while (map[i.y][i.x] && map[i.y][i.x] != '\n')
		{
			if(map[i.y][i.x] == c)
				coords = ft_newlstcoords(i.x, i.y, coords);
			i.x++;
		}
		i.x = 0;
		i.y++;
	}
	return(coords);
}
void ft_char_init(t_win *win)
{
	win->bg.img = mlx_xpm_file_to_image(win->mlx, "images/char/backgroud.xpm",
	&win->bg.img_width, &win->bg.img_height);
	win->bg.addr = mlx_get_data_addr(win->bg.img, &win->bg.bits_per_pixel,
	&win->bg.line_length, &win->bg.endian);
	win->obstacle =	ft_get_image_transparance(win->mlx, win->bg, "images/char/obstacle.xpm");
	win->kakashi.front = ft_get_image_transparance(win->mlx, win->bg, "images/char/kakashi_front.xpm");
	win->kakashi.frontW = ft_get_image_transparance(win->mlx, win->bg, "images/char/kakashi_front_walk.xpm");
	win->kakashi.frontW2 = ft_get_image_transparance(win->mlx, win->bg, "images/char/kakashi_front_walk2.xpm");
	win->kakashi.back = ft_get_image_transparance(win->mlx, win->bg, "images/char/kakashi_back.xpm");
	win->kakashi.backW = ft_get_image_transparance(win->mlx, win->bg, "images/char/kakashi_back_walk.xpm");
	win->kakashi.backW2 = ft_get_image_transparance(win->mlx, win->bg, "images/char/kakashi_back_walk2.xpm");
	win->kakashi.left= ft_get_image_transparance(win->mlx, win->bg, "images/char/kakashi_left.xpm");
	win->kakashi.leftW = ft_get_image_transparance(win->mlx, win->bg, "images/char/kakashi_left_walk.xpm");
	win->kakashi.leftW2 = ft_get_image_transparance(win->mlx, win->bg, "images/char/kakashi_left_walk2.xpm");
	win->kakashi.right = ft_get_image_transparance(win->mlx, win->bg, "images/char/kakashi_right.xpm");
	win->kakashi.rightW = ft_get_image_transparance(win->mlx, win->bg, "images/char/kakashi_right_walk.xpm");
	win->kakashi.rightW2 = ft_get_image_transparance(win->mlx, win->bg, "images/char/kakashi_right_walk2.xpm");
	win->naruto.front = ft_get_image_transparance(win->mlx, win->bg, "images/char/Naruto_front.xpm");
	win->naruto.backW = ft_get_image_transparance(win->mlx, win->bg, "images/char/Naruto_hand.xpm");
	win->naruto.frontW = ft_get_image_transparance(win->mlx, win->bg, "images/char/Naruto_hand2.xpm");
	win->naruto.frontW2 = ft_get_image_transparance(win->mlx, win->bg, "images/char/Naruto_hand3.xpm");
	win->naruto.back = ft_get_image_transparance(win->mlx, win->bg, "images/char/Sexy_jutsu.xpm");
	win->escape = ft_get_image_transparance(win->mlx, win->bg, "images/char/escape.xpm");
}
void ft_win_init(t_win *win)
{
	t_index i;
	t_coords *k;

	i.y = 0;
	i.x = 0;
	ft_tabtablen(win);
	win->mlx = mlx_init();
	win->mlx_win = mlx_new_window(win->mlx, win->x * 64, win->y * 64, "so long");
	ft_char_init(win);
	ft_print_character(win, win->bg.img, '0');
	ft_print_character(win, win->obstacle.img, '1');
	ft_print_character(win, win->kakashi.front.img, 'P');
	ft_print_character(win, win->naruto.front.img, 'C');
	ft_print_character(win, win->escape.img, 'E');
	k = ft_get_coords(win->map, 'P');
	win->kakashi.x = k->x * 64;
	win->kakashi.y = k->y * 64;
	win->anim_count = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:10:28 by evella            #+#    #+#             */
/*   Updated: 2024/01/08 12:41:34 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void ft_player_init(t_win *win)
{
	win->player.front.still = ft_get_image_transparance(win->mlx, win->bg, "images/char/kakashi_front.xpm");
	win->player.front.walk = ft_get_image_transparance(win->mlx, win->bg, "images/char/kakashi_front_walk.xpm");
	win->player.front.walk2 = ft_get_image_transparance(win->mlx, win->bg, "images/char/kakashi_front_walk2.xpm");
	win->player.front.fight = ft_get_image_transparance(win->mlx, win->bg, "images/char/kakashi_front_fight.xpm");
	win->player.front.fight2 = ft_get_image_transparance(win->mlx, win->bg, "images/char/kakashi_front_fight2.xpm");
	win->player.front.fight3 = ft_get_image_transparance(win->mlx, win->bg, "images/char/kakashi_front_fight3.xpm");
	win->player.back.still = ft_get_image_transparance(win->mlx, win->bg, "images/char/kakashi_back.xpm");
	win->player.back.walk = ft_get_image_transparance(win->mlx, win->bg, "images/char/kakashi_back_walk.xpm");
	win->player.back.walk2 = ft_get_image_transparance(win->mlx, win->bg, "images/char/kakashi_back_walk2.xpm");
	win->player.back.fight = ft_get_image_transparance(win->mlx, win->bg, "images/char/kakashi_back_fight.xpm");
	win->player.back.fight2 = ft_get_image_transparance(win->mlx, win->bg, "images/char/kakashi_back_fight2.xpm");
	win->player.back.fight3 = ft_get_image_transparance(win->mlx, win->bg, "images/char/kakashi_back_fight3.xpm");
	win->player.left.still= ft_get_image_transparance(win->mlx, win->bg, "images/char/kakashi_left.xpm");
	win->player.left.walk = ft_get_image_transparance(win->mlx, win->bg, "images/char/kakashi_left_walk.xpm");
	win->player.left.walk2 = ft_get_image_transparance(win->mlx, win->bg, "images/char/kakashi_left_walk2.xpm");
	win->player.left.fight= ft_get_image_transparance(win->mlx, win->bg, "images/char/kakashi_left_fight.xpm");
	win->player.left.fight2 = ft_get_image_transparance(win->mlx, win->bg, "images/char/kakashi_left_fight2.xpm");
	win->player.left.fight3 = ft_get_image_transparance(win->mlx, win->bg, "images/char/kakashi_left_fight3.xpm");
	win->player.right.still = ft_get_image_transparance(win->mlx, win->bg, "images/char/kakashi_right.xpm");
	win->player.right.walk = ft_get_image_transparance(win->mlx, win->bg, "images/char/kakashi_right_walk.xpm");
	win->player.right.walk2 = ft_get_image_transparance(win->mlx, win->bg, "images/char/kakashi_right_walk2.xpm");
	win->player.right.fight = ft_get_image_transparance(win->mlx, win->bg, "images/char/kakashi_right_fight.xpm");
	win->player.right.fight2 = ft_get_image_transparance(win->mlx, win->bg, "images/char/kakashi_right_fight2.xpm");
	win->player.right.fight3 = ft_get_image_transparance(win->mlx, win->bg, "images/char/kakashi_right_fight3.xpm");
}
static void ft_ennemies_init(t_win *win)
{
	win->ennemies.frame1 = ft_get_image_transparance(win->mlx, win->bg, "images/char/naruto_front.xpm");
	win->ennemies.frame2 = ft_get_image_transparance(win->mlx, win->bg, "images/char/Naruto_hand.xpm");
	win->ennemies.frame3 = ft_get_image_transparance(win->mlx, win->bg, "images/char/Naruto_hand2.xpm");
	win->ennemies.frame4 = ft_get_image_transparance(win->mlx, win->bg, "images/char/Naruto_hand3.xpm");
	win->ennemies.frame5 = ft_get_image_transparance(win->mlx, win->bg, "images/char/Sexy_jutsu.xpm");
	win->ennemies.dead = ft_get_image_transparance(win->mlx, win->bg, "images/char/naruto_dead.xpm");
	win->ennemies.dead2 = ft_get_image_transparance(win->mlx, win->bg, "images/char/naruto_dead2.xpm");
	win->ennemies.dead3 = ft_get_image_transparance(win->mlx, win->bg, "images/char/naruto_dead3.xpm");
}

static void ft_img_init(t_win *win)
{
	win->bg.img = mlx_xpm_file_to_image(win->mlx, "images/char/backgroud.xpm",
	&win->bg.img_width, &win->bg.img_height);
	win->bg.addr = mlx_get_data_addr(win->bg.img, &win->bg.bits_per_pixel,
	&win->bg.line_length, &win->bg.endian);
	win->obstacle =	ft_get_image_transparance(win->mlx, win->bg, "images/char/obstacle.xpm");
	win->escape = ft_get_image_transparance(win->mlx, win->bg, "images/char/escape.xpm");
	win->collectible = ft_get_image_transparance(win->mlx, win->bg, "images/char/collectible.xpm");
	ft_player_init(win);
	ft_ennemies_init(win);
}

char	**ft_add_moove_map(char **map, t_win *win)
{
	t_index	i;
	char **newmap;

	i.i = 0;
	i.l = ft_strlen(map[0]);
	newmap = ft_calloc(sizeof(char *), win->y + 2);
	newmap[0] = ft_calloc(sizeof(char), i.l + 1);
	ft_memset(newmap[0], 'M', i.l - 1);
	newmap[0][i.l - 1] = '\n';
	while(map[i.i])
	{
		newmap[i.i + 1] = ft_strdup(map[i.i]);
		i.i++;
	}
	ft_freetabtabb(win->y, map);
	return (newmap);
}

void ft_win_init(t_win *win)
{
	t_coords *k;

	//win->y++;
	//win->map = ft_add_moove_map(win->map, win);
	win->mlx = mlx_init();
	win->mlx_win = mlx_new_window(win->mlx, win->x * 64, win->y * 64, "so long");
	ft_img_init(win);
	ft_print_character(win, win->bg.img, '0');
	ft_print_character(win, win->obstacle.img, '1');
	ft_print_character(win, win->player.front.still.img, 'P');
	ft_print_character(win, win->ennemies.frame1.img, 'N');
	ft_print_character(win, win->escape.img, 'E');
	ft_print_character(win, win->collectible.img, 'C');
	k = ft_get_coords(win->map, 'P');
	win->player.x = k->x * 64;
	win->player.y = k->y * 64;
	win->anim_count = 0;
	win->keycode = 1;
	win->ennemies.state = 0;
	win->ennemies.x = 0;
	win->ennemies.y = 0;
	win->loop = 0;
	win->moove = 0;
	free(k->next);
	free(k);
}

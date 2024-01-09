/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:10:28 by evella            #+#    #+#             */
/*   Updated: 2024/01/09 20:15:53 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/so_long.h"

void	ft_swap_px(t_data bg, t_data *c, int i, int j)
{
	c->addr[(i * c->line_length) + (j * (c->bits_per_pixel / 8))]
		= bg.addr[(i * c->line_length) \
		+ (j * (c->bits_per_pixel / 8))];
	c->addr[(i * c->line_length) + (j * (c->bits_per_pixel / 8)) + 1]
		= bg.addr[(i * c->line_length) \
		+ (j * (c->bits_per_pixel / 8)) + 1];
	c->addr[(i * c->line_length) + (j * (c->bits_per_pixel / 8)) + 2]
		= bg.addr[(i * c->line_length) \
		+ (j * (c->bits_per_pixel / 8)) + 2];
}

t_data	ft_get_image_transparance(void *mlx, t_data bg, char *path)
{
	int		i;
	int		j;
	t_data	c;

	j = -1;
	i = -1;
	c.img = mlx_xpm_file_to_image(mlx, path, &c.img_width, &c.img_height);
	c.addr = mlx_get_data_addr(c.img, &c.bits_per_pixel, &c.line_length,
			&c.endian);
	while (++i < (c.line_length / 4))
	{
		while (++j <= (c.line_length / 4))
		{
			if ((c.addr[(i * c.line_length) \
				+ (j * (c.bits_per_pixel / 8))] == 0) \
				&& (c.addr[(i * c.line_length) \
				+ (j * (c.bits_per_pixel / 8)) + 1] == 0) \
				&& (c.addr[(i * c.line_length) \
				+ (j * (c.bits_per_pixel / 8)) + 2] == 0))
				ft_swap_px(bg, &c, i, j);
		}
		j = -1;
	}
	return (c);
}

static void	ft_img_init(t_win *win)
{
	win->bg.img = mlx_xpm_file_to_image(win->mlx, "images/char/backgroud.xpm",
			&win->bg.img_width, &win->bg.img_height);
	win->bg.addr = mlx_get_data_addr(win->bg.img, &win->bg.bits_per_pixel,
			&win->bg.line_length, &win->bg.endian);
	win->obstacle = ft_get_image_transparance(win->mlx, win->bg,
			"images/char/obstacle.xpm");
	win->escape = ft_get_image_transparance(win->mlx, win->bg,
			"images/char/escape.xpm");
	win->collectible = ft_get_image_transparance(win->mlx, win->bg,
			"images/char/collectible.xpm");
	ft_player_init(win);
	ft_ennemies_init(win);
}

void	ft_win_init(t_win *win)
{
	t_coords	*k;

	win->mlx = mlx_init();
	win->mlx_win = mlx_new_window(win->mlx, win->x * 64, win->y * 64,
			"so long");
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

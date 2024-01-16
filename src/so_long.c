/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:42:03 by evella            #+#    #+#             */
/*   Updated: 2024/01/16 10:43:37 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/so_long.h"

void	ft_freecoords(t_coords *coords)
{
	t_coords	*tmp;

	while (coords)
	{
		tmp = coords;
		coords = coords->next;
		free(tmp);
	}
}

int	ft_print_character(t_win *win, void *img, char c)
{
	t_index	i;

	i.y = 0;
	i.x = 0;
	while (i.y < win->y)
	{
		while (i.x < win->x)
		{
			if (c == '0')
				mlx_put_image_to_window(win->mlx, win->mlx_win, img, i.x * 64,
					i.y * 64);
			else if (win->map[i.y][i.x] == c)
				mlx_put_image_to_window(win->mlx, win->mlx_win, img, i.x * 64,
					i.y * 64);
			i.x++;
		}
		i.x = 0;
		i.y++;
	}
	return (0);
}

static int	ft_check_format(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] != 'r' || str[i - 2] != 'e'
		|| str[i - 3] != 'b' || str[i - 4] != '.')
	{
		ft_printf("the map file must be in .ber format\n");
		return (1);
	}
	return (0);
}

int	ft_hook_close_game(t_win *win)
{
	mlx_destroy_window(win->mlx, win->mlx_win);
	ft_destroy_anim(win, win->player.front);
	ft_destroy_anim(win, win->player.back);
	ft_destroy_anim(win, win->player.right);
	ft_destroy_anim(win, win->player.left);
	ft_destroy_ennemies(win);
	mlx_destroy_image(win->mlx, win->bg.img);
	mlx_destroy_image(win->mlx, win->obstacle.img);
	mlx_destroy_image(win->mlx, win->collectible.img);
	mlx_destroy_image(win->mlx, win->escape.img);
	ft_freetabtabb(win->y, win->map);
	mlx_destroy_display(win->mlx);
	free(win->mlx);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_win	win;

	if (ft_check_format(argv[1]))
		return (1);
	if (argc != 2)
		return (perror("Error\nPlease give only one map as argument\n"), 1);
	win.map = ft_map_verif(argv[1], &win);
	if (!win.map)
		return (1);
	ft_win_init(&win);
	mlx_key_hook(win.mlx_win, ft_hook, &win);
	if (mlx_loop_hook(win.mlx, ft_loop_hook, &win) == 1)
		return (0);
	mlx_hook(win.mlx_win, 17, 0, ft_hook_close_game, &win);
	mlx_loop(win.mlx);
	return (0);
}

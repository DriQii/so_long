/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:42:03 by evella            #+#    #+#             */
/*   Updated: 2023/12/20 00:25:47 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/so_long.h"

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

int	main(int argc, char **argv)
{
	t_win	win;

	if (argc != 2)
		return (ft_printf("Error\nPlease give only one map as argument\n"), 1);
	win.map = ft_map_verif(argv[1], &win);
	if (!win.map)
		return (1);
	ft_win_init(&win);
	mlx_key_hook(win.mlx_win, ft_hook, &win);
	if (mlx_loop_hook(win.mlx, ft_loop_hook, &win) == 1)
		return (0);
	mlx_loop(win.mlx);
	return (0);
}

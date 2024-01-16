/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:53:06 by evella            #+#    #+#             */
/*   Updated: 2024/01/16 16:09:50 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/so_long.h"

void	ft_print_moove(t_win *win)
{
	char	*tmp;
	char	*str;
	char	*strmoove;

	tmp = ft_itoa(win->moove);
	str = ft_strdup("Number of moove : ");
	strmoove = ft_strjoin(str, tmp);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->bg.img, 0, 0);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->bg.img, 64, 0);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->bg.img, 128, 0);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->obstacle.img, 0,
		0);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->obstacle.img, 64,
		0);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->obstacle.img, 128,
		0);
	mlx_string_put(win->mlx, win->mlx_win, 10, 10, 0x00000000, strmoove);
	free(strmoove);
	free(str);
	free(tmp);
}

t_index	ft_test(t_win *win)
{
	t_index	i;

	i.y = 0;
	i.x = 0;
	if (win->keycode == 13 || win->keycode == 126)
		i.y -= 1;
	else if (win->keycode == 0 || win->keycode == 123)
		i.x -= 1;
	else if (win->keycode == 1 || win->keycode == 125)
		i.y += 1;
	else if (win->keycode == 2 || win->keycode == 124)
		i.x += 1;
	return (i);
}

int	ft_check_moove(t_win *win)
{
	t_index	i;

	i = ft_test(win);
	if (win->map[win->player.y / 64 + i.y][win->player.x / 64 + i.x] == '0'
		|| win->map[win->player.y / 64 + i.y][win->player.x / 64 + i.x] == 'N'
		|| win->map[win->player.y / 64 + i.y][win->player.x / 64 + i.x] == 'C'
		|| (win->map[win->player.y / 64 + i.y][win->player.x / 64
			+ i.x] == 'E' && win->c_count == 0) || win->map[win->player.y / 64
		+ i.y][win->player.x / 64 + i.x] == 'P')
	{
		win->moove++;
		ft_print_moove(win);
		if (win->map[win->player.y / 64 + i.y][win->player.x / 64 + i.x] == 'N')
			ft_close_game(win, "You loose !!!!!");
		if (win->map[win->player.y / 64 + i.y][win->player.x / 64
			+ i.x] == 'C')
		{
			win->c_count--;
			win->map[win->player.y / 64 + i.y][win->player.x / 64
				+ i.x] = '0';
		}
		win->player.y += i.y * 64;
		win->player.x += i.x * 64;
	}
	return (0);
}

int	ft_hook(int keycode, t_win *win)
{
	if (keycode == 65307)
		ft_close_game(win, "");
	else if (keycode == 32)
		return (ft_put_fight_anim(win), 1);
	else if (keycode == 119 || keycode == 65362)
		win->keycode = 13;
	else if (keycode == 97 || keycode == 65361)
		win->keycode = 0;
	else if (keycode == 115 || keycode == 65364)
		win->keycode = 1;
	else if (keycode == 100 || keycode == 65363)
		win->keycode = 2;
	if (win->keycode == 13 || win->keycode == 0 || win->keycode == 1
		|| win->keycode == 2)
	{
		ft_put_walkanim(win);
		if (win->map[win->player.y / 64][win->player.x / 64] == 'E')
			ft_close_game(win, "GG You just won the game !!!!!");
	}
	return (1);
}

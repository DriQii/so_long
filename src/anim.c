/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:38:30 by evella            #+#    #+#             */
/*   Updated: 2024/01/12 15:18:24 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/so_long.h"

static void	ft_walkanim(t_win *win, t_anim anim)
{
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->bg.img, win->player.x,
		win->player.y);
	mlx_put_image_to_window(win->mlx, win->mlx_win, anim.walk.img,
		win->player.x, win->player.y);
	mlx_do_sync(win->mlx);
	usleep(20000);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->bg.img, win->player.x,
		win->player.y);
	ft_check_moove(win);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->bg.img, win->player.x,
		win->player.y);
	mlx_put_image_to_window(win->mlx, win->mlx_win, anim.walk.img,
		win->player.x, win->player.y);
	mlx_do_sync(win->mlx);
	usleep(10000);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->bg.img, win->player.x,
		win->player.y);
	mlx_put_image_to_window(win->mlx, win->mlx_win, anim.walk2.img,
		win->player.x, win->player.y);
	mlx_do_sync(win->mlx);
	usleep(60000);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->bg.img, win->player.x,
		win->player.y);
	mlx_put_image_to_window(win->mlx, win->mlx_win, anim.still.img,
		win->player.x, win->player.y);
}

static void	ft_deadanim(t_win *win)
{
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->bg.img,
		win->ennemies.x, win->ennemies.y);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->ennemies.dead.img,
		win->ennemies.x, win->ennemies.y);
	mlx_do_sync(win->mlx);
	usleep(200000);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->bg.img,
		win->ennemies.x, win->ennemies.y);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->ennemies.dead2.img,
		win->ennemies.x, win->ennemies.y);
	mlx_do_sync(win->mlx);
	usleep(100000);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->bg.img,
		win->ennemies.x, win->ennemies.y);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->ennemies.dead3.img,
		win->ennemies.x, win->ennemies.y);
	mlx_do_sync(win->mlx);
	usleep(300000);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->bg.img,
		win->ennemies.x, win->ennemies.y);
}

void	ft_put_walkanim(t_win *win)
{
	if (win->keycode == 13 || win->keycode == 126)
		ft_walkanim(win, win->player.back);
	if (win->keycode == 0 || win->keycode == 123)
		ft_walkanim(win, win->player.left);
	if (win->keycode == 1 || win->keycode == 125)
		ft_walkanim(win, win->player.front);
	if (win->keycode == 2 || win->keycode == 124)
		ft_walkanim(win, win->player.right);
}

void	ft_put_deadanim(t_win *win)
{
	if (win->keycode == 13 || win->keycode == 126)
	{
		win->ennemies.x = win->player.x;
		win->ennemies.y = win->player.y - 64;
	}
	else if (win->keycode == 0 || win->keycode == 123)
	{
		win->ennemies.x = win->player.x - 64;
		win->ennemies.y = win->player.y;
	}
	else if (win->keycode == 1 || win->keycode == 125)
	{
		win->ennemies.x = win->player.x;
		win->ennemies.y = win->player.y + 64;
	}
	else if (win->keycode == 2 || win->keycode == 124)
	{
		win->ennemies.x = win->player.x + 64;
		win->ennemies.y = win->player.y;
	}
	win->map[win->ennemies.y / 64][win->ennemies.x / 64] = '0';
	ft_deadanim(win);
}

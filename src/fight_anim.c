/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fight_anim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:38:33 by evella            #+#    #+#             */
/*   Updated: 2024/01/10 21:32:01 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/so_long.h"

static int	ft_check_ennemies(t_win *win)
{
	if (win->map[win->player.y / 64 - 1][win->player.x / 64] == 'N')
	{
		win->keycode = 13;
		return (1);
	}
	else if (win->map[win->player.y / 64][win->player.x / 64 - 1] == 'N')
	{
		win->keycode = 0;
		return (1);
	}
	else if (win->map[win->player.y / 64 + 1][win->player.x / 64] == 'N')
	{
		win->keycode = 1;
		return (1);
	}
	else if (win->map[win->player.y / 64][win->player.x / 64 + 1] == 'N')
	{
		win->keycode = 2;
		return (1);
	}
	return (0);
}

static void	ft_print_anim(t_win *win, t_data frame)
{
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->bg.img, win->player.x,
		win->player.y);
	mlx_put_image_to_window(win->mlx, win->mlx_win, frame.img,
		win->player.x, win->player.y);
}

static void	ft_fightanim(t_win *win, t_anim anim)
{
	ft_print_anim(win, anim.fight);
	mlx_do_sync(win->mlx);
	usleep(25000);
	ft_print_anim(win, anim.fight2);
	mlx_do_sync(win->mlx);
	usleep(50000);
	ft_print_anim(win, anim.fight3);
	mlx_do_sync(win->mlx);
	usleep(35000);
	ft_print_anim(win, anim.fight);
	mlx_do_sync(win->mlx);
	usleep(25000);
	ft_print_anim(win, anim.still);
}

void	ft_put_fight_anim(t_win *win)
{
	int	check;

	check = ft_check_ennemies(win);
	if (win->keycode == 13 || win->keycode == 126)
		ft_fightanim(win, win->player.back);
	else if (win->keycode == 0 || win->keycode == 123)
		ft_fightanim(win, win->player.left);
	else if (win->keycode == 1 || win->keycode == 125)
		ft_fightanim(win, win->player.front);
	else if (win->keycode == 2 || win->keycode == 124)
		ft_fightanim(win, win->player.right);
	if (check == 1 && win->ennemies.state == 0)
	{
		ft_put_deadanim(win);
	}
}

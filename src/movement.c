/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:53:06 by evella            #+#    #+#             */
/*   Updated: 2023/12/12 20:45:21 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/libft.h"

int	ft_check_moove(t_win *win, int keycode)
{
	int	tmpx;
	int tmpy;

	tmpy = 0;
	tmpx = 0;
	if(keycode == 13)
			tmpy -= 1;
	else if (keycode == 0)
			tmpx -= 1;
	else if (keycode == 1)
			tmpy += 1;
	else if (keycode == 2)
			tmpx += 1;
	if(win->map[win->kakashi.y / 64 + tmpy ][win->kakashi.x / 64 + tmpx] == '0'
	|| win->map[win->kakashi.y / 64 + tmpy][win->kakashi.x / 64 + tmpx] == 'C'
	|| (win->map[win->kakashi.y / 64 + tmpy][win->kakashi.x / 64 + tmpx] == 'E' && win->c_count == 0)
	|| win->map[win->kakashi.y / 64 + tmpy][win->kakashi.x / 64 + tmpx] == 'P')
	{
		if (win->map[win->kakashi.y / 64 + tmpy][win->kakashi.x / 64 + tmpx] == 'C')
			win->c_count--;
		if (win->map[win->kakashi.y / 64 + tmpy][win->kakashi.x / 64 + tmpx] == 'C')
			win->map[win->kakashi.y / 64 + tmpy][win->kakashi.x / 64 + tmpx] = '0';
		win->kakashi.y += tmpy * 64;
		win->kakashi.x += tmpx * 64;
	}
	return(keycode);
}

/* int ft_loop_hook(t_win *win)
{
	if (win->loop < 10000)
	{
		win->loop++;
		return (0);
	}
	if(win->anim_count == 0)
	{
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->kakashi.frontW.img, win->kakashi.x, win->kakashi.y);
		win->anim_count++;
	}
	else if(win->anim_count == 1)
	{
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->bg.img, win->kakashi.x, win->kakashi.y);
		ft_check_moove(win, win->keycode);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->kakashi.frontW2.img, win->kakashi.x, win->kakashi.y);
		win->anim_count = 0;
	}

	return(1);

	//mlx_put_image_to_window(win->mlx, win->mlx_win, win->kakashi.front.img, win->kakashi.x, win->kakashi.y);
} */

int ft_loop_hook(t_win *win)
{
	if (win->loop < 10000)
	{
		win->loop++;
		return (0);
	}
	win->loop = 0;
	if(win->anim_count == 0)
	{
		ft_print_character(win, win->bg.img, 'C');
		ft_print_character(win, win->naruto.front.img, 'C');
		win->anim_count++;
	}
	if(win->anim_count == 1)
	{
		ft_print_character(win, win->bg.img, 'C');
		ft_print_character(win, win->naruto.backW.img, 'C');
		win->anim_count++;
	}
	else if(win->anim_count == 2)
	{
		ft_print_character(win, win->bg.img, 'C');
		ft_print_character(win, win->naruto.frontW.img, 'C');
		win->anim_count++;
	}
	else if(win->anim_count == 3)
	{
		ft_print_character(win, win->bg.img, 'C');
		ft_print_character(win, win->naruto.frontW2.img, 'C');
		win->anim_count++;
	}
	else if(win->anim_count == 4)
	{
		ft_print_character(win, win->bg.img, 'C');
		ft_print_character(win, win->naruto.back.img, 'C');
		win->anim_count++;
	}
	else if(win->anim_count == 5)
	{
		ft_print_character(win, win->bg.img, 'C');
		ft_print_character(win, win->naruto.back.img, 'C');
		win->anim_count = 0;
	}

	return(1);

	//mlx_put_image_to_window(win->mlx, win->mlx_win, win->kakashi.front.img, win->kakashi.x, win->kakashi.y);
}
void ft_walkanim(t_win *win, t_data img, int time, int end)
{
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->bg.img, win->kakashi.x, win->kakashi.y);
	mlx_put_image_to_window(win->mlx, win->mlx_win, img.img, win->kakashi.x, win->kakashi.y);
	mlx_do_sync(win->mlx);
	usleep(time);
	if(end == 0)
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->bg.img, win->kakashi.x, win->kakashi.y);
}
/* void ft_fightanim()
{
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->bg.img, win->kakashi.x, win->kakashi.y);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->bg.img, win->kakashi.x, win->kakashi.y);

} */

void ft_put_walk_anim(t_win *win, int keycode)
{
	win->keycode = keycode;
	if(keycode == 13)
	{
		ft_walkanim(win,  win->kakashi.backW, 40000, 0);
		ft_check_moove(win, keycode);
		ft_walkanim(win, win->kakashi.backW2, 60000, 0);
		ft_walkanim(win, win->kakashi.back, 0, 1);
	}
	if(keycode == 0)
	{
		ft_walkanim(win,  win->kakashi.leftW, 40000, 0);
		ft_check_moove(win, keycode);
		ft_walkanim(win, win->kakashi.leftW2, 60000, 0);
		ft_walkanim(win, win->kakashi.left, 0, 1);
	}
	if(keycode == 1)
	{
		ft_walkanim(win,  win->kakashi.frontW, 40000, 0);
		ft_check_moove(win, keycode);
		ft_walkanim(win, win->kakashi.frontW2, 60000, 0);
		ft_walkanim(win, win->kakashi.front, 0, 1);
	}
	if(keycode == 2)
	{
		ft_walkanim(win,  win->kakashi.rightW, 40000, 0);
		ft_check_moove(win, keycode);
		ft_walkanim(win, win->kakashi.rightW2, 60000, 0);
		ft_walkanim(win, win->kakashi.right, 0, 1);
	}
}

int	ft_hook(int keycode, t_win *win)
{

	if(keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
	{
		//mlx_put_image_to_window(win->mlx, win->mlx_win, win->bg.img, win->kakashi.x, win->kakashi.y);
		ft_put_walk_anim(win, keycode);
		if(win->map[win->kakashi.y / 64][win->kakashi.x / 64] == 'E')
			{
				printf("\n\nGG You just won the game !!!!!\n\n");
				mlx_destroy_window(win->mlx, win->mlx_win);
				return(0);
			}
	}
	return (1);
}



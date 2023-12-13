/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:53:06 by evella            #+#    #+#             */
/*   Updated: 2023/12/13 14:43:04 by evella           ###   ########.fr       */
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
	if(win->map[win->player.y / 64 + tmpy ][win->player.x / 64 + tmpx] == '0'
	|| win->map[win->player.y / 64 + tmpy][win->player.x / 64 + tmpx] == 'C'
	|| (win->map[win->player.y / 64 + tmpy][win->player.x / 64 + tmpx] == 'E' && win->c_count == 0)
	|| win->map[win->player.y / 64 + tmpy][win->player.x / 64 + tmpx] == 'P')
	{
		if (win->map[win->player.y / 64 + tmpy][win->player.x / 64 + tmpx] == 'C')
			win->c_count--;
		if (win->map[win->player.y / 64 + tmpy][win->player.x / 64 + tmpx] == 'C')
			win->map[win->player.y / 64 + tmpy][win->player.x / 64 + tmpx] = '0';
		win->player.y += tmpy * 64;
		win->player.x += tmpx * 64;
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
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->player.frontW.img, win->player.x, win->player.y);
		win->anim_count++;
	}
	else if(win->anim_count == 1)
	{
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->bg.img, win->player.x, win->player.y);
		ft_check_moove(win, win->keycode);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->player.frontW2.img, win->player.x, win->player.y);
		win->anim_count = 0;
	}

	return(1);

	//mlx_put_image_to_window(win->mlx, win->mlx_win, win->player.front.img, win->player.x, win->player.y);
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
		ft_print_character(win, win->ennemies.frame1.img, 'C');
		win->anim_count++;
	}
	if(win->anim_count == 1)
	{
		ft_print_character(win, win->bg.img, 'C');
		ft_print_character(win, win->ennemies.frame2.img, 'C');
		win->anim_count++;
	}
	else if(win->anim_count == 2)
	{
		ft_print_character(win, win->bg.img, 'C');
		ft_print_character(win, win->ennemies.frame3.img, 'C');
		win->anim_count++;
	}
	else if(win->anim_count == 3)
	{
		ft_print_character(win, win->bg.img, 'C');
		ft_print_character(win, win->ennemies.frame4.img, 'C');
		win->anim_count++;
	}
	else if(win->anim_count == 4)
	{
		ft_print_character(win, win->bg.img, 'C');
		ft_print_character(win, win->ennemies.frame5.img, 'C');
		win->anim_count++;
	}
	else if(win->anim_count == 5)
	{
		ft_print_character(win, win->bg.img, 'C');
		ft_print_character(win, win->ennemies.frame5.img, 'C');
		win->anim_count = 0;
	}

	return(1);

	//mlx_put_image_to_window(win->mlx, win->mlx_win, win->player.front.img, win->player.x, win->player.y);
}
void ft_walkanim(t_win *win, t_anim anim)
{

	mlx_put_image_to_window(win->mlx, win->mlx_win, win->bg.img, win->player.x, win->player.y);
	mlx_put_image_to_window(win->mlx, win->mlx_win, anim.walk.img, win->player.x, win->player.y);
	mlx_do_sync(win->mlx);
	usleep(20000);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->bg.img, win->player.x, win->player.y);
	ft_check_moove(win, win->keycode);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->bg.img, win->player.x, win->player.y);
	mlx_put_image_to_window(win->mlx, win->mlx_win, anim.walk.img, win->player.x, win->player.y);
	mlx_do_sync(win->mlx);
	usleep(10000);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->bg.img, win->player.x, win->player.y);
	mlx_put_image_to_window(win->mlx, win->mlx_win, anim.walk2.img, win->player.x, win->player.y);
	mlx_do_sync(win->mlx);
	usleep(60000);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->bg.img, win->player.x, win->player.y);
	mlx_put_image_to_window(win->mlx, win->mlx_win, anim.still.img, win->player.x, win->player.y);
}
/* void ft_fightanim()
{
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->bg.img, win->player.x, win->player.y);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->bg.img, win->player.x, win->player.y);

} */

void ft_put_walk_anim(t_win *win, int keycode)
{
	win->keycode = keycode;
	if(keycode == 13)
	{
		ft_walkanim(win,  win->player.back);
		win->pos = 'U';
	}
	if(keycode == 0)
	{
		ft_walkanim(win,  win->player.left);
		win->pos = 'L';
	}
	if(keycode == 1)
	{
		ft_walkanim(win,  win->player.front);
		win->pos = 'D';
	}
	if(keycode == 2)
	{
		ft_walkanim(win,  win->player.right);
		win->pos = 'R';
	}
}

int	ft_hook(int keycode, t_win *win)
{

	if(keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
	{
		//mlx_put_image_to_window(win->mlx, win->mlx_win, win->bg.img, win->player.x, win->player.y);
		ft_put_walk_anim(win, keycode);
		if(win->map[win->player.y / 64][win->player.x / 64] == 'E')
			{
				printf("\n\nGG You just won the game !!!!!\n\n");
				mlx_destroy_window(win->mlx, win->mlx_win);
				return(0);
			}
	}
	//else if (keycode == 49)

	return (1);
}



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:53:06 by evella            #+#    #+#             */
/*   Updated: 2023/12/15 15:53:19 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/libft.h"

int	ft_check_moove(t_win *win)
{
	int	tmpx;
	int tmpy;

	tmpy = 0;
	tmpx = 0;
	if(win->keycode == 13 || win->keycode == 126)
			tmpy -= 1;
	else if (win->keycode == 0 || win->keycode == 123)
			tmpx -= 1;
	else if (win->keycode == 1 || win->keycode == 125)
			tmpy += 1;
	else if (win->keycode == 2 || win->keycode == 124)
			tmpx += 1;
	if(win->map[win->player.y / 64 + tmpy ][win->player.x / 64 + tmpx] == '0'
	|| win->map[win->player.y / 64 + tmpy][win->player.x / 64 + tmpx] == 'N'
	|| win->map[win->player.y / 64 + tmpy][win->player.x / 64 + tmpx] == 'C'
	|| (win->map[win->player.y / 64 + tmpy][win->player.x / 64 + tmpx] == 'E' && win->c_count == 0)
	|| win->map[win->player.y / 64 + tmpy][win->player.x / 64 + tmpx] == 'P')
	{
		if(win->map[win->player.y / 64 + tmpy ][win->player.x / 64 + tmpx] == 'N')
			ft_close_game(win, "You loose !!!!!");
		if(win->map[win->player.y / 64 + tmpy ][win->player.x / 64 + tmpx] == 'C')
		{
			win->c_count--;
			win->map[win->player.y / 64 + tmpy ][win->player.x / 64 + tmpx] = '0';
		}
		win->player.y += tmpy * 64;
		win->player.x += tmpx * 64;
		//printf("count %d",win->c_count);
	}
	return(0);
}

int	ft_hook(int keycode, t_win *win)
{
	printf("%d\n",keycode);
	if(keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2
	|| keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
	{
		win->keycode = keycode;
		ft_put_walkanim(win);
		if(win->map[win->player.y / 64][win->player.x / 64] == 'E')
			ft_close_game(win, "GG You just won the game !!!!!");
	}
	else if (keycode == 49)
		ft_put_fight_anim(win);
	return (1);
}



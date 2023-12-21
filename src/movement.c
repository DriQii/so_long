/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:53:06 by evella            #+#    #+#             */
/*   Updated: 2023/12/21 15:46:37 by evella           ###   ########.fr       */
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
		win->moove++;
		ft_printf("moove = %d\n", win->moove);
		if(win->map[win->player.y / 64 + tmpy ][win->player.x / 64 + tmpx] == 'N')
			ft_close_game(win, "You loose !!!!!");
		if(win->map[win->player.y / 64 + tmpy ][win->player.x / 64 + tmpx] == 'C')
		{
			win->c_count--;
			win->map[win->player.y / 64 + tmpy ][win->player.x / 64 + tmpx] = '0';
		}
		win->player.y += tmpy * 64;
		win->player.x += tmpx * 64;
	}
	return(0);
}

int	ft_hook(int keycode, t_win *win)
{
	if (keycode == 49 || keycode == 32)
		return(ft_put_fight_anim(win), 1);
	else if (keycode == 13 || keycode == 126 || keycode == 119 || keycode == 65362)
		win->keycode = 13;
	else if (keycode == 0 || keycode == 123 || keycode == 97 || keycode == 65361)
		win->keycode = 0;
	else if (keycode == 1 || keycode == 125 || keycode == 115 || keycode == 65364)
		win->keycode = 1;
	else if (keycode == 2 || keycode == 124 || keycode == 100 || keycode == 65363)
		win->keycode = 2;
	if(keycode == 13 || keycode == 126 || keycode == 119 || keycode == 65362
	|| keycode == 0 || keycode == 123 || keycode == 97 || keycode == 65361
	|| keycode == 1 || keycode == 125 || keycode == 115 || keycode == 65364
	|| keycode == 2 || keycode == 124 || keycode == 100 || keycode == 65363)
	{
		ft_put_walkanim(win);
		if(win->map[win->player.y / 64][win->player.x / 64] == 'E')
			ft_close_game(win, "GG You just won the game !!!!!");
	}
	return (1);
}



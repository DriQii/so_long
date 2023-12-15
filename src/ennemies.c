/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemies.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:21:34 by evella            #+#    #+#             */
/*   Updated: 2023/12/15 15:24:43 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/libft.h"

int	ft_ennemies_moove(t_win *win)
{
	int tmpx;
	int tmpy;
	t_index i;

	i.y = 1;
	i.x = 1;
	tmpx = 0;
	tmpy = 0;
	while(win->map[i.y])
	{
		while(win->map[i.y][i.x])
		{
			if(win->map[i.y][i.x] == 'N' && win->map[i.y - 1][i.x] == '0')
				tmpy -= 1;
			else if (win->map[i.y][i.x] == 'N' && win->map[i.y][i.x + 1] == '0')
				tmpx += 1;
			else if (win->map[i.y][i.x] == 'N' && win->map[i.y + 1][i.x] == '0')
				tmpy += 1;
			else if (win->map[i.y][i.x] == 'N' && win->map[i.y][i.x - 1] == '0')
				tmpx -= 1;

			if (tmpx != 0 || tmpy != 0 || tmpx == -1 || tmpy == -1)
			{
				//printf("%d, %d, %d, %d\n\n", i.y, i.x, win->player.y, win->player.x);
				//printf("char =%c\n", win->map[4][7]);
				win->map[i.y][i.x] = '0';
				win->map[i.y + tmpy][i.x + tmpx] = 'N';
				if(i.y + tmpy == win->player.y / 64 && i.x + tmpx == win->player.x / 64)
					ft_close_game(win, "You loose !!");
				mlx_put_image_to_window(win->mlx, win->mlx_win, win->bg.img, i.x * 64, i.y * 64);
				if(tmpx == 1)
					i.x++;
				if(tmpy == 1)
					i.y++;
				//printf("%d %d\n",tmpy, tmpx);
				tmpx = 0;
				tmpy = 0;
			}

			i.x++;
		}
		i.x = 0;
		i.y++;
	}
	/* ft_print_tabtab(win->map);
	printf("\n"); */
	return(win->keycode);
}

int ft_loop_hook(t_win *win)
{
	int	end;
	if (win->loop < 10000)
	{
		win->loop++;
		return (0);
	}
	win->loop = 0;

	if(win->anim_count == 0)
	{

		ft_print_character(win, win->bg.img, 'N');
		ft_print_character(win, win->ennemies.frame1.img, 'N');
		win->anim_count++;
		win->ennemies.state = 0;
	}
	if(win->anim_count == 1)
	{
		ft_print_character(win, win->bg.img, 'N');
		ft_print_character(win, win->ennemies.frame2.img, 'N');
		win->anim_count++;
	}
	else if(win->anim_count == 2)
	{
		ft_print_character(win, win->bg.img, 'N');
		ft_print_character(win, win->ennemies.frame3.img, 'N');
		win->anim_count++;
	}
	else if(win->anim_count == 3)
	{
		ft_print_character(win, win->bg.img, 'N');
		ft_print_character(win, win->ennemies.frame4.img, 'N');
		win->anim_count++;
	}
	else if(win->anim_count == 4)
	{
		ft_print_character(win, win->bg.img, 'N');
		ft_print_character(win, win->ennemies.frame5.img, 'N');
		win->anim_count++;
		win->ennemies.state = 1;
	}
	else if(win->anim_count == 5)
	{
		end = ft_ennemies_moove(win);
		ft_print_character(win, win->bg.img, 'N');
		ft_print_character(win, win->ennemies.frame5.img, 'N');
		win->anim_count = 0;
		return(end);
	}
	return(0);
}


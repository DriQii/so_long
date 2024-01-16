/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemies.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:21:34 by evella            #+#    #+#             */
/*   Updated: 2024/01/16 09:53:28 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/so_long.h"

static void	ft_check_ennemies_moove(t_win *win, t_index *i)
{
	if (win->map[i->y][i->x] == 'N' && win->map[i->y - 1][i->x] == '0')
		i->k -= 1;
	else if (win->map[i->y][i->x] == 'N' && win->map[i->y][i->x + 1] == '0')
		i->j += 1;
	else if (win->map[i->y][i->x] == 'N' && win->map[i->y + 1][i->x] == '0')
		i->k += 1;
	else if (win->map[i->y][i->x] == 'N' && win->map[i->y][i->x - 1] == '0')
		i->j -= 1;
	if (i->j != 0 || i->k != 0 || i->j == -1 || i->k == -1)
	{
		win->map[i->y][i->x] = '0';
		win->map[i->y + i->k][i->x + i->j] = 'N';
		if (i->y + i->k == win->player.y / 64 && i->x
			+ i->j == win->player.x / 64)
			ft_close_game(win, "You loose !!");
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->bg.img, i->x
			* 64, i->y * 64);
		if (i->j == 1)
			i->x++;
		if (i->k == 1)
			i->y++;
		i->j = 0;
		i->k = 0;
	}
}

int	ft_ennemies_moove(t_win *win)
{
	t_index	i;

	i.y = 1;
	i.x = 1;
	i.j = 0;
	i.k = 0;
	while (win->map[i.y])
	{
		while (win->map[i.y][i.x])
		{
			ft_check_ennemies_moove(win, &i);
			i.x++;
		}
		i.x = 0;
		i.y++;
	}
	return (win->keycode);
}

static void	ft_test(t_win *win, t_data frame, int state)
{
	ft_print_character(win, win->bg.img, 'N');
	ft_print_character(win, frame.img, 'N');
	if (state == 1)
		win->ennemies.state = 1;
	else
		win->ennemies.state = 0;
	if (win->anim_count == 5)
		win->anim_count = 0;
	else
		win->anim_count++;
}

int	ft_loop_hook(t_win *win)
{
	int	end;

	if (win->loop < 10000)
	{
		win->loop++;
		return (0);
	}
	win->loop = 0;
	if (win->anim_count == 0)
		ft_test(win, win->ennemies.frame1, 0);
	if (win->anim_count == 1)
		ft_test(win, win->ennemies.frame2, 0);
	else if (win->anim_count == 2)
		ft_test(win, win->ennemies.frame3, 0);
	else if (win->anim_count == 3)
		ft_test(win, win->ennemies.frame4, 0);
	else if (win->anim_count == 4)
		ft_test(win, win->ennemies.frame5, 1);
	else if (win->anim_count == 5)
	{
		end = ft_ennemies_moove(win);
		ft_test(win, win->ennemies.frame5, 1);
		return (end);
	}
	return (0);
}

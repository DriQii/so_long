/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:16:02 by evella            #+#    #+#             */
/*   Updated: 2024/01/09 20:16:41 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/so_long.h"

void	ft_player_fight_init(t_win *win)
{
	win->player.front.fight = ft_get_image_transparance(win->mlx, win->bg,
			"images/char/kakashi_front_fight.xpm");
	win->player.front.fight2 = ft_get_image_transparance(win->mlx, win->bg,
			"images/char/kakashi_front_fight2.xpm");
	win->player.front.fight3 = ft_get_image_transparance(win->mlx, win->bg,
			"images/char/kakashi_front_fight3.xpm");
	win->player.back.fight = ft_get_image_transparance(win->mlx, win->bg,
			"images/char/kakashi_back_fight.xpm");
	win->player.back.fight2 = ft_get_image_transparance(win->mlx, win->bg,
			"images/char/kakashi_back_fight2.xpm");
	win->player.back.fight3 = ft_get_image_transparance(win->mlx, win->bg,
			"images/char/kakashi_back_fight3.xpm");
	win->player.left.fight = ft_get_image_transparance(win->mlx, win->bg,
			"images/char/kakashi_left_fight.xpm");
	win->player.left.fight2 = ft_get_image_transparance(win->mlx, win->bg,
			"images/char/kakashi_left_fight2.xpm");
	win->player.left.fight3 = ft_get_image_transparance(win->mlx, win->bg,
			"images/char/kakashi_left_fight3.xpm");
	win->player.right.fight = ft_get_image_transparance(win->mlx, win->bg,
			"images/char/kakashi_right_fight.xpm");
	win->player.right.fight2 = ft_get_image_transparance(win->mlx, win->bg,
			"images/char/kakashi_right_fight2.xpm");
	win->player.right.fight3 = ft_get_image_transparance(win->mlx, win->bg,
			"images/char/kakashi_right_fight3.xpm");
}

void	ft_player_init(t_win *win)
{
	win->player.front.still = ft_get_image_transparance(win->mlx, win->bg,
			"images/char/kakashi_front.xpm");
	win->player.front.walk = ft_get_image_transparance(win->mlx, win->bg,
			"images/char/kakashi_front_walk.xpm");
	win->player.front.walk2 = ft_get_image_transparance(win->mlx, win->bg,
			"images/char/kakashi_front_walk2.xpm");
	win->player.back.still = ft_get_image_transparance(win->mlx, win->bg,
			"images/char/kakashi_back.xpm");
	win->player.back.walk = ft_get_image_transparance(win->mlx, win->bg,
			"images/char/kakashi_back_walk.xpm");
	win->player.back.walk2 = ft_get_image_transparance(win->mlx, win->bg,
			"images/char/kakashi_back_walk2.xpm");
	win->player.left.still = ft_get_image_transparance(win->mlx, win->bg,
			"images/char/kakashi_left.xpm");
	win->player.left.walk = ft_get_image_transparance(win->mlx, win->bg,
			"images/char/kakashi_left_walk.xpm");
	win->player.left.walk2 = ft_get_image_transparance(win->mlx, win->bg,
			"images/char/kakashi_left_walk2.xpm");
	win->player.right.still = ft_get_image_transparance(win->mlx, win->bg,
			"images/char/kakashi_right.xpm");
	win->player.right.walk = ft_get_image_transparance(win->mlx, win->bg,
			"images/char/kakashi_right_walk.xpm");
	win->player.right.walk2 = ft_get_image_transparance(win->mlx, win->bg,
			"images/char/kakashi_right_walk2.xpm");
	ft_player_fight_init(win);
}

void	ft_ennemies_init(t_win *win)
{
	win->ennemies.frame1 = ft_get_image_transparance(win->mlx, win->bg,
			"images/char/naruto_front.xpm");
	win->ennemies.frame2 = ft_get_image_transparance(win->mlx, win->bg,
			"images/char/Naruto_hand.xpm");
	win->ennemies.frame3 = ft_get_image_transparance(win->mlx, win->bg,
			"images/char/Naruto_hand2.xpm");
	win->ennemies.frame4 = ft_get_image_transparance(win->mlx, win->bg,
			"images/char/Naruto_hand3.xpm");
	win->ennemies.frame5 = ft_get_image_transparance(win->mlx, win->bg,
			"images/char/Sexy_jutsu.xpm");
	win->ennemies.dead = ft_get_image_transparance(win->mlx, win->bg,
			"images/char/naruto_dead.xpm");
	win->ennemies.dead2 = ft_get_image_transparance(win->mlx, win->bg,
			"images/char/naruto_dead2.xpm");
	win->ennemies.dead3 = ft_get_image_transparance(win->mlx, win->bg,
			"images/char/naruto_dead3.xpm");
}

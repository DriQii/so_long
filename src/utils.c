/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:19:23 by evella            #+#    #+#             */
/*   Updated: 2024/01/08 15:01:23 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/so_long.h"

t_coords	*ft_get_coords(char **map, int c)
{
	t_index		i;
	t_coords	*coords;

	i.y = 0;
	i.x = 0;
	coords = ft_calloc(sizeof(*coords), 1);
	while (map[i.y])
	{
		while (map[i.y][i.x] && map[i.y][i.x] != '\n')
		{
			if (map[i.y][i.x] == c)
				coords = ft_newlstcoords(i.x, i.y, coords);
			i.x++;
		}
		i.x = 0;
		i.y++;
	}
	return (coords);
}

void	ft_tabtablen(char **tab, t_win *win)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
			j++;
		i++;
	}
	win->y = i;
	win->x = j - 1;
}

void	ft_destroy_anim(t_win *win, t_anim anim)
{
	mlx_destroy_image(win->mlx, anim.still.img);
	mlx_destroy_image(win->mlx, anim.walk.img);
	mlx_destroy_image(win->mlx, anim.walk2.img);
	mlx_destroy_image(win->mlx, anim.fight.img);
	mlx_destroy_image(win->mlx, anim.fight2.img);
	mlx_destroy_image(win->mlx, anim.fight3.img);
}

void	ft_close_game(t_win *win, char *str)
{
	ft_printf("\n\n%s\n\n", str);
	mlx_destroy_window(win->mlx, win->mlx_win);
	ft_destroy_anim(win, win->player.front);
	ft_destroy_anim(win, win->player.back);
	ft_destroy_anim(win, win->player.right);
	ft_destroy_anim(win, win->player.left);
	ft_freetabtabb(win->y, win->map);
	free(win->mlx);
	exit(0);
}

void	ft_freecoords(t_coords *coords)
{
	t_coords	*tmp;

	while (coords)
	{
		tmp = coords;
		coords = coords->next;
		free(tmp);
	}
}

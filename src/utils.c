/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:19:23 by evella            #+#    #+#             */
/*   Updated: 2023/12/13 14:33:23 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/libft.h"

void ft_print_tabtab(char **tab)
{
	int i;

	i = 0;
	while(tab[i])
	{
		ft_printf("%s", tab[i]);
		i++;
	}
}

void ft_print_coords(t_coords *lst)
{
	while (lst)
	{
		printf("%d %d\n", lst->y, lst->x);
		lst = lst->next;
	}
}

t_coords *ft_get_coords(char **map, int c)
{
	t_index		i;
	t_coords	*coords;

	i.y = 0;
	i.x = 0;
	while (map[i.y])
	{
		while (map[i.y][i.x] && map[i.y][i.x] != '\n')
		{
			if(map[i.y][i.x] == c)
				coords = ft_newlstcoords(i.x, i.y, coords);
			i.x++;
		}
		i.x = 0;
		i.y++;
	}
	return(coords);
}

void ft_tabtablen(t_win *win)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while(win->map[i])
	{
		j = 0;
		while(win->map[i][j])
			j++;
		i++;
	}
	win->y = i;
	win->x = j - 1;
}

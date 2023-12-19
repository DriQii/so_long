/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:42:22 by evella            #+#    #+#             */
/*   Updated: 2023/12/20 00:14:51 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long.h"
#include "../include/libft.h"

void	*ft_freetabtabb(int size, char **tab, t_win *win)
{
    int i = 0;
	while (i < size)
	{
		free(tab[i]);
		tab[i] = NULL;
        i++;
	}
	if (tab[i])
		free(tab[i]);
    if(i > 0)
	    free (tab);
	tab = NULL;
	printf("win %d, %d, %d\n", i, win->y, win->x);
	return (NULL);
}
char **ft_realoc_tabtab(char **tab, int size, t_win *win)
{
    int i;
    char **newtab;

    i = 0;
    newtab = malloc(sizeof(char *) * (size + 2));
	if(tab)
    {
		while (i < size && tab[i])
		{
			newtab[i] = ft_strdup(tab[i]);
			i++;
		}
		ft_freetabtabb(i, tab, win);
	}

    newtab[i] = NULL;
	newtab[i + 1] = NULL;
	//printf("%d\n", i);
    return(newtab);
}

char **ft_get_map(int fd, t_win *win)
{
    char    **map;
    char    *tmp;
    t_index i;

    i.i = 0;
    tmp = get_next_line(fd);
	if (!tmp)
	{
		map = ft_calloc(sizeof(char *), 1);
		map[0] = NULL;
		return (map);
	}
    while(tmp)
    {
        map = ft_realoc_tabtab(map, i.i, win);
        map[i.i] = tmp;
        tmp = get_next_line(fd);
        i.i++;
    }
    //map = ft_realoc_tabtab(map, i.i);
    return(map);
}

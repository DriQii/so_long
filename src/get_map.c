/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:42:22 by evella            #+#    #+#             */
/*   Updated: 2023/12/14 14:34:40 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long.h"
#include "../include/libft.h"

void	*ft_freetabtabb(int size, char **tab)
{
    int i = 0;
	while (i < size)
	{
		free(tab[i]);
        i++;
	}
	//printf("%s", tab[0]);
    if(i > 0)
	    free (tab);
	return (NULL);
}
char **ft_realoc_tabtab(char **tab, int size)
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
		ft_freetabtabb(i, tab);
	}

    newtab[i] = NULL;
	newtab[i + 1] = NULL;
	//printf("%d\n", i);
    return(newtab);
}

char **ft_get_map(int fd)
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
        map = ft_realoc_tabtab(map, i.i);
        map[i.i] = tmp;
        tmp = get_next_line(fd);
        i.i++;
    }
    //map = ft_realoc_tabtab(map, i.i);
    return(map);
}

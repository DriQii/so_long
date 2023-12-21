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

void	*ft_freetabtabb(int size, char **tab)
{
    int i = 0;
	while (i < size)
	{
		free(tab[i]);
		tab[i] = NULL;
        i++;
	}
    if(i > 0)
	    free (tab);
	tab = NULL;
	return (NULL);
}
char **ft_realoc_tabtab(char **tab, int size)
{
    int i;
    char **newtab;

    i = 0;
    newtab = malloc(sizeof(char *) * (size + 2));
	while (i < size && tab[i])
	{
		newtab[i] = ft_strdup(tab[i]);
		i++;
	}
	if (i > 0)
		ft_freetabtabb(i, tab);
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
    
	map = ft_calloc(sizeof(char *), 1);
	if(!map)
		return(NULL);
	map[0] = NULL;
	tmp = get_next_line(fd);
	if (!tmp)
		return (map);
    while(tmp)
    {
        
        map[i.i] = tmp;
		i.i++;
		map = ft_realoc_tabtab(map, i.i);
        tmp = get_next_line(fd);
        
    }
    map = ft_realoc_tabtab(map, i.i);
    return(map);
}


#include "../include/so_long.h"
#include "../include/libft.h"

void	*ft_freetabtabb(int k, char **tab)
{
    int i = 0;
	while (k > 0)
	{
		k--;
        i++;
		free(tab[k]);
	}
    if(i > 0)
	    free (tab);
	return (NULL);
}
char **ft_realoc_tabtab(char **tab, int size)
{
    int i;
    char **newtab;

    i = 0;
    newtab = ft_calloc(sizeof(char *), size + 1);
    while (i < size)
    {
        newtab[i] = ft_strdup(tab[i]);
        i++;
    }
    ft_freetabtabb(i, tab);
    newtab[i] = NULL;
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
    map = ft_realoc_tabtab(map, i.i);
    return(map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:58:17 by evella            #+#    #+#             */
/*   Updated: 2023/12/20 00:24:09 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long.h"
#include "../include/libft.h"


void	ft_new_map(char **map, char **newmap)
{
	t_index	i;

	i.i = 0;
	i.l = ft_strlen(map[0]);
	while(map[i.i])
	{
		ft_memset(newmap[i.i], '0', i.l - 1);
		i.i++;
	}
	//newmap = ft_realoc_tabtab(newmap, i.x);
}

/* void	ft_new_map(char **map, char **newmap)
{
	char	*tmp;
	t_index	i;

	i.x = 0;
	i.y = 0;
	i.l = ft_strlen(map[0]);
	while(map[i.x])
	{
		//newmap = ft_realoc_tabtab(newmap, i.x);
		tmp = ft_calloc(sizeof(char), i.l + 1);
		ft_memset(tmp, '0', i.l);
		tmp[i.l - 1] = '\n';
		newmap[i.x] = tmp;
		i.x++;
	}
	//newmap = ft_realoc_tabtab(newmap, i.x);
	//return(newmap);
} */

static int	ft_border_verif(char **map)
{
	t_index	i;

	i.i = 0;
	i.j = 0;
	i.l = ft_strlen(map[0]) - 1;
	while (map[i.i])
	{
		while (map[i.i][i.j] && map[i.i][i.j] != '\n')
		{
			if ((i.i == 0 && map[i.i][i.j] != '1')
			|| (map[i.i][0] != '1'
			|| map[i.i][i.l - 1] != '1')
			|| (!map[i.i + 1] && map[i.i][i.j] != '1'))
			{
				ft_printf("Error\nThe map must be surrounded by obstacles\n");
				return (1);
			}
			i.j++;
		}
		i.j = 0;
		i.i++;
	}
	return(0);
}

static int	ft_character_verif(char **map)
{
	t_index i;

	i.c = 0;
	i.e = 0;
	i.p = 0;
	i.i = 0;
	i.j = 0;
	while (map[i.i])
	{
		while (map[i.i][i.j] && map[i.i][i.j] != '\n')
		{
			if (map[i.i][i.j] == 'C')
				i.c++;
			else if (map[i.i][i.j] == 'E')
				i.e++;
			else if (map[i.i][i.j] == 'P')
				i.p++;
			i.j++;
		}
		i.j = 0;
		i.i++;
	}
	if(i.c == 0 || i.e != 1 || i.p != 1)
		return(ft_printf("Error\nThe map must contain a single P a single E and at least one C\n"), 1);
	return(0);
}

static int	ft_shape_verif(char **map)
{
	t_index i;

	i.i = 0;
	i.l = ft_strlen(map[0]);
	while (map[i.i])
	{
		i.k = ft_strlen(map[i.i]);
		if (i.k != i.l)
			return(ft_printf("Error\nThe map must be rectangular\n"), 1);
		i.i++;
	}
	return(0);
}

char	**ft_map_verif(char *file, t_win *win)
{
	int			fd;
	char		**map;
	char		**newmap;
	t_character	*character;

	fd = open(file, O_RDONLY);
    map = ft_get_map(fd, win);
	if (!map[0])
		return (free(map), ft_printf("Error\nEmpty map\n"), NULL);
	close(fd);
	ft_tabtablen(map, win);
	fd = open(file, O_RDONLY);
	newmap = ft_get_map(fd, win);
	ft_new_map(map, newmap);
	close(fd);
	fd = open(file, O_RDONLY);
	if(!newmap)
		return(free(map), NULL);
	ft_char_shearch(map, &character);
	if (ft_shape_verif(map) != 0)
		return (free(map),free(newmap), NULL);
	else if (ft_border_verif(map) != 0)
		return (free(map),free(newmap), NULL);
	else if (ft_character_verif(map) != 0)
		return (free(map),free(newmap), NULL);
	else if(ft_road_error(map, newmap, character) != 0)
		return (free(map),free(newmap), NULL);
	ft_printf("Map OK\n");
	win->c_count = character->C;
	ft_freecoords(character->C_coords);
	ft_freecoords(character->E_coords);
	ft_freecoords(character->P_coords);
	free(character);
	close(fd);
	newmap = ft_freetabtabb(win->y , newmap, win);
	return (map);
}



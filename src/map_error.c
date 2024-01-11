/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:58:17 by evella            #+#    #+#             */
/*   Updated: 2024/01/11 18:21:11 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/so_long.h"

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
			if ((i.i == 0 && map[i.i][i.j] != '1') || (map[i.i][0] != '1'
					|| map[i.i][i.l - 1] != '1') || (!map[i.i + 1]
					&& map[i.i][i.j] != '1'))
			{
				ft_printf("Error\nThe map must be surrounded by obstacles\n");
				return (1);
			}
			i.j++;
		}
		i.j = 0;
		i.i++;
	}
	return (0);
}

static int	ft_character_verif(char **map)
{
	t_index	i;

	i.c = 0;
	i.e = 0;
	i.p = 0;
	i.i = -1;
	i.j = 0;
	while (map[++i.i])
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
	}
	if (i.c == 0 || i.e != 1 || i.p != 1)
		return (ft_printf("Error\n \
		The map must contain a single P a single E and at least one C\n"), 1);
	return (0);
}

static int	ft_shape_verif(char **map)
{
	t_index	i;

	i.i = 0;
	i.l = ft_strlen(map[0]);
	while (map[i.i])
	{
		i.k = ft_strlen(map[i.i]);
		if (i.k != i.l)
			return (ft_printf("Error\nThe map must be rectangular\n"), 1);
		i.i++;
	}
	return (0);
}
static void	*ft_map_error(t_character *character)
{
	ft_freecoords(character->C_coords);
	ft_freecoords(character->E_coords);
	ft_freecoords(character->P_coords);
	free(character);
	return (NULL);
}

char	**ft_map_verif(char *file, t_win *win)
{
	int			fd;
	char		**map;
	char		**newmap;
	t_character	*character;

	fd = open(file, O_RDONLY);
	map = ft_get_map(fd);
	if (!map[0])
		return (free(map), ft_printf("Error\nEmpty map\n"), NULL);
	close(fd);
	ft_tabtablen(map, win);
	fd = open(file, O_RDONLY);
	newmap = ft_get_map(fd);
	ft_new_map(map, newmap);
	close(fd);
	if (!newmap)
		return (ft_freetabtabb(win->y, map), NULL);
	ft_char_shearch(map, &character);
	if (ft_shape_verif(map) || ft_border_verif(map)
		|| ft_character_verif(map) || ft_road_error(map, newmap, character))
		return (ft_freetabtabb(win->y, map), ft_freetabtabb(win->y, newmap)
		,ft_map_error(character));
	win->c_count = character->C;
	newmap = ft_freetabtabb(win->y, newmap);
	return (ft_map_error(character) ,map);
}

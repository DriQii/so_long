/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   road_error2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:12:08 by evella            #+#    #+#             */
/*   Updated: 2024/01/11 18:21:19 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/so_long.h"

void	ft_new_map(char **map, char **newmap)
{
	t_index	i;

	i.i = 0;
	i.l = ft_strlen(map[0]);
	while (map[i.i])
	{
		ft_memset(newmap[i.i], '0', i.l - 1);
		i.i++;
	}
}

t_coords	*ft_newlstcoords(int x, int y, t_coords *coords)
{
	t_coords	*node;

	node = ft_calloc(sizeof(*node), 1);
	if (!node)
		return (NULL);
	node->x = x;
	node->y = y;
	if (coords)
		node->next = coords;
	coords = node;
	return (coords);
}

void	ft_char_coords(t_character **character, t_index i, char c)
{
	if (c == 'C')
	{
		(*character)->C++;
		(*character)->C_coords = ft_newlstcoords(i.x + 1, i.y + 1,
				(*character)->C_coords);
	}
	else if (c == 'P')
		(*character)->P_coords = ft_newlstcoords(i.x + 1, i.y + 1,
				(*character)->P_coords);
	else if (c == 'E')
		(*character)->E_coords = ft_newlstcoords(i.x + 1, i.y + 1,
				(*character)->E_coords);
}

t_character	*ft_char_shearch(char **map, t_character **character)
{
	t_index	i;

	i.y = 0;
	i.x = 0;
	(*character) = ft_calloc(sizeof(*(*character)), 1);
	(*character)->C = 0;
	while (map[i.y])
	{
		while (map[i.y][i.x] && map[i.y][i.x] != '\n')
		{
			if (map[i.y][i.x] == 'C')
				ft_char_coords(character, i, 'C');
			else if (map[i.y][i.x] == 'P')
				ft_char_coords(character, i, 'P');
			else if (map[i.y][i.x] == 'E')
				ft_char_coords(character, i, 'E');
			i.x++;
		}
		i.x = 0;
		i.y++;
	}
	return (*character);
}

t_coords	*ft_collectible_check(t_coords *P_coords, t_coords *coords,
		char **newmap)
{
	while (coords)
	{
		if (((P_coords->y == coords->y && P_coords->x - 1 == coords->x)
				|| (P_coords->y - 1 == coords->y && P_coords->x == coords->x)
				|| (P_coords->y == coords->y && P_coords->x + 1 == coords->x)
				|| (P_coords->y + 1 == coords->y && P_coords->x == coords->x))
			&& newmap[coords->y - 1][coords->x - 1] == '0')
			return (coords);
		coords = coords->next;
	}
	return (NULL);
}

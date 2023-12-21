/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   road_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:41:57 by evella            #+#    #+#             */
/*   Updated: 2023/12/21 15:36:59 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/libft.h"

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

t_character *ft_char_shearch(char **map, t_character **character)
{
	t_index		i;

	i.y = 0;
	i.x = 0;
	(*character) = ft_calloc(sizeof(*(*character)), 1);
	(*character)->C = 0;
	while (map[i.y])
	{
		while (map[i.y][i.x] && map[i.y][i.x] != '\n')
		{
			if (map[i.y][i.x] == 'C')
				{
					(*character)->C++;
					(*character)->C_coords = ft_newlstcoords(i.x + 1, i.y + 1, (*character)->C_coords);
				}
			else if(map[i.y][i.x] == 'P')
				(*character)->P_coords = ft_newlstcoords(i.x + 1 , i.y + 1, (*character)->P_coords);
			else if(map[i.y][i.x] == 'E')
				(*character)->E_coords = ft_newlstcoords(i.x + 1 , i.y + 1, (*character)->E_coords);
			i.x++;
		}
		i.x = 0;
		i.y++;
	}
	return(*character);
}

t_coords	*ft_collectible_check(t_coords *P_coords, t_coords *coords, char **newmap)
{

	while (coords)
	{
		if (((P_coords->y == coords->y && P_coords->x - 1 == coords->x)
		|| (P_coords->y - 1 == coords->y && P_coords->x == coords->x)
		|| (P_coords->y == coords->y && P_coords->x + 1 == coords->x)
		|| (P_coords->y + 1 == coords->y && P_coords->x == coords->x))
		&& newmap[coords->y - 1][coords->x - 1] == '0')
			return(coords);
		coords = coords->next;
	}

	return(NULL);
}

t_coords	*ft_zero_check(t_character character, char **map, char **newmap)
{
	t_coords	*find;

	find = ft_calloc(sizeof(*find), 1);
	if ((map[character.P_coords->y - 1][character.P_coords->x - 2] == '0' || map[character.P_coords->y - 1][character.P_coords->x - 2] == 'N')
	&& newmap[character.P_coords->y - 1][character.P_coords->x - 2] == '0')
	{
		find = ft_newlstcoords(character.P_coords->x - 1, character.P_coords->y, find);
		return(find);
	}
	else if ((map[character.P_coords->y - 2][character.P_coords->x - 1] == '0' || map[character.P_coords->y - 2][character.P_coords->x - 1] == 'N')
	&& newmap[character.P_coords->y - 2][character.P_coords->x - 1] == '0')
	{
		find = ft_newlstcoords(character.P_coords->x, character.P_coords->y - 1, find);
		return(find);
	}
	else if ((map[character.P_coords->y - 1][character.P_coords->x] == '0' || map[character.P_coords->y - 1][character.P_coords->x] == 'N')
	&& newmap[character.P_coords->y - 1][character.P_coords->x] == '0')
	{
		find = ft_newlstcoords(character.P_coords->x + 1, character.P_coords->y, find);
		return(find);
	}
	else if ((map[character.P_coords->y ][character.P_coords->x - 1] == '0' || map[character.P_coords->y ][character.P_coords->x - 1] == 'N')
	&& newmap[character.P_coords->y ][character.P_coords->x - 1] == '0')
	{
		find = ft_newlstcoords(character.P_coords->x, character.P_coords->y + 1, find);
		return(find);
	}
	return(free(find), NULL);
}
int	ft_road_error(char **map, char **newmap, t_character *character)
{
	t_coords	*find;
	t_coords	*tmp;
	t_index		i;

	i.i = 0;
	i.j = 0;
	while (character->P_coords)
	{
		if(i.i == character->C + 1)
		{
			find = ft_collectible_check(character->P_coords, character->E_coords, newmap);
			if(find)
			{
				return(0);
			}
			newmap[character->P_coords->y - 1][character->P_coords->x - 1] = '1';
		}
		if ((find = ft_collectible_check(character->P_coords, character->C_coords, newmap)))
		{
			character->P_coords = ft_newlstcoords(find->x, find->y, character->P_coords);
			newmap[find->y - 1][find->x - 1] = '1';
			if(i.i < character->C)
				i.i++;
		}
		else
		{
			find = ft_zero_check(*character, map, newmap);
			if (find)
				{
					character->P_coords = ft_newlstcoords(find->x, find->y, character->P_coords);
					newmap[find->y - 1][find->x - 1] = '1';
					free(find->next);
					free(find);
				}
			else
				{
					tmp = character->P_coords;
					character->P_coords = character->P_coords->next;
					free(tmp);
				}
		}
		if (i.i == character->C)
			{
				ft_new_map(map, newmap);
				i.i++;
			}
	}
	return(printf("Error\nNo way to reach all the collectibles and the exit\n"), 1);
}

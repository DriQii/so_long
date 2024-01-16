/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   road_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:41:57 by evella            #+#    #+#             */
/*   Updated: 2024/01/16 16:26:45 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/so_long.h"

t_coords	*ft_zero_check(t_character character, char **map, char **newmap)
{
	t_index		i;

	i.x = 0;
	i.y = 0;
	if ((map[character.P_coords->y - 1][character.P_coords->x - 2] == '0'
		|| map[character.P_coords->y - 1][character.P_coords->x - 2] == 'N')
		&& newmap[character.P_coords->y - 1][character.P_coords->x - 2] == '0')
		i.x--;
	else if ((map[character.P_coords->y - 2][character.P_coords->x - 1] == '0'
		|| map[character.P_coords->y - 2][character.P_coords->x - 1] == 'N')
		&& newmap[character.P_coords->y - 2][character.P_coords->x - 1] == '0')
		i.y--;
	else if ((map[character.P_coords->y - 1][character.P_coords->x] == '0'
		|| map[character.P_coords->y - 1][character.P_coords->x] == 'N')
		&& newmap[character.P_coords->y - 1][character.P_coords->x] == '0')
		i.x++;
	else if ((map[character.P_coords->y][character.P_coords->x - 1] == '0'
		|| map[character.P_coords->y][character.P_coords->x - 1] == 'N')
		&& newmap[character.P_coords->y][character.P_coords->x - 1] == '0')
		i.y++;
	if (i.y != 0 || i.x != 0)
		return (ft_newlstcoords(character.P_coords->x + i.x, \
			character.P_coords->y + i.y, NULL));
	return (NULL);
}

static void	ft_check_road(char **map, char **newmap, t_character *character)
{
	t_coords	*find;
	t_coords	*tmp;

	find = ft_zero_check(*character, map, newmap);
	if (find)
	{
		character->P_coords = ft_newlstcoords(find->x, find->y,
				character->P_coords);
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

static int	ft_check_exit(int c_count, char **newmap, t_character *character)
{
	t_coords	*find;

	if (c_count == character->C + 1)
	{
		find = ft_collectible_check(character->P_coords,
				character->E_coords, newmap);
		if (find)
			return (1);
		newmap[character->P_coords->y - 1][character->P_coords->x
			- 1] = '1';
	}
	return (0);
}

static int	ft_check_c(char **map, char **newmap
	, t_character *character, int c_count)
{
	t_coords	*find;

	find = ft_collectible_check(character->P_coords, \
	character->C_coords, newmap);
	if (find)
	{
		character->P_coords = ft_newlstcoords(find->x, find->y,
				character->P_coords);
		newmap[find->y - 1][find->x - 1] = '1';
		if (c_count < character->C)
			c_count++;
	}
	else
		ft_check_road(map, newmap, character);
	return (c_count);
}

int	ft_road_error(char **map, char **newmap, t_character *character)
{
	int			c_count;

	c_count = 0;
	while (character->P_coords)
	{
		if (ft_check_exit(c_count, newmap, character))
			return (0);
		c_count = ft_check_c(map, newmap, character, c_count);
		if (c_count == character->C)
		{
			ft_new_map(map, newmap);
			c_count++;
		}
	}
	return (ft_printf("Error\n \
No way to reach all the collectibles and the exit\n"),
		1);
}

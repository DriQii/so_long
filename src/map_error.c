/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:58:17 by evella            #+#    #+#             */
/*   Updated: 2023/11/30 16:41:37 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long.h"
#include "../include/libft.h"

static int	ft_border_verif(char **map)
{
	t_index i;

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
				ft_printf("Border Error\n");
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
	if(i.c == 0 || i.e == 0 || i.p == 0)
		return(ft_printf("Character Error\n"), 1);
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
			return(ft_printf("Shape Error\n"), 1);
		i.i++;
	}
	return(0);
}

int	ft_map_verif(char **map)
{
	if (!map[0])
		return (free(map), ft_printf("Empty Map\n"), 1);
	if (ft_shape_verif(map) != 0)
		return (2);
	else if (ft_border_verif(map) != 0)
		return (3);
	else if (ft_character_verif(map) != 0)
		return (4);
	ft_printf("Map OK\n");
	return (0);
}



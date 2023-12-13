/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:19:23 by evella            #+#    #+#             */
/*   Updated: 2023/12/07 19:53:00 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/libft.h"

void ft_print_tabtab(char **tab)
{
	int i;

	i = 0;
	while(tab[i])
	{
		ft_printf("%s", tab[i]);
		i++;
	}
}

void ft_print_coords(t_coords *lst)
{
	while (lst)
	{
		printf("%d %d\n", lst->y, lst->x);
		lst = lst->next;
	}
}

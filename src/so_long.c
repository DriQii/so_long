/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:42:03 by evella            #+#    #+#             */
/*   Updated: 2023/12/20 00:25:47 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_win	win;

	if (argc != 2)
		return (ft_printf("Error\nPlease give only one map as argument\n"), 1);
	if (!(win.map = ft_map_verif(argv[1], &win)))
		return (1);
	ft_win_init(&win);
	mlx_key_hook(win.mlx_win, ft_hook, &win);
	if (mlx_loop_hook(win.mlx, ft_loop_hook, &win) == 1)
		return (0);
	mlx_loop(win.mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:50:15 by evella            #+#    #+#             */
/*   Updated: 2023/10/02 14:50:50 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	len;

	len = 1;
	while (n / 10 != 0)
	{
		len = len * 10;
		n = n / 10;
	}
	return (len);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		len;
	char	res;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = n * -1;
	}
	len = ft_intlen(n);
	while (len >= 1)
	{
		res = n / len + '0';
		write (fd, &res, 1);
		n = n % len;
		len = len / 10;
	}
}

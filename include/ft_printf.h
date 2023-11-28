/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 02:47:01 by evella            #+#    #+#             */
/*   Updated: 2023/10/08 19:43:04 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <../include/libft.h>

int	ft_putptr(unsigned long int n);
int	ft_putnbr_hexa(unsigned int n, int upper, int format);
int	ft_putchar(const char c);
int	ft_putstr(const char *s);
int	ft_putnbru(unsigned int n);
int	ft_printf(const char *s, ...);
int	ft_intlen(int n);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 09:08:40 by mapontil          #+#    #+#             */
/*   Updated: 2021/11/23 10:05:34 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	ft_check_conv(char arg, va_list args, int *i);
int		ft_valid_conv(char arg);
void	ft_putchar(char c, int *i);
size_t	ft_strlen(const char *s);
void	ft_putc(va_list args, int *i);
void	ft_puts(va_list args, int *i);
void	ft_putnbr(int nb, int *i);
void	ft_putunbr(unsigned int nb, int *i);
void	ft_putn(va_list args, int *i);
void	ft_putun(va_list args, int *i);
void	ft_putnhex(va_list args, int *i);
void	ft_putnhex_maj(va_list args, int *i);
void	ft_puthex_p(va_list args, int *i);
void	ft_putnbr_base(long int nb, char *base, int *i);
void	ft_putnbr_base_ad(unsigned long int nb, char *base, int *i);

#endif
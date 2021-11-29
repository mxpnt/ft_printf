/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 09:13:54 by mapontil          #+#    #+#             */
/*   Updated: 2021/11/23 10:01:40 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_valid_conv(char arg)
{
	if (arg == 'c' || arg == 's' || arg == 'p' || arg == 'd' || arg == 'i'
		|| arg == 'u' || arg == 'x' || arg == 'X' || arg == '%')
		return (1);
	return (0);
}

void	ft_check_conv(char arg, va_list args, int *i)
{
	if (arg == 'c')
		ft_putc(args, i);
	else if (arg == 's')
		ft_puts(args, i);
	else if (arg == 'p')
		ft_puthex_p(args, i);
	else if (arg == 'd' || arg == 'i')
		ft_putn(args, i);
	else if (arg == 'u')
		ft_putun(args, i);
	else if (arg == 'x')
		ft_putnhex(args, i);
	else if (arg == 'X')
		ft_putnhex_maj(args, i);
	else if (arg == '%')
		ft_putchar('%', i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			if (ft_valid_conv(*(str + 1)))
			{
				ft_check_conv(*(str + 1), args, &i);
				str += 2;
			}
			else
				str++;
		}
		else
		{
			ft_putchar(*str, &i);
			str++;
		}
	}
	va_end(args);
	return (i);
}

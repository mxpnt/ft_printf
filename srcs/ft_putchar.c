/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:41:04 by mapontil          #+#    #+#             */
/*   Updated: 2021/11/16 11:11:03 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putc(va_list args, int *i)
{
	unsigned char	c;

	c = va_arg(args, int);
	*i += write(1, &c, 1);
}

void	ft_puts(va_list args, int *i)
{
	char	*str;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		*i += write(1, "(null)", 6);
		return ;
	}
	*i += write(1, str, ft_strlen(str));
}

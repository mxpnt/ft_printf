/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 16:01:23 by mapontil          #+#    #+#             */
/*   Updated: 2021/11/16 14:17:34 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_base_ad(unsigned long int nb, char *base, int *i)
{
	if (nb < 0)
		nb = -nb;
	if (nb >= 16)
		ft_putnbr_base_ad(nb / 16, base, i);
	ft_putchar(base[nb % 16], i);
}

void	ft_putnhex(va_list args, int *i)
{
	unsigned int	nb;

	nb = va_arg(args, unsigned int);
	ft_putnbr_base_ad(nb, "0123456789abcdef", i);
}

void	ft_putnhex_maj(va_list args, int *i)
{
	unsigned int	nb;

	nb = va_arg(args, unsigned int);
	ft_putnbr_base_ad(nb, "0123456789ABCDEF", i);
}

void	ft_puthex_p(va_list args, int *i)
{
	unsigned long int	nb;

	nb = va_arg(args, unsigned long int);
	*i += write(1, "0x", 2);
	ft_putnbr_base_ad(nb, "0123456789abcdef", i);
}

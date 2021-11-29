/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:38:18 by mapontil          #+#    #+#             */
/*   Updated: 2021/11/16 11:30:27 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr(int nb, int *i)
{
	long int	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		*i += write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10, i);
	nbr = nbr % 10 + 48;
	*i += write(1, &nbr, 1);
}

void	ft_putunbr(unsigned int nb, int *i)
{
	if (nb < 0)
	{
		*i += write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10, i);
	nb = nb % 10 + 48;
	*i += write(1, &nb, 1);
}

void	ft_putn(va_list args, int *i)
{
	int	nb;

	nb = va_arg(args, int);
	ft_putnbr(nb, i);
}

void	ft_putun(va_list args, int *i)
{
	unsigned int	nb;

	nb = va_arg(args, unsigned int);
	ft_putunbr(nb, i);
}

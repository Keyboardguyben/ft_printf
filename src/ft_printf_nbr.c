/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilliea <bgilliea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:15:59 by bgilliea          #+#    #+#             */
/*   Updated: 2022/11/28 12:16:38 by bgilliea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_getsize(long nb)
{
	int	neg;
	int	i;

	neg = 0;
	i = 0;
	if (nb < 0)
	{
		neg = 1;
		i++;
		nb = -nb;
	}
	if (nb == 0)
		return (1);
	while (nb >= 1)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

void	ft_putnbr(int nb)
{
	unsigned int	nbr;

	if (nb < 0)
	{
		type_char('-');
		nbr = nb * -1;
	}
	else
		nbr = nb;
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	type_char(nbr % 10 + 48);
}

int	type_nbr(int nbr)
{
	int	printf_len;

	printf_len = ft_getsize(nbr);
	ft_putnbr(nbr);
	return (printf_len);
}

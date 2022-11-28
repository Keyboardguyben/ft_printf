/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilliea <bgilliea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:15:38 by bgilliea          #+#    #+#             */
/*   Updated: 2022/11/28 12:16:29 by bgilliea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_hex_len(unsigned	long num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_putnbr_base(long nbr, char *base)
{
	if (nbr == 0)
	{
		type_char(base[0]);
		return ;
	}
	if (nbr != 0)
	{
		if (nbr / 16 != 0)
			ft_putnbr_base(nbr / 16, base);
		type_char(base[nbr % 16]);
	}
}

int	type_hex(int nbr, char maj)
{
	int		printf_len;
	long	test;
	char	*base;

	printf_len = 0;
	test = 4294967296;
	base = "0123456789abcdef";
	if (maj == 'X')
		base = "0123456789ABCDEF";
	if (nbr >= 0)
	{
		ft_putnbr_base(nbr, base);
		printf_len += ft_hex_len(nbr);
	}
	else if (nbr < 0)
	{
		ft_putnbr_base((test + nbr), base);
		printf_len += ft_hex_len(test + nbr);
	}	
	return (printf_len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilliea <bgilliea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:12:07 by bgilliea          #+#    #+#             */
/*   Updated: 2022/11/24 15:54:58 by bgilliea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnbr_ptr(unsigned long long nbr, char *base)
{
	if (nbr == 0)
	{
		type_char(base[0]);
		return ;
	}
	if (nbr != 0)
	{
		if (nbr / 16 != 0)
			ft_putnbr_ptr(nbr / 16, base);
		type_char(base[nbr % 16]);
	}
}

int	type_ptr(unsigned long long ptr)
{
	int	print_len;

	print_len = 0;
	print_len += type_char('0');
	print_len += type_char('x');
	ft_putnbr_ptr(ptr, "0123456789abcdef");
	print_len += ft_hex_len(ptr);
	return (print_len);
}

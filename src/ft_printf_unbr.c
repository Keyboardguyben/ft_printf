/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilliea <bgilliea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:50:25 by bgilliea          #+#    #+#             */
/*   Updated: 2022/11/24 16:41:39 by bgilliea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static unsigned int	ft_ugetsize(long nb)
{
	int	i;

	i = 0;
	if(nb == 0)
		return (1);
	while (nb >= 1)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

void	ft_putunbr(unsigned int nb)
{
	if (nb >= 10)
		ft_putunbr(nb / 10);
	type_char(nb % 10 + 48);
}

int	type_unsigned(unsigned int nbr)
{
	int	printf_len;

	printf_len = 0;
	printf_len = ft_ugetsize(nbr);
	ft_putunbr(nbr);
	return (printf_len);
}

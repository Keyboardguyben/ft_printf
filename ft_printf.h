/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilliea <bgilliea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:11:53 by bgilliea          #+#    #+#             */
/*   Updated: 2022/11/28 11:54:46 by bgilliea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *c, ...);
int	type_nbr(int nbr);
int	type_char(char c);
int	type_unsigned(unsigned int unbr);
int	type_hex(int nbr, char maj);
int	type_ptr(unsigned long long ptr);
int	ft_hex_len(unsigned	long num);

#endif
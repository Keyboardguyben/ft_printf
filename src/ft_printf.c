/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilliea <bgilliea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:05:07 by bgilliea          #+#    #+#             */
/*   Updated: 2022/11/28 12:15:45 by bgilliea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	type_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	type_str(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		i += type_str("(null)");
	}
	else
	{
		while (s[i])
			i += type_char(s[i]);
	}
	return (i);
}

int	get_type(va_list args, const char format)
{
	int	print_len;

	print_len = 0;
	if (format == 'c')
		print_len += type_char(va_arg(args, int));
	else if (format == 's')
		print_len += type_str(va_arg(args, char *));
	else if (format == 'p')
		print_len += type_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		print_len += type_nbr(va_arg(args, int));
	else if (format == 'u')
		print_len += type_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_len += type_hex(va_arg(args, int), format);
	else if (format == '%')
		print_len += type_char('%');
	return (print_len);
}

int	ft_printf(const char *c, ...)
{
	int		i;
	va_list	args;
	int		print_len;

	i = 0;
	print_len = 0;
	va_start(args, c);
	while (c[i])
	{
		if (c[i] == '%')
		{
			print_len += get_type(args, c[i + 1]);
			i++;
		}
		else
			print_len += type_char(c[i]);
		i++;
	}
	va_end(args);
	return (print_len);
}

// #include <stdio.h>
// int main()
// {
// 	char *str = "Voila c'est tout";
// 	void *ptr = str;

// 	int t1 = printf("%p\n","");
// 	int t2 = ft_printf("%p\n","");
// 	printf("%d =? %d",t1,t2);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:09:49 by prando-a          #+#    #+#             */
/*   Updated: 2023/09/10 18:55:39 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_x(unsigned long long n, char c)
{
	int		print_len;

	print_len = 0;
	if (n >= 16)
		print_len += print_x(n / 16, c);
	if (c == 'x')
		ft_putchar("0123456789abcdef"[n % 16]);
	else
		ft_putchar("0123456789ABCDEF"[n % 16]);
	return (++print_len);
}

int	print_p(unsigned long long n)
{
	return (write(1, "0x", 2) + print_x(n, 'x'));
}

int	formatter(va_list args, char format)
{
	if (format == '%')
		return (write(1, &format, 1));
	if (format == 'c')
		return (print_c(va_arg(args, int)));
	if (format == 's')
		return (print_s(va_arg(args, char *)));
	if (format == 'd' || format == 'i')
		return (print_di(va_arg(args, int)));
	if (format == 'u')
		return (print_u(va_arg(args, unsigned)));
	if (format == 'x' || format == 'X')
		return (print_x(va_arg(args, unsigned int), format));
	if (format == 'p')
		return (print_p(va_arg(args, unsigned long long)));
	return (0);
}

int	ft_printf(char const *str, ...)
{
	int		print_len;
	va_list	args;

	va_start(args, str);
	print_len = 0;
	while (*str)
	{
		if (*str == '%' && *str++)
			print_len += formatter(args, *str++);
		else
			print_len += write(1, str++, 1);
	}
	va_end(args);
	return (print_len);
}

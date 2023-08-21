/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:52:15 by prando-a          #+#    #+#             */
/*   Updated: 2023/07/27 10:41:35 by prando-a         ###   ########.fr       */
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

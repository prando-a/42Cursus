/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:35:15 by prando-a          #+#    #+#             */
/*   Updated: 2023/07/26 17:20:39 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	digits(long n, int len)
{
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	print_u(unsigned int n)
{
	int	print_len;

	print_len = digits(n, 0);
	if (n >= 10)
	{
		print_di(n / 10);
		print_di(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
	}
	return (print_len);
}

int	print_di(int n)
{
	int	print_len;

	print_len = digits(n, 0);
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		print_di(n / 10);
		print_di(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
	}
	return (print_len);
}

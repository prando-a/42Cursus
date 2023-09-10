/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:16:20 by prando-a          #+#    #+#             */
/*   Updated: 2023/09/10 18:52:59 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	print_c(int c)
{
	return (write(1, &c, 1));
}

int	print_s(char *str)
{
	int	print_len;

	print_len = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (*str)
		print_len += write(1, str++, 1);
	return (print_len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:08:54 by prando-a          #+#    #+#             */
/*   Updated: 2023/08/06 11:32:09 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(char const *str, ...);
void	ft_putchar(char c);
int		print_c(int c);
int		print_s(char *str);
int		print_di(int n);
int		print_u(unsigned int n);
int		print_x(unsigned long long n, char c);
int		print_p(unsigned long long n);

#endif
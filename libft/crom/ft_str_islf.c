/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_islf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crom <crom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:57:23 by prando-a          #+#    #+#             */
/*   Updated: 2023/10/21 19:27:41 by crom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	float_checker(char *str, int *i, int *check)
{
	int	sym_lock;

	sym_lock = 0;
	while (str[*i])
	{
		if (str[*i] == '.')
		{
			if (sym_lock++ == 0 && str[*i + 1] >= '0' && str[*i + 1] <= '9')
				(*check)++;
		}
		if (str[*i] >= '0' && str[*i] <= '9')
			(*check)++;
		(*i)++;
	}
	return (sym_lock && (*check == *i));
}

int	ft_str_islf(char *str)
{
	int	i;
	int	check;
	int	sym_lock;

	i = -1;
	check = 0;
	sym_lock = 0;
	if (!*str)
		return (0);
	while (str[++i] && str[i] != '.')
	{
		if (str[0] == '-' || str[0] == '+')
		{
			if (sym_lock++ == 0 && str[i + 1] >= '0' && str[i + 1] <= '9')
				check++;
		}
		if (str[i] >= '0' && str[i] <= '9')
			check++;
	}
	if (check == 0)
		return (0);
	return (float_checker(str, &i, &check) + (check == i));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_islf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:57:23 by prando-a          #+#    #+#             */
/*   Updated: 2023/08/30 13:40:46 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	float_checker(char *str, int *i, int *num_check)
{
	int	sym_lock;

	sym_lock = 0;
	while (str[*i])
	{
		if (str[*i] == '.')
		{
			if (sym_lock++ == 0 && str[*i + 1] >= '0' && str[*i + 1] <= '9')
				(*num_check)++;
		}
		if (str[*i] >= '0' && str[*i] <= '9')
			(*num_check)++;
		(*i)++;
	}
	return (sym_lock);
}

int	ft_str_islf(char *str)
{
	int	i;
	int	num_check;
	int	sym_lock;
	int	float_check;

	i = 0;
	num_check = 0;
	sym_lock = 0;
	while (str[i] && str[i] != '.')
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (sym_lock++ == 0 && str[i + 1] >= '0' && str[i + 1] <= '9')
				num_check++;
		}
		if (str[i] >= '0' && str[i] <= '9')
			num_check++;
		i++;
	}
	float_check = float_checker(str, &i, &num_check);
	if (num_check == i)
		return (1 + float_check);
	else
		return (0);
}

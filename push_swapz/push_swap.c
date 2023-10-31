/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crom <crom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:30:58 by prando-a          #+#    #+#             */
/*   Updated: 2023/10/23 00:46:37 by crom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_reps(char **raw)
{
	int	i;
	int	j;
	int	error;

	i = 0;
	error = 0;
	while (raw[i] && !error)
	{
		j = 0;
		while (raw[j] && !error)
		{
			if (ft_atoll(raw[j]) == ft_atoll(raw[i]) && i != j)
				error++;
			j++;
		}
		i++;
	}
	return (!error);
}

char	**arg_toraw(char **argv)
{
	char	**raw;
	char	*merged;
	int		i;

	merged = ft_merge(argv, ' ', 1);
	if (!merged)
		return (NULL);
	raw = ft_split(merged, ' ');
	free(merged);
	if (!raw)
		return (NULL);
	if (ft_arr_islf(raw) != 1 || !check_reps(raw))
		return (ft_strdel(raw), NULL);
	i = 0;
	while (raw[i])
	{
		if (ft_atoll(raw[i]) > INT_MAX || ft_atoll(raw[i++]) < INT_MIN)
			return (ft_strdel(raw), NULL);
	}
	return (raw);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**raw;
	int		i;

	if (argc == 1)
		return (1);
	raw = arg_toraw(++argv);
	if (!raw)
		return (ft_printf("Error\n"), 1);
	stack_a = NULL;
	stack_b = NULL;
	i = -1;
	while (raw[++i])
	{
		if (!write_stack_a(&stack_a, ft_atoll(raw[i]), i + 1))
			return (clear_stacks(&stack_a, &stack_b), ft_printf("Error\n"), 1);
	}
	ft_strdel(raw);
	sort_nums(&stack_a, &stack_b, i);
	return (clear_stacks(&stack_a, &stack_b), 0);
}

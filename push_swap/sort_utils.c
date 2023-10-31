/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crom <crom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:31:34 by prando-a          #+#    #+#             */
/*   Updated: 2023/10/23 00:56:56 by crom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_calc(t_list **arr, int elements)
{
	int		i;
	int		j;
	t_list	*p;

	i = 0;
	j = 0;
	while (i < elements - 1)
	{
		j = 0;
		while (j < elements - i - 1)
		{
			if (arr[j]->val > arr[j + 1]->val)
			{
				p = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = p;
			}
			j++;
		}
		i++;
	}
}

int	put_index(t_list **stack_a, int elements)
{
	t_list	*p;
	t_list	**arr;
	int		i;

	p = *stack_a;
	arr = malloc(elements * sizeof(t_list *));
	if (!arr)
		return (0);
	i = 0;
	while (p)
	{
		arr[i++] = p;
		p = p->next;
	}
	index_calc(arr, elements);
	i = -1;
	while (++i < elements)
		arr[i]->index = i + 1;
	return (free(arr), 1);
}

void	pos_update(t_list **stack_one, t_list **stack_two)
{
	t_list	*p;
	int		i;

	p = NULL;
	i = 0;
	if (stack_one && *stack_one)
	{
		p = *stack_one;
		while (p)
		{
			p->pos = ++i;
			p = p->next;
		}
	}
	if (stack_two && *stack_two)
	{
		p = *stack_two;
		i = 0;
		while (p)
		{
			p->pos = ++i;
			p = p->next;
		}
	}
}

int	get_min_val(t_list *stack)
{
	int	num;

	num = stack->val;
	while (stack)
	{
		if (stack->val < num)
			num = stack->val;
		stack = stack->next;
	}
	return (num);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nums.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:07:07 by prando-a          #+#    #+#             */
/*   Updated: 2023/10/23 18:12:00 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_list **stack_a, t_list **stack_b, int elements)
{
	int		i;
	int		j;
	int		bits;

	i = -1;
	bits = 0;
	while (elements >> bits++)
		;
	while (++i < bits && !lst_is_sorted(*stack_a))
	{
		j = 0;
		while (j++ < elements && !lst_is_sorted(*stack_a))
		{
			if ((*stack_a)->index >> i & 1)
				rotate(stack_a, 'a');
			else
				push(stack_a, stack_b, 'b');
		}
		while (*stack_b)
			push(stack_b, stack_a, 'a');
	}
}

void	sort_three(t_list **stack_a)
{
	t_list	*a;
	int		lock;

	a = *stack_a;
	lock = 0;
	if (a->val < a->next->val)
	{
		if (a->val < a->next->next->val && ++lock)
			swap(stack_a, 'a');
		else
			rev_r(stack_a, 'a');
	}
	a = *stack_a;
	if (a->val > a->next->val)
	{
		if (a->val > a->next->next->val)
			rotate(stack_a, 'a');
		if (lst_is_sorted(*stack_a))
			return ;
		a = *stack_a;
		if ((a->val < a->next->next->val && a->next->val > a->next->next->val)
			|| !lock)
			swap(stack_a, 'a');
	}
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int		min;
	t_list	*p;

	while (ft_lstsize(*stack_a) > 3 && !lst_is_sorted(*stack_a))
	{
		p = *stack_a;
		min = get_min_val(*stack_a);
		if (p->val == min)
			push(stack_a, stack_b, 'b');
		else
		{
			while (p->val != min)
				p = p->next;
			if (p->pos == 2)
				swap(stack_a, 'a');
			else if (p->pos == 4 || p->pos == 5)
				rev_r(stack_a, 'a');
			else
				rotate(stack_a, 'a');
		}
	}
	if (!lst_is_sorted(*stack_a))
		sort_three(stack_a);
	while (*stack_b)
		push(stack_b, stack_a, 'a');
}

void	sort_nums(t_list **stack_a, t_list **stack_b, int elements)
{
	if (lst_is_sorted(*stack_a))
		return ;
	if (elements == 2)
		swap(stack_a, 'a');
	else if (elements == 3)
		sort_three(stack_a);
	else if (elements == 4 || elements == 5)
		sort_five(stack_a, stack_b);
	else
	{
		if (!put_index(stack_a, elements))
			return ;
		radix_sort(stack_a, stack_b, elements);
	}
}

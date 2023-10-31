/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:27:41 by prando-a          #+#    #+#             */
/*   Updated: 2023/10/20 17:52:22 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_is_sorted(t_list *stack_a)
{
	t_list	*current;

	current = stack_a;
	while (current && current->next)
	{
		if (current->val > current->next->val)
			return (0);
		current = current->next;
	}
	return (1);
}

void	lst_clear(t_list *lst)
{
	t_list	*current;
	t_list	*temp;

	current = lst;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}

void	clear_stacks(t_list **stack_a, t_list **stack_b)
{
	if (stack_a)
		lst_clear(*stack_a);
	if (stack_b)
		lst_clear(*stack_b);
	*stack_a = NULL;
	*stack_b = NULL;
}

int	write_stack_a(t_list **lst, int val, int pos)
{
	t_list	*p;
	t_list	*last;

	p = (t_list *)malloc(sizeof(t_list));
	if (!p)
		return (0);
	p->val = val;
	p->pos = pos;
	p->next = NULL;
	if (!*lst)
		*lst = p;
	else
	{
		last = ft_lstlast(*lst);
		last->next = p;
	}
	return (1);
}

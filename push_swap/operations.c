/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:53:09 by prando-a          #+#    #+#             */
/*   Updated: 2023/10/09 18:07:06 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **src, t_list **dst, char c)
{
	t_list	*node_to_move;

	if (*src)
	{
		node_to_move = *src;
		*src = (*src)->next;
		node_to_move->next = *dst;
		*dst = node_to_move;
		ft_printf("p%c\n", c);
		pos_update(dst, src);
	}
}

void	swap(t_list **lst, char c)
{
	t_list	*new_first;
	t_list	*new_second;

	if (*lst && (*lst)->next)
	{
		new_second = *lst;
		new_first = new_second->next;
		new_second->next = new_first->next;
		new_first->next = new_second;
		*lst = new_first;
		if (c == 'a')
			ft_printf("s%c\n", c);
		else if (c == 'b')
			ft_printf("s%c\n", c);
		pos_update(lst, NULL);
	}
}

void	rotate(t_list **lst, char c)
{
	t_list	*new_last;
	t_list	*old_last;

	if (*lst && (*lst)->next)
	{
		new_last = *lst;
		old_last = ft_lstlast(*lst);
		*lst = new_last->next;
		old_last->next = new_last;
		new_last->next = NULL;
		if (c == 'a')
			ft_printf("r%c\n", c);
		else if (c == 'b')
			ft_printf("r%c\n", c);
		pos_update(lst, NULL);
	}
}

void	rev_r(t_list **lst, char c)
{
	t_list	*new_last;

	if (*lst && (*lst)->next)
	{
		new_last = *lst;
		while (new_last->next->next)
			new_last = new_last->next;
		new_last->next->next = *lst;
		*lst = new_last->next;
		new_last->next = NULL;
		if (c == 'a')
			ft_printf("rr%c\n", c);
		else if (c == 'b')
			ft_printf("rr%c\n", c);
		pos_update(lst, NULL);
	}
}

void	multi_op(t_list **stack_a, t_list **stack_b, char *mode)
{
	if (ft_strequ(mode, "ss"))
	{
		swap(stack_a, 0);
		swap(stack_b, 0);
		ft_printf("ss\n");
	}
	if (ft_strequ(mode, "rr"))
	{
		rotate(stack_a, 0);
		rotate(stack_b, 0);
		ft_printf("rr\n");
	}
	if (ft_strequ(mode, "rrr"))
	{
		rev_r(stack_a, 0);
		rev_r(stack_b, 0);
		ft_printf("rrr\n");
	}
}

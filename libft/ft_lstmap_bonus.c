/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:10:52 by prando-a          #+#    #+#             */
/*   Updated: 2023/07/18 14:03:08 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*a;
	t_list	*b;

	if (!lst)
		return (NULL);
	a = malloc(sizeof(t_list));
	if (!a)
		return (0);
	b = a;
	b->content = f(lst->content);
	while (lst->next)
	{
		lst = lst->next;
		b->next = malloc(sizeof(t_list));
		if (!b->next)
		{
			ft_lstclear(&a, del);
			return (0);
		}
		b->next->content = f(lst->content);
		b = b->next;
	}
	b->next = NULL;
	return (a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 19:36:50 by prando-a          #+#    #+#             */
/*   Updated: 2023/07/16 18:38:41 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	struct s_list	*p;

	if (!*lst)
		*lst = new;
	else
	{
		p = ft_lstlast(*lst);
		p->next = new;
	}
}

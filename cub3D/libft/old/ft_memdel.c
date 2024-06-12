/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:06:43 by prando-a          #+#    #+#             */
/*   Updated: 2023/09/11 18:53:45 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_memdel(void **ap)
{
	int	i;

	i = 0;
	while (ap[i])
		free(ap[i++]);
	free(ap);
	ap = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:21:44 by prando-a          #+#    #+#             */
/*   Updated: 2023/08/04 18:05:15 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	s;

	s = count * size;
	ptr = malloc(s);
	if (ptr == NULL)
		return (0);
	ft_bzero (ptr, s);
	return (ptr);
}

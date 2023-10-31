/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:08:01 by prando-a          #+#    #+#             */
/*   Updated: 2023/09/11 18:41:35 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_realloc(void *ptr, size_t new_size)
{
	void	*new_ptr;
	size_t	copy_size;

	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (free(ptr), NULL);
	copy_size = 0;
	if (ptr && new_ptr && new_size != 0)
	{
		if (new_size < sizeof(ptr))
			copy_size = new_size;
		else
			copy_size = sizeof(ptr);
		ft_memcpy(new_ptr, ptr, copy_size);
	}
	return (free(ptr), new_ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:22:37 by prando-a          #+#    #+#             */
/*   Updated: 2023/07/16 12:08:43 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, int n)
{
	int			i;
	char		*pdst;
	const char	*psrc;

	i = -1;
	pdst = dst;
	psrc = src;
	if (!pdst && !psrc && n > 0)
		return (0);
	while (++i < n)
		pdst[i] = psrc[i];
	return (dst);
}

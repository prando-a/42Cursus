/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 02:40:07 by prando-a          #+#    #+#             */
/*   Updated: 2023/08/30 13:41:20 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dst, const char *src, unsigned int dstsize)
{
	unsigned int			i;
	unsigned int			j;
	unsigned int			x;

	i = ft_strlen(dst);
	j = 0;
	x = i;
	if (dstsize <= i)
		return (ft_strlen(src) + dstsize);
	while (src[j] && j < (dstsize - x - 1))
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (x + ft_strlen(src));
}

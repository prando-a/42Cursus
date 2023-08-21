/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:34:58 by prando-a          #+#    #+#             */
/*   Updated: 2023/07/16 18:01:09 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*meleon;
	unsigned int		i;

	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	if (len + start > ft_strlen(s))
		len = ft_strlen(s) - start;
	meleon = (char *)ft_calloc(len + 1, sizeof(char));
	if (!meleon)
		return (0);
	i = 0;
	while (i < len)
		meleon[i++] = s[start++];
	return (meleon);
}

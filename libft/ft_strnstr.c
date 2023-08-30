/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:27:09 by prando-a          #+#    #+#             */
/*   Updated: 2023/08/30 13:42:41 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, unsigned int len)
{
	unsigned int			i;
	unsigned int			j;
	unsigned int			ln;

	i = 0;
	ln = ft_strlen((char *)needle);
	if (*needle == '\0')
		return ((char *)haystack);
	if (!*haystack || len < ln || len == 0)
		return (0);
	while (i <= len - ln && haystack[i])
	{
		j = 0;
		if (haystack[i] == needle[0])
		{
			while (haystack[i + j] == needle[j] && j < ln)
				j++;
			if (j == ln)
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (0);
}

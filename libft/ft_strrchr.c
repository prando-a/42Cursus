/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:09:11 by prando-a          #+#    #+#             */
/*   Updated: 2023/07/16 17:54:59 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s) + 1;
	while (--i)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}

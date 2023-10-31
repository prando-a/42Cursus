/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:03:12 by prando-a          #+#    #+#             */
/*   Updated: 2023/08/30 13:40:57 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*mander;
	unsigned int	i;

	if (!s1)
		return (0);
	i = -1;
	mander = (char *)ft_calloc((ft_strlen(s1) + 1), sizeof(char));
	if (mander == NULL)
		return (0);
	while (s1[++i])
		mander[i] = s1[i];
	return (mander);
}

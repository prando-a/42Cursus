/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:17:27 by prando-a          #+#    #+#             */
/*   Updated: 2023/12/22 18:22:39 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mander;
	int		i;
	int		j;

	mander = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	i = -1;
	j = 0;
	if (mander && s1)
	{
		while (s1[++i])
			mander[i] = s1[i];
	}
	while (mander && s2[j])
		mander[i++] = s2[j++];
	return (mander);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:17:27 by prando-a          #+#    #+#             */
/*   Updated: 2023/08/30 13:41:06 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mander;
	int		i;
	int		j;

	mander = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (mander == NULL)
		return (0);
	i = -1;
	j = 0;
	while (s1[++i])
		mander[i] = s1[i];
	while (s2[j])
		mander[i++] = s2[j++];
	return (mander);
}

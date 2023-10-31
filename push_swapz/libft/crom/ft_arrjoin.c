/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:45:28 by prando-a          #+#    #+#             */
/*   Updated: 2023/09/14 13:31:14 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**ft_arrjoin(char **a1, char **a2)
{
	char	**mander;
	int		i;
	int		j;

	mander = ft_calloc(ft_arrnum(a1) + ft_arrnum(a2) + 1, sizeof(char *));
	if (mander == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (a1[i])
	{
		mander[i] = ft_strdup(a1[i]);
		if (!mander[i++])
			return (ft_strdel(mander), NULL);
	}
	while (a2[j])
	{
		mander[i] = ft_strdup(a2[j++]);
		if (!mander[i++])
			return (ft_strdel(mander), NULL);
	}
	return (mander);
}

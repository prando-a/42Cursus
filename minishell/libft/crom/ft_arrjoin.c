/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:45:28 by prando-a          #+#    #+#             */
/*   Updated: 2023/12/20 16:12:38 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	arrjoin_free(char **a1, char **a2, int mode)
{
	if (mode == 1 || mode == 3)
		ft_strdel(a1);
	if (mode == 2 || mode == 3)
		ft_strdel(a2);
}

char	**ft_arrjoin(char **a1, char **a2, int mode)
{
	char	**mander;
	int		i;
	int		j;

	if (!a1 || !a2)
		return (ft_strdel(a1), ft_strdel(a2), NULL);
	mander = ft_calloc(ft_arrnum(a1) + ft_arrnum(a2) + 1, sizeof(char *));
	i = 0;
	j = 0;
	while (mander && a1[i])
	{
		mander[i] = ft_strdup(a1[i]);
		if (!mander[i++])
			return (ft_strdel(mander), NULL);
	}
	while (mander && a2[j])
	{
		mander[i] = ft_strdup(a2[j++]);
		if (!mander[i++])
			return (ft_strdel(mander), NULL);
	}
	return (arrjoin_free(a1, a2, mode), mander);
}

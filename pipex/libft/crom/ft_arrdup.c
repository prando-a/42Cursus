/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 20:22:06 by prando-a          #+#    #+#             */
/*   Updated: 2023/11/23 20:22:22 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**ft_arrdup(char **array)
{
	char	**mander;
	int		i;

	if (!array)
		return (NULL);
	mander = ft_calloc(ft_arrnum(array) + 1, sizeof(char *));
	if (!mander)
		return (NULL);
	i = 0;
	while (array[i])
	{
		mander[i] = ft_strdup(array[i]);
		if (!array[i++])
			return (ft_strdel(mander), NULL);
	}
	return (mander);
}

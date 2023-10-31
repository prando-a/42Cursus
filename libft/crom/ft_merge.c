/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crom <crom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 00:07:20 by prando-a          #+#    #+#             */
/*   Updated: 2023/10/23 00:29:22 by crom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	merge_scriptor(char **array, char *mander, char c, int len)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (array[j])
	{
		while (array[j][i])
			mander[k++] = array[j][i++];
		i = -1;
		while (array[j + 1] && ++i < len)
			mander[k++] = c;
		i = 0;
		j++;
	}
}

char	*ft_merge(char **array, char c, int len)
{
	char	*mander;
	int		s_len;

	s_len = 0;
	while (array[s_len])
	{
		if (!array[s_len++][0])
			return (NULL);
	}
	s_len = 0;
	if (c != '\0')
	{
		while (array[s_len])
			s_len++;
		s_len = (s_len - 1) * len;
	}
	else
		len = 0;
	s_len += ft_arrlen(array);
	mander = ft_calloc(s_len + 1, 1);
	if (!mander)
		return (NULL);
	return (merge_scriptor(array, mander, c, len), mander);
}

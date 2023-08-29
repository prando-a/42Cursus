/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 00:07:20 by prando-a          #+#    #+#             */
/*   Updated: 2023/08/28 17:11:20 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	arr_tostr(char **array, char *mander, char c, int len)
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
	if (!array)
		return (NULL);
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
	arr_tostr(array, mander, c, len);
	return (mander);
}

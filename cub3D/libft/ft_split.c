/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:29:06 by prando-a          #+#    #+#             */
/*   Updated: 2024/01/03 17:13:41 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wcnt(char const *s, char c, int i1, int w)
{
	while (s[i1])
	{
		if (s[i1] != c)
		{
			w++;
			while (s[i1] && s[++i1] != c)
				;
		}
		else
			i1++;
	}
	return (w);
}

char	*scriptor(char const *s, int k, int i, int len)
{
	int		i2;
	char	*meleon;

	len = i - k;
	i2 = 0;
	meleon = ft_calloc((len + 1), sizeof(char));
	if (meleon == NULL)
		return (NULL);
	while (k < i)
		meleon[i2++] = s[k++];
	return (meleon);
}

int	strict_pass(char **izard, int i3)
{
	while (izard[i3])
		free(izard[i3++]);
	free(izard);
	return (0);
}

int	core_while(t_indexes *cnt, const char *s, char **mander, char c)
{
	while (s[cnt->i] && s[++cnt->i] != c)
		;
	mander[cnt->j] = scriptor(s, cnt->k, cnt->i, 0);
	if (mander[cnt->j++] == NULL)
		return (strict_pass(mander, 0));
	cnt->k = cnt->i;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char		**mander;
	t_indexes	cnt;

	if (!s)
		return (0);
	cnt.i = 0;
	cnt.j = 0;
	cnt.k = 0;
	mander = ft_calloc((wcnt(s, c, 0, 0) + 1), sizeof(char *));
	if (mander == NULL)
		return (NULL);
	while (s[cnt.i])
	{
		if (s[cnt.i] != c)
		{
			if (core_while(&cnt, s, mander, c) == 0)
				return (NULL);
		}
		else
		{
			cnt.i++;
			cnt.k++;
		}
	}
	return (mander);
}

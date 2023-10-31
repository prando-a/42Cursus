/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:49:15 by prando-a          #+#    #+#             */
/*   Updated: 2023/09/11 18:36:24 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*mander;
	size_t	i;

	i = -1;
	mander = ft_calloc(ft_strlen(s) + 1, 1);
	if (!mander)
		return (NULL);
	while (s[++i])
		mander[i] = f(s[i]);
	return (mander);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 12:58:12 by prando-a          #+#    #+#             */
/*   Updated: 2023/12/22 18:25:17 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mander;
	size_t	i;

	i = -1;
	mander = ft_calloc(ft_strlen(s) + 1, 1);
	while (mander && s[++i])
		mander[i] = f(i, s[i]);
	return (mander);
}

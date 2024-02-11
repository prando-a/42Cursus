/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 20:25:51 by prando-a          #+#    #+#             */
/*   Updated: 2024/01/03 17:13:00 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_chrdel(char *str, char c, int del)
{
	int		i;
	int		len;
	char	*mander;	

	i = -1;
	len = 0;
	if (!str)
		return (NULL);
	while (str[++i])
	{
		if (str[i] != c)
			len++;
	}
	mander = ft_calloc(len + 1, 1);
	i = -1;
	len = 0;
	while (mander && str[++i])
	{
		if (str[i] != c)
			mander[len++] = str[i];
	}
	if (del)
		free(str);
	return (mander);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crom <crom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 14:08:47 by prando-a          #+#    #+#             */
/*   Updated: 2023/09/10 00:03:24 by crom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	cifras(long n, int i)
{
	if (n <= 0)
		i++;
	while (n != 0 && ++i)
		n /= 10;
	return (i);
}

char	*ft_itoa(int n)
{
	char		*mander;
	int			i;
	long		l;

	l = n;
	i = cifras(l, 0);
	mander = malloc(i + 1);
	if (mander == NULL)
		return (0);
	if (l == 0)
		mander[0] = '0';
	if (l < 0)
	{
		l = l * -1;
		mander[0] = '-';
	}
	mander[i] = '\0';
	while (l != 0)
	{
		mander[--i] = (l % 10) + '0';
		l /= 10;
	}
	return (mander);
}

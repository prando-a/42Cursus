/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:19:38 by prando-a          #+#    #+#             */
/*   Updated: 2024/04/30 22:20:01 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	cifras(long n, int i)
{
	if (n <= 0)
		i++;
	while (n != 0 && ++i)
		n /= 10;
	return (i);
}

char	*ft_itoa(ssize_t n)
{
	char			*mander;
	int				i;
	long long		l;

	l = n;
	i = cifras(l, 0);
	mander = ft_calloc(i + 1, 1);
	if (mander && l == 0)
		mander[0] = '0';
	if (mander && l < 0)
	{
		l = l * -1;
		mander[0] = '-';
	}
	while (mander && l != 0)
	{
		mander[--i] = (l % 10) + '0';
		l /= 10;
	}
	return (mander);
}
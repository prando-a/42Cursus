/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crom <crom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:21:09 by prando-a          #+#    #+#             */
/*   Updated: 2023/12/20 12:33:12 by crom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *s, int c, unsigned int n)
{
	unsigned int			i;
	const char				*p;

	p = s;
	i = -1;
	while (s && p && ++i < n)
	{
		if (p[i] == (char)c)
			return ((char *)&p[i]);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:21:09 by prando-a          #+#    #+#             */
/*   Updated: 2023/07/16 12:00:03 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *s, int c, unsigned int n)
{
	unsigned int			i;
	const char				*p;

	p = s;
	i = -1;
	while (++i < n)
	{
		if (p[i] == (char)c)
			return ((char *)&p[i]);
	}
	return (0);
}

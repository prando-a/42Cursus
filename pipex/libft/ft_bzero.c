/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crom <crom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:26:51 by prando-a          #+#    #+#             */
/*   Updated: 2023/12/20 12:32:26 by crom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_bzero(void *s, int n)
{
	unsigned char	*p;
	int				i;

	i = -1;
	p = s;
	while (p && s && ++i < n)
		p[i] = 0;
}

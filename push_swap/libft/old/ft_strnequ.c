/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:05:46 by prando-a          #+#    #+#             */
/*   Updated: 2023/09/11 18:40:27 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned int	i;
	unsigned int	a;

	i = 0;
	a = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] == s2[i])
			a++;
		i++;
	}
	return (i == a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linecounter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:34:14 by prando-a          #+#    #+#             */
/*   Updated: 2023/08/23 17:34:38 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_linecounter(char *str)
{
	int	i;
	int	fnd;

	i = 0;
	fnd = 0;
	if (*str)
		fnd++;
	while (str[i])
	{
		if (str[i++] == '\n')
			fnd++;
	}
	if (str[--i] == '\n')
		fnd--;
	return (fnd);
}
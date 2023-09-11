/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 01:21:53 by prando-a          #+#    #+#             */
/*   Updated: 2023/09/11 18:41:14 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_arrlen(char **array)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (array[i])
		len += ft_strlen(array[i++]);
	return (len);
}

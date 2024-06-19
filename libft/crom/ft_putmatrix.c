/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmatrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:37:35 by prando-a          #+#    #+#             */
/*   Updated: 2024/01/03 17:21:39 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putmatrix(char **arr)
{
	int	i;
	int	print_len;

	i = 0;
	print_len = 0;
	if (!arr)
		return (ft_printf("(null matrix)\n"));
	while (arr[i])
		print_len += ft_printf("%s\n", arr[i++]);
	return (print_len);
}

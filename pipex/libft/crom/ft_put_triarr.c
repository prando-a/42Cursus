/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_triarr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:11:51 by prando-a          #+#    #+#             */
/*   Updated: 2024/01/03 17:21:26 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_put_triarr(char ***tri)
{
	int	i;
	int	print_len;

	i = 0;
	print_len = 0;
	if (!tri)
		return (ft_printf("(tri_arr null)\n"));
	while (tri[i])
		print_len += ft_putmatrix(tri[i++]);
	return (print_len);
}

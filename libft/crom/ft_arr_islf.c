/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_islf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:56:50 by prando-a          #+#    #+#             */
/*   Updated: 2023/09/13 14:21:33 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_arr_islf(char **array)
{
	int	num_ok;
	int	float_ok;

	num_ok = 1;
	float_ok = 0;
	while (*array && num_ok)
	{
		if (!ft_str_islf(*array))
			num_ok--;
		else if (ft_str_islf(*array) == 2 && !float_ok)
			float_ok++;
		array++;
	}
	return (num_ok + float_ok);
}

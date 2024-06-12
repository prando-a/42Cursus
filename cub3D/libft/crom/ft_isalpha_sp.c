/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha_sp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:35:10 by prando-a          #+#    #+#             */
/*   Updated: 2024/01/15 20:35:47 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isalpha_spa(int c);

int	ft_isalnum_spa(int c)
{
	return (ft_isdigit(c) || ft_isalpha_spa(c));
}

int	ft_isalpha_spa(int c)
{
	static int	check;

	if (!check)
		check = (c == SPCHAR_FORMAT);
	else
	{
		check = !(c == n_TILDE || c == N_TILDE || c == u_UML
				|| c == a_ACUTE || c == A_ACUTE || c == e_ACUTE
				|| c == E_ACUTE || c == i_ACUTE || c == I_ACUTE
				|| c == o_ACUTE || c == O_ACUTE || c == u_ACUTE
				|| c == U_ACUTE);
		return (!check);
	}
	return (ft_isalpha(c) || check);
}

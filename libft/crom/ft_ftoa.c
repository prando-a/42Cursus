/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:32:42 by prando-a          #+#    #+#             */
/*   Updated: 2023/12/20 16:01:02 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*frac_to_str(float frac, int digits)
{
	long long int	frac_int;
	long long int	multiplier;

	multiplier = 1;
	while (digits--)
		multiplier *= 10;
	frac_int = (frac * (multiplier));
	return (ft_lltoa(frac_int));
}

char	*ft_ftoa(float n, int digits)
{
	int		integer;
	float	frac;
	char	*mander;
	char	*frac_a;

	integer = (int)n;
	frac = n - integer;
	mander = gnl_strjoin(ft_itoa(integer), ".", 1, 0);
	if (!mander)
		return (NULL);
	frac_a = frac_to_str(frac, digits);
	if (!frac_a)
		return (NULL);
	mander = gnl_strjoin(mander, frac_a, 3, 0);
	if (!mander)
		return (free(frac_a), NULL);
	return (mander);
}

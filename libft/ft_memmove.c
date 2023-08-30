/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:31:31 by prando-a          #+#    #+#             */
/*   Updated: 2023/08/30 13:39:15 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dst, const void *src, int len)
{
	char		*pdst;
	const char	*psrc;
	int			i;

	pdst = dst;
	psrc = src;
	i = -1;
	if (!pdst && !psrc && len > 0)
		return (0);
	if (pdst > psrc)
	{
		while (len-- > 0)
			pdst[len] = psrc[len];
	}
	else
	{
		while (++i < len)
			pdst[i] = psrc[i];
	}
	return (dst);
}

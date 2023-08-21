/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 10:55:16 by prando-a          #+#    #+#             */
/*   Updated: 2023/08/21 17:07:02 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *b, int c, int len)
{
	int		i;
	char	*b2;

	b2 = b;
	i = -1;
	while (++i < len)
		b2[i] = c;
	return (b);
}

/*int a;
int *ptra;
int *ptrptra;

a = 12;
ptra = &a;
*ptra = 15;
ptrptra = ptra;
*ptrptra = 20;*/
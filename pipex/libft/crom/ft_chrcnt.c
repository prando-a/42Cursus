/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrcnt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:22:52 by prando-a          #+#    #+#             */
/*   Updated: 2024/01/03 17:26:16 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_chrcnt(char *str, char c)
{
	int	i;
	int	fnd;

	i = -1;
	fnd = 0;
	if (str && !str[0])
		return (1);
	while (str && str[++i])
	{
		if (str[i] == c)
			fnd++;
	}
	return (fnd);
}

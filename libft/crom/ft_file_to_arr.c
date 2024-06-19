/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_to_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:33:00 by prando-a          #+#    #+#             */
/*   Updated: 2023/12/22 18:30:38 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**ft_file_to_arr(int fd)
{
	char	*str;
	char	**mander;

	str = ft_file_to_str(fd);
	mander = ft_split(str, '\n');
	if (!mander)
		return (free(str), NULL);
	return (free(str), mander);
}

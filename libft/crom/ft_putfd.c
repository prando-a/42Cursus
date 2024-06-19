/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:11:33 by prando-a          #+#    #+#             */
/*   Updated: 2024/01/03 17:11:34 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putfd(int fd)
{
	char	*str;
	int		bytes;

	str = ft_file_to_str(fd);
	bytes = ft_printf(str);
	if (str)
		free(str);
	return (bytes);
}

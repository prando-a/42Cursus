/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crom <crom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:33:05 by prando-a          #+#    #+#             */
/*   Updated: 2023/12/31 02:16:02 by crom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_file_to_str(int fd)
{
	char	*raw;
	char	*line;

	raw = NULL;
	line = get_next_line(fd);
	while (line)
	{
		raw = gnl_strjoin(raw, line, 3, 1);
		if (!raw)
			return (NULL);
		line = get_next_line(fd);
	}
	return (raw);
}

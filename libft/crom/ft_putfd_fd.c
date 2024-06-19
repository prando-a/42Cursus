/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfd_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:25:55 by prando-a          #+#    #+#             */
/*   Updated: 2024/01/15 20:35:55 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putfd_fd(int fd_src, int fd_dst)
{
	char	*str;

	str = ft_file_to_str(fd_src);
	ft_putstr_fd(str, fd_dst);
	if (str)
		free(str);
}

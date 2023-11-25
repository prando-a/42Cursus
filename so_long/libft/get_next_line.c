/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:22:15 by prando-a          #+#    #+#             */
/*   Updated: 2023/11/25 15:40:14 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gnl_strjoin(char *s1, char *s2, int mode)
{
	char	*mander;
	int		i;
	int		j;

	mander = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!mander)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		mander[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		mander[i++] = s2[j++];
	if (mode == 1 || mode == 3)
		free(s1);
	if (mode == 2 || mode == 3)
		free(s2);
	return (mander);
}

char	*keeper(char *static_s)
{
	char	*get_chr;

	get_chr = ft_strdup(ft_strchr(static_s, '\n'));
	free(static_s);
	if (get_chr)
		static_s = ft_strdup(get_chr + 1);
	else
		static_s = NULL;
	return (free(get_chr), static_s);
}

char	*reader(char *static_s, int fd)
{
	int				bytes_read;
	char			*buffer;

	if (!static_s)
		static_s = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(static_s, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), free(static_s), NULL);
		buffer[bytes_read] = '\0';
		static_s = gnl_strjoin(static_s, buffer, 1);
		if (!*static_s)
			return (free(static_s), free(buffer), buffer = NULL, NULL);
	}
	return (free(buffer), static_s);
}

char	*get_next_line(int fd)
{
	static char		*static_s[2048];
	char			*line;
	int				i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	static_s[fd] = reader(static_s[fd], fd);
	if (!static_s[fd])
		return (NULL);
	i = 0;
	while (static_s[fd][i] != '\n' && static_s[fd][i])
		i++;
	line = ft_substr(static_s[fd], 0, i + 1);
	static_s[fd] = keeper(static_s[fd]);
	return (line);
}

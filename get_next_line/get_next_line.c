/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:22:15 by prando-a          #+#    #+#             */
/*   Updated: 2023/08/30 13:49:42 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *s1)
{
	char			*mander;
	unsigned int	i;

	if (!s1)
		return (NULL);
	i = -1;
	mander = (char *)ft_calloc((ft_strlen(s1) + 1), sizeof(char));
	if (!mander)
		return (NULL);
	while (s1[++i])
		mander[i] = s1[i];
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
		if (!static_s)
			static_s = ft_calloc(1, 1);
		static_s = gnl_strjoin(static_s, buffer);
		if (!*static_s)
			return (free(static_s), free(buffer), buffer = NULL, NULL);
	}
	return (free(buffer), static_s);
}

char	*get_next_line(int fd)
{
	static char		*static_s;
	char			*line;
	int				i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	static_s = reader(static_s, fd);
	if (!static_s)
		return (NULL);
	i = 0;
	while (static_s[i] != '\n' && static_s[i])
		i++;
	line = ft_substr(static_s, 0, i + 1);
	static_s = keeper(static_s);
	return (line);
}

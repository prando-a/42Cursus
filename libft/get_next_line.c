/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crom <crom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:22:15 by prando-a          #+#    #+#             */
/*   Updated: 2023/12/31 02:12:54 by crom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gnl_strjoin(char *s1, char *s2, int mode, int init)
{
	char	*mander;
	int		i;

	if (!s1 && init)
		s1 = ft_calloc(1, 1);
	if (!s1 || !s2)
		return (NULL);
	mander = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	i = -1;
	while (mander && s1[++i])
		mander[i] = s1[i];
	--i;
	while (mander && s2[++i - ft_strlen(s1)])
		mander[i] = s2[i - ft_strlen(s1)];
	if (mode == 1 || mode == 3)
		free(s1);
	if (mode == 2 || mode == 3)
		free(s2);
	return (mander);
}

char	*keeper(char *static_s)
{
	char	*get_chr;

	get_chr = ft_strchr(static_s, '\n');
	if (get_chr)
	{
		get_chr = ft_strdup(ft_strchr(static_s, '\n') + 1);
		if (!get_chr)
			return (free(static_s), NULL);
		return (free(static_s), static_s = NULL, get_chr);
	}
	else
		return (free(static_s), NULL);
}

char	*reader(char *static_s, int fd)
{
	int				bytes_read;
	char			*buffer;

	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return (free(static_s), NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(static_s, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), free(static_s), NULL);
		buffer[bytes_read] = '\0';
		static_s = gnl_strjoin(static_s, buffer, 1, 1);
		if (!static_s || !*static_s)
			return (free(static_s), free(buffer), NULL);
	}
	return (free(buffer), static_s);
}

char	*get_next_line(int fd)
{
	static char		*static_s;
	char			*line;
	int				i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (free(static_s), NULL);
	static_s = reader(static_s, fd);
	if (!static_s)
		return (NULL);
	i = 0;
	while (static_s[i] != '\n' && static_s[i])
		i++;
	line = ft_substr(static_s, 0, i + 1);
	if (!line)
		return (free(static_s), static_s = NULL, NULL);
	static_s = keeper(static_s);
	if (!static_s)
		return (free(static_s), static_s = NULL, line);
	return (line);
}

char	*get_next_line_bonus(int fd)
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
	if (!line)
		return (free(static_s[fd]), static_s[fd] = NULL, NULL);
	static_s[fd] = keeper(static_s[fd]);
	if (!static_s[fd])
		return (free(static_s[fd]), static_s[fd] = NULL, line);
	return (line);
}

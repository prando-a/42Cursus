/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:54:26 by prando-a          #+#    #+#             */
/*   Updated: 2023/09/10 15:34:39 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			s;
	size_t			i;

	s = count * size;
	ptr = malloc(s);
	if (!ptr)
		return (0);
	i = 0;
	while (i < s)
		ptr[i++] = 0;
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*meleon;
	unsigned int		i;

	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	if (len + start > ft_strlen(s))
		len = ft_strlen(s) - start;
	meleon = (char *)ft_calloc(len + 1, sizeof(char));
	if (!meleon)
		return (0);
	i = 0;
	while (i < len)
		meleon[i++] = s[start++];
	return (meleon);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*mander;
	int		i;
	int		j;

	mander = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (mander == NULL)
		return (0);
	i = -1;
	j = 0;
	while (s1[++i])
		mander[i] = s1[i];
	while (s2[j])
		mander[i++] = s2[j++];
	free(s1);
	return (mander);
}

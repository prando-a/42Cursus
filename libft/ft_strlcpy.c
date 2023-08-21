/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 01:01:48 by prando-a          #+#    #+#             */
/*   Updated: 2023/07/24 13:55:53 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		i;

	i = 0;
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

/*#include<stdio.h>
#include<string.h>
#include<stdlib.h> 

int main(int argc, char *argv[]) {
    (void)argc;
    char cuteria[500];
    strcpy(cuteria, argv[1]);
    const char* anga = argv[2];
    int egral_uno = atoi(argv[3]);
    printf("%d", ft_strlcpy(cuteria, anga, egral_uno));
    printf ("\n%s\n%s", cuteria, anga);
}*/
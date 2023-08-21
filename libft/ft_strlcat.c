/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 02:40:07 by prando-a          #+#    #+#             */
/*   Updated: 2023/07/24 17:05:26 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "libft.h"

int	ft_strlcat(char *dst, const char *src, unsigned int dstsize)
{
	unsigned int			i;
	unsigned int			j;
	unsigned int			x;

	i = ft_strlen(dst);
	j = 0;
	x = i;
	if (dstsize <= i)
		return (ft_strlen(src) + dstsize);
	while (src[j] && j < (dstsize - x - 1))
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (x + ft_strlen(src));
}

/*int main(int argc, char *argv[]) {
    (void)argc;
    char destino[500];
    strcpy(destino, argv[1]);
    const char* fuente = argv[2];
    int egral_uno = atoi(argv[3]);
    printf("%d", ft_strlcat(destino, fuente, egral_uno));
    printf ("\n%s\n%s", destino, fuente);
}*/
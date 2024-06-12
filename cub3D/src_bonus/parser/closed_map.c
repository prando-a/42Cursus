/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closed_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:19:41 by prando-a          #+#    #+#             */
/*   Updated: 2024/05/26 04:47:31 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	write_to_aux(char **map, char **res, int i, int max_len)
{
	int			j;
	int			k;
	static int	l;

	if (!res[0])
		return (0);
	res[++l] = ft_calloc(ft_strlen(map[i]) + 3 + (max_len - ft_strlen(map[i])),
			sizeof(char));
	if (!res[l])
		return (0);
	j = -1;
	k = 1;
	res[l][0] = ' ';
	while (map[i][++j])
		res[l][k++] = map[i][j];
	while (j++ <= max_len)
		res[l][k++] = ' ';
	return (1);
}

char	**get_aux(char **map, int i, int j, int max_len)
{
	char	**res;

	res = ft_calloc(ft_arrnum(map) + 3, sizeof(char *));
	while (map[++i])
		if ((int)ft_strlen(map[i]) > max_len)
			max_len = ft_strlen(map[i]);
	res[0] = ft_calloc(max_len + 3, sizeof(char));
	i = -1;
	while (res && res[0] && ++i < (max_len + 2))
		res[0][i] = ' ';
	i = 0;
	while (res && map[i])
		if (!write_to_aux(map, res, i++, max_len))
			return (ft_strdel(res), NULL);
	res[ft_arrnum(map) + 1] = ft_calloc(max_len + 3, sizeof(char));
	if (!res[ft_arrnum(map) + 1])
		return (ft_strdel(res), NULL);
	j = -1;
	while (++j < (max_len + 2))
		res[ft_arrnum(map) + 1][j] = ' ';
	return (res);
}

int	flood_fill(char **aux, int y, int x, int *space_flag)
{
	if (x > -1 && x < (int)ft_strlen(aux[0]) && y > -1 && y < ft_arrnum(aux)
		&& aux[y][x] && aux[y][x] != '1' && aux[y][x] != 'F')
	{
		if (aux[y][x] == ' ')
			*space_flag = 1;
		aux[y][x] = 'F';
		flood_fill(aux, y + 1, x, space_flag);
		flood_fill(aux, y - 1, x, space_flag);
		flood_fill(aux, y, x + 1, space_flag);
		flood_fill(aux, y, x - 1, space_flag);
	}
	return (1);
}

int	smart_fill(char **aux, int mode)
{
	int	i;
	int	j;
	int	space_flag;

	i = 0;
	space_flag = 0;
	if (!aux)
		return (cub_error("Error getting sub-auxiliar map"), 0);
	while (aux[i])
	{
		j = 0;
		while (aux[i][j])
		{
			if (aux[i][j] == '0')
				if (flood_fill(aux, i, j, &space_flag)
					&& mode == 1 && space_flag)
					return (cub_error("Space found on filling zone"),
						ft_strdel(aux), 0);
			j++;
		}
		i++;
	}
	if (mode == 0 && aux[0][0] == 'F')
		return (cub_error("Map is not closed"), ft_strdel(aux), 0);
	return (ft_strdel(aux), 1);
}

int	closed_map(t_map *m)
{
	char	**aux;

	aux = get_aux(m->map, -1, -1, 0);
	if (!aux)
		return (cub_error("Error getting auxiliar map"), 0);
	if (!smart_fill(ft_arrdup(aux), 0))
		return (ft_strdel(aux), 0);
	if (!smart_fill(ft_arrdup(aux), 1))
		return (ft_strdel(aux), 0);
	ft_strdel(m->map);
	m->map = aux;
	return (1);
}

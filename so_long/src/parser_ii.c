/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_ii.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:09:50 by prando-a          #+#    #+#             */
/*   Updated: 2023/11/24 12:00:55 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_player_pos(t_mapdata **map, int y, int x)
{
	(*map)->player++;
	(*map)->player_posx = x;
	(*map)->player_posy = y;
}

int	check_items(t_mapdata **map)
{
	int	i;
	int	j;

	j = -1;
	while ((*map)->map[++j])
	{
		i = -1;
		while ((*map)->map[j][++i])
		{
			if ((*map)->map[j][i] == 'C')
				(*map)->collectibles++;
			if ((*map)->map[j][i] == 'E')
				(*map)->exit++;
			if ((*map)->map[j][i] == 'P')
				set_player_pos(map, j, i);
		}
	}
	if ((*map)->collectibles < 1)
		return ((*map)->error = 5, 0);
	if ((*map)->exit != 1)
		return ((*map)->error = 6, 0);
	if ((*map)->player != 1)
		return ((*map)->error = 7, 0);
	return (1);
}

int	can_be_solved(char **aux)
{
	int	i;
	int	j;

	j = -1;
	while (aux[++j])
	{
		i = -1;
		while (aux[j][++i])
		{
			if (aux[j][i] == 'C' || aux[j][i] == 'E'
				|| aux[j][i] == 'P')
				return (0);
		}
	}
	return (1);
}

void	flood_fill(char **aux, int y, int x)
{
	if (aux[y][x] != '1' && aux[y][x] != 'F')
	{
		aux[y][x] = 'F';
		flood_fill(aux, y + 1, x);
		flood_fill(aux, y - 1, x);
		flood_fill(aux, y, x + 1);
		flood_fill(aux, y, x - 1);
	}
}

int	solve_check(t_mapdata **map)
{
	char	**auxmap;

	auxmap = ft_arrdup((*map)->map);
	if (!auxmap)
		return ((*map)->error = 2, 0);
	flood_fill(auxmap, (*map)->player_posy, (*map)->player_posx);
	if (!can_be_solved(auxmap))
		return ((*map)->error = 9, ft_strdel(auxmap), 0);
	return (ft_strdel(auxmap), 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:21:32 by prando-a          #+#    #+#             */
/*   Updated: 2024/05/26 04:47:03 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	valid_chars(char **map)
{
	int	i;
	int	j;
	int	k;

	k = 1;
	i = -1;
	while (map[++i] && k != 0)
	{
		j = -1;
		while (map[i][++j] && k != 0)
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W'
				|| map[i][j] == '1' || map[i][j] == '0'
				|| map[i][j] == ' ' || map[i][j] == 'D')
				k = 1;
			else
				k = 0;
		}
	}
	if (k == 0)
		return (cub_error("Invalid characters in map"), 0);
	return (1);
}

int	set_player_pos(t_map *map)
{
	int	i;
	int	j;
	int	init_pos;

	init_pos = 0;
	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'N' || map->map[i][j] == 'S'
				|| map->map[i][j] == 'E' || map->map[i][j] == 'W')
			{
				init_pos++;
				map->player_pos.x = j + 0.5;
				map->player_pos.y = i + 0.5;
			}
		}
	}
	if (init_pos != 1)
		return (cub_error("Missing start position or more than one"), 0);
	return (1);
}

int	get_map(t_map *map, char **file)
{
	int		x;
	int		y;

	map->map = extract_map(file);
	if (!map->map)
		return (0);
	if (ft_arrnum(map->map) < 3)
		return (cub_error("Bad map dimensions, or not closed at 1st line"), 0);
	if (!valid_chars(map->map) || !closed_map(map) || !set_player_pos(map)
		|| !cub_check_doors(map->map))
		return (ft_strdel(map->map), 0);
	x = map->player_pos.x;
	y = map->player_pos.y;
	if (map->map[y][x] == 'N')
		map->g = N;
	if (map->map[y][x] == 'E')
		map->g = E;
	if (map->map[y][x] == 'S')
		map->g = S;
	if (map->map[y][x] == 'W')
		map->g = W;
	map->map[y][x] = '0';
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:24:20 by prando-a          #+#    #+#             */
/*   Updated: 2024/05/28 04:09:13 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3D.h"

int	door_correct_pos(char **map, int y, int x)
{
	if (map[y][x + 1] == '1' && map[y][x - 1] == '1')
	{
		if (map[y + 1][x] == '1' || map[y - 1][x] == '1')
			return (cub_error("Found unaccesible door or leading to wall"), 0);
	}
	else if (map[y + 1][x] == '1' && map[y - 1][x] == '1')
	{
		if (map[y][x + 1] == '1' || map[y][x - 1] == '1')
			return (cub_error("Found unaccesible door or leading to wall"), 0);
	}
	else
		return (cub_error("Found door in invalid position"), 0);
	return (1);
}

int	cub_check_doors(char **map)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'D')
			{
				if (!door_correct_pos(map, y, x))
					return (0);
			}
		}
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_qmaps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-27 18:43:04 by prando-a          #+#    #+#             */
/*   Updated: 2024-05-27 18:43:04 by prando-a         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	fill_q1(char **map, int height)
{
	int	y;
	int	x;

	y = 0;
	(void)height;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1' && x > 0 && y > 0 && y < height
				&& map[y + 1][x - 1] == '1'
				&& (map[y + 1][x] == '0')
				&& (map[y][x - 1] == '0' || map[y][x - 1] == ' '))
				map[y][x - 1] = '2';
			x++;
		}
		y++;
	}
}

void	fill_q2(char **map, int height)
{
	int	y;
	int	x;

	y = 0;
	(void)height;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1' && x > 0 && y > 0 && y < height
				&& map[y + 1][x + 1] == '1'
				&& (map[y + 1][x] == '0')
				&& (map[y][x + 1] == '0' || map[y][x + 1] == ' '))
				map[y][x + 1] = '2';
			x++;
		}
		y++;
	}
}

void	fill_q3(char **map, int height)
{
	int	y;
	int	x;

	y = 0;
	(void)height;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1' && x > 0 && y > 0 && y < height
				&& map[y + 1][x - 1] == '1'
				&& (map[y][x - 1] == '0')
				&& (map[y + 1][x] == '0' || map[y + 1][x] == ' '))
				map[y + 1][x] = '2';
			x++;
		}
		y++;
	}
}

void	fill_q4(char **map, int height)
{
	int	y;
	int	x;

	y = 0;
	(void)height;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1' && x > 0 && y > 0 && y < height
				&& map[y + 1][x + 1] == '1'
				&& (map[y][x + 1] == '0')
				&& (map[y + 1][x] == '0' || map[y + 1][x] == ' '))
				map[y + 1][x] = '2';
			x++;
		}
		y++;
	}
}

void	init_maps(t_cub *cub)
{
	cub->map.maps[Q1] = ft_arrdup(cub->map.map);
	cub->map.maps[Q2] = ft_arrdup(cub->map.map);
	cub->map.maps[Q3] = ft_arrdup(cub->map.map);
	cub->map.maps[Q4] = ft_arrdup(cub->map.map);
	fill_q1(cub->map.maps[Q1], cub->map.height);
	fill_q2(cub->map.maps[Q2], cub->map.height);
	fill_q3(cub->map.maps[Q3], cub->map.height);
	fill_q4(cub->map.maps[Q4], cub->map.height);
}

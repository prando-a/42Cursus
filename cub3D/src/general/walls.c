/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-27 16:38:55 by prando-a          #+#    #+#             */
/*   Updated: 2024-05-27 16:38:55 by prando-a         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	check_wall_w(t_cub *cub)
{
	t_point	pos;
	char	**map;
	char	cpy;

	pos = cub->map.player_pos;
	map = choose_map_for_check_w(cub);
	cpy = map[(int)cub->map.player_pos.y][(int)cub->map.player_pos.x];
	map[(int)cub->map.player_pos.y][(int)cub->map.player_pos.x] = '0';
	if (((map[(int)(pos.y - ((cub->mv_speed + 0.2) \
	* cos(cub->map.g * M_PI / 180)))][(int)(pos.x + ((cub->mv_speed + 0.2) \
	* sin(cub->map.g * M_PI / 180)))] == '1'
		|| map[(int)(pos.y - ((cub->mv_speed + 0.2)
		* cos(cub->map.g * M_PI / 180)))][(int)(pos.x + ((cub->mv_speed + 0.2)
		* sin(cub->map.g * M_PI / 180)))] == 'D')
		|| (map[(int)(pos.y - ((cub->mv_speed + 0.2)
		* cos(cub->map.g * M_PI / 180)))][(int)(pos.x + ((cub->mv_speed + 0.2)
		* sin(cub->map.g * M_PI / 180)))] == '2')))
		return (map[(int)pos.y][(int)pos.x] = cpy, 0);
	return (map[(int)pos.y][(int)pos.x] = cpy, 1);
}

int	check_wall_a(t_cub *cub)
{
	t_point	pos;
	char	**map;
	char	cpy;

	pos = cub->map.player_pos;
	map = choose_map_for_check_a(cub);
	cpy = map[(int)cub->map.player_pos.y][(int)cub->map.player_pos.x];
	map[(int)cub->map.player_pos.y][(int)cub->map.player_pos.x] = '0';
	if (((map[(int)(pos.y - ((cub->mv_speed + 0.2) \
	* sin(cub->map.g * M_PI / 180)))][(int)(pos.x - ((cub->mv_speed + 0.2) \
	* cos(cub->map.g * M_PI / 180)))] == '1'
		|| map[(int)(pos.y - ((cub->mv_speed + 0.2)
		* sin(cub->map.g * M_PI / 180)))][(int)(pos.x - ((cub->mv_speed + 0.2)
		* cos(cub->map.g * M_PI / 180)))] == 'D')
		|| (map[(int)(pos.y - ((cub->mv_speed + 0.2)
		* sin(cub->map.g * M_PI / 180)))][(int)(pos.x - ((cub->mv_speed + 0.2)
		* cos(cub->map.g * M_PI / 180)))] == '2')))
		return (map[(int)pos.y][(int)pos.x] = cpy, 0);
	return (map[(int)pos.y][(int)pos.x] = cpy, 1);
}

int	check_wall_s(t_cub *cub)
{
	t_point	pos;
	char	**map;
	char	cpy;

	pos = cub->map.player_pos;
	map = choose_map_for_check_s(cub);
	cpy = map[(int)cub->map.player_pos.y][(int)cub->map.player_pos.x];
	map[(int)cub->map.player_pos.y][(int)cub->map.player_pos.x] = '0';
	if (((map[(int)(pos.y + ((cub->mv_speed + 0.2) \
	* cos(cub->map.g * M_PI / 180)))][(int)(pos.x - ((cub->mv_speed + 0.2) \
	* sin(cub->map.g * M_PI / 180)))] == '1'
		|| map[(int)(pos.y + ((cub->mv_speed + 0.2)
		* cos(cub->map.g * M_PI / 180)))][(int)(pos.x - ((cub->mv_speed + 0.2)
		* sin(cub->map.g * M_PI / 180)))] == 'D')
		|| (map[(int)(pos.y + ((cub->mv_speed + 0.2)
		* cos(cub->map.g * M_PI / 180)))][(int)(pos.x - ((cub->mv_speed + 0.2)
		* sin(cub->map.g * M_PI / 180)))] == '2')))
		return (map[(int)pos.y][(int)pos.x] = cpy, 0);
	return (map[(int)pos.y][(int)pos.x] = cpy, 1);
}

int	check_wall_d(t_cub *cub)
{
	t_point	pos;
	char	**map;
	char	cpy;

	pos = cub->map.player_pos;
	map = choose_map_for_check_d(cub);
	cpy = map[(int)cub->map.player_pos.y][(int)cub->map.player_pos.x];
	map[(int)cub->map.player_pos.y][(int)cub->map.player_pos.x] = '0';
	if (((map[(int)(pos.y + ((cub->mv_speed + 0.2) \
	* sin(cub->map.g * M_PI / 180)))][(int)(pos.x + ((cub->mv_speed + 0.2) \
	* cos(cub->map.g * M_PI / 180)))] == '1'
		|| map[(int)(pos.y + ((cub->mv_speed + 0.2)
		* sin(cub->map.g * M_PI / 180)))][(int)(pos.x + ((cub->mv_speed + 0.2)
		* cos(cub->map.g * M_PI / 180)))] == 'D')
		|| (map[(int)(pos.y + ((cub->mv_speed + 0.2)
		* sin(cub->map.g * M_PI / 180)))][(int)(pos.x + ((cub->mv_speed + 0.2)
		* cos(cub->map.g * M_PI / 180)))] == '2')))
		return (map[(int)pos.y][(int)pos.x] = cpy, 0);
	return (map[(int)pos.y][(int)pos.x] = cpy, 1);
}

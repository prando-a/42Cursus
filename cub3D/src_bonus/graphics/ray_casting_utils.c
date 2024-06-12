/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:24:33 by jose-mgo          #+#    #+#             */
/*   Updated: 2024/05/28 04:41:24 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

double	get_distance(double x, double y, t_cub *cub)
{
	double	distance;

	distance = sqrt(pow(cub->map.player_pos.x - x, 2)
			+ pow(cub->map.player_pos.y - y, 2));
	return (distance);
}

char	**choose_actual_map(t_cub *cub, double ray)
{
	if (ray >= 0 && ray < M_PI / 2)
		return (cub->map.maps[Q2]);
	if (ray >= M_PI / 2 && ray < M_PI)
		return (cub->map.maps[Q3]);
	if (ray >= M_PI && ray < 3 * M_PI / 2)
		return (cub->map.maps[Q4]);
	if (ray >= 3 * M_PI / 2 && ray < 2 * M_PI)
		return (cub->map.maps[Q1]);
	return (cub->map.map);
}

void	change_pos(t_cub *cub, char change[4], t_point pos)
{
	cub->map.maps[Q1][(int)pos.y][(int)pos.x] = change[0];
	cub->map.maps[Q2][(int)pos.y][(int)pos.x] = change[1];
	cub->map.maps[Q3][(int)pos.y][(int)pos.x] = change[2];
	cub->map.maps[Q4][(int)pos.y][(int)pos.x] = change[3];
}

void	ch_ray_val(t_point *pos, double val, double ray, int mode)
{
	if (mode == SUM)
	{
		pos->x += (val * sin(ray));
		pos->y += (val * cos(ray) * -1);
	}
	else
	{
		pos->x -= (val * sin(ray));
		pos->y -= (val * cos(ray) * -1);
	}
}

void	ray_iteration2(t_raycast *rc, char **map)
{
	while (rc->pos.x > 0 && rc->pos.y > 0 && rc->pos.x < rc->width
		&& rc->pos.y < rc->height && rc->bl == 0
		&& map[(int)rc->pos.y][(int)rc->pos.x] != '1'
		&& map[(int)rc->pos.y][(int)rc->pos.x] != 'D')
		ch_ray_val(&rc->pos, 0.0001, rc->ray, SUM);
	while (rc->pos.x > 0 && rc->pos.y > 0 && rc->pos.x < rc->width
		&& rc->pos.y < rc->height && rc->bl == 0
		&& map[(int)rc->pos.y][(int)rc->pos.x] != '0'
		&& map[(int)rc->pos.y][(int)rc->pos.x] != 'd')
		ch_ray_val(&rc->pos, 0.00001, rc->ray, DIF);
}

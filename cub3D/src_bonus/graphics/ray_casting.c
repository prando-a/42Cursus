/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:24:33 by jose-mgo          #+#    #+#             */
/*   Updated: 2024/05/28 04:55:03 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	ray_iteration(t_raycast *rc, char **map)
{
	while (rc->bl == 1 && map[(int)rc->pos.y][(int)rc->pos.x] != '2'
		&& map[(int)rc->pos.y][(int)rc->pos.x] != ' ')
		ch_ray_val(&rc->pos, 0.1, rc->ray, DIF);
	while (rc->bl == 1 && map[(int)rc->pos.y][(int)rc->pos.x] != '0'
		&& map[(int)rc->pos.y][(int)rc->pos.x] != ' ')
		ch_ray_val(&rc->pos, 0.01, rc->ray, DIF);
	while (rc->bl == 1 && map[(int)rc->pos.y][(int)rc->pos.x] != '1'
		&& map[(int)rc->pos.y][(int)rc->pos.x] != ' ')
		ch_ray_val(&rc->pos, 0.001, rc->ray, SUM);
	while (rc->bl == 1 && map[(int)rc->pos.y][(int)rc->pos.x] != '0'
		&& map[(int)rc->pos.y][(int)rc->pos.x] != ' ')
		ch_ray_val(&rc->pos, 0.00001, rc->ray, DIF);
	while (rc->pos.x > 0 && rc->pos.y > 0 && rc->pos.x < rc->width
		&& rc->pos.y < rc->height && rc->bl == 0
		&& map[(int)rc->pos.y][(int)rc->pos.x] != '0'
		&& map[(int)rc->pos.y][(int)rc->pos.x] != 'd')
		ch_ray_val(&rc->pos, 0.001, rc->ray, DIF);
	ray_iteration2(rc, map);
}

void	ray_casting_common(t_cub *cub, t_raycast *rc, t_point player)
{
	char	cpy[4];
	char	zero[4];

	ft_memset(zero, '0', 4);
	rc->bl = 0;
	cub->boolean_door = 0;
	rc->map = choose_actual_map(cub, rc->ray);
	cpy[Q1] = cub->map.maps[Q1][(int)player.y][(int)player.x];
	cpy[Q2] = cub->map.maps[Q2][(int)player.y][(int)player.x];
	cpy[Q3] = cub->map.maps[Q3][(int)player.y][(int)player.x];
	cpy[Q4] = cub->map.maps[Q4][(int)player.y][(int)player.x];
	change_pos(cub, zero, player);
	while (rc->bl == 0 && rc->map[(int)rc->pos.y][(int)rc->pos.x] != '1'
		&& rc->map[(int)rc->pos.y][(int)rc->pos.x] != 'D'
		&& rc->map[(int)rc->pos.y][(int)rc->pos.x] != '2'
		&& rc->map[(int)rc->pos.y][(int)rc->pos.x] != ' ')
		ch_ray_val(&rc->pos, 0.05, rc->ray, SUM);
	if (rc->map[(int)rc->pos.y][(int)rc->pos.x] == '2')
		rc->bl = 1;
	if (rc->map[(int)rc->pos.y][(int)rc->pos.x] == 'D')
		cub->boolean_door = 1;
	while (rc->bl == 1 && rc->map[(int)rc->pos.y][(int)rc->pos.x] != '2')
		ch_ray_val(&rc->pos, 0.1, rc->ray, DIF);
	ray_iteration(rc, rc->map);
	change_pos(cub, cpy, cub->map.player_pos);
}

void	ray_casting_l(t_cub *cub, t_raycast *rc, int times)
{
	while (++times <= PIXEL_X / 2)
	{
		rc->pos.x = cub->map.player_pos.x;
		rc->pos.y = cub->map.player_pos.y;
		ray_casting_common(cub, rc, cub->map.player_pos);
		put_images(PIXEL_X / 2 - times, rc->pos, cub, rc->ray);
		rc->ray -= (M_PI / 180) / 120 * 8;
		cub->rays[PIXEL_X / 2 - times].x = rc->pos.x;
		cub->rays[PIXEL_X / 2 - times].y = rc->pos.y;
	}
}

void	ray_casting_r(t_cub *cub, t_raycast *rc, int times)
{
	while (++times < PIXEL_X / 2)
	{
		rc->pos.x = cub->map.player_pos.x;
		rc->pos.y = cub->map.player_pos.y;
		ray_casting_common(cub, rc, cub->map.player_pos);
		put_images(PIXEL_X / 2 + times, rc->pos, cub, rc->ray);
		rc->ray += (M_PI / 180) / 120 * 8;
		cub->rays[times + PIXEL_X / 2].x = rc->pos.x;
		cub->rays[times + PIXEL_X / 2].y = rc->pos.y;
	}
}

void	ray_casting(t_cub *cub)
{
	t_raycast	rc;

	rc.width = cub->map.width;
	rc.height = cub->map.height;
	rc.ray = correct_angles(cub->map.g) * M_PI / 180;
	ray_casting_r(cub, &rc, -1);
	rc.ray = correct_angles(cub->map.g) * M_PI / 180;
	ray_casting_l(cub, &rc, -1);
	cub->rays[PIXEL_X].x = -1;
	cub->rays[PIXEL_X].y = -1;
	minimap(cub, &cub->map.player_pos);
	put_weapons(cub, &cub->weapons, cub->weapons.current);
	display_fps(cub);
}

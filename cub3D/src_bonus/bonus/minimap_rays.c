/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:40:02 by prando-a          #+#    #+#             */
/*   Updated: 2024/06/01 03:39:46 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	get_sum(double x, double ray)
{
	if (x < ray)
		return (1);
	else
		return (-1);
}

void	draw_ray_minimap_y(t_cub *cub, t_mmap m)
{
	int	i;

	i = 0;
	while (cub->rays[i].x != -1)
	{
		m.pos.y = (cub->map.player_pos.y - 10 * (int)m.dif.y) * PIXEL_SIZE;
		m.ray.y = (cub->rays[i].y - 10 * (int)m.dif.y) * PIXEL_SIZE;
		m.ray.x = (cub->rays[i].x - 10 * (int)m.dif.x) * PIXEL_SIZE;
		m.m = (m.ray.y - m.pos.y) / ((m.ray.x - (cub->map.player_pos.x - 10
						* (int)m.dif.x) * PIXEL_SIZE));
		m.n = m.pos.y - (m.m * (cub->map.player_pos.x - 10 * (int)m.dif.x)
				* PIXEL_SIZE);
		m.sum.y = get_sum(m.pos.y, m.ray.y);
		while ((int)m.pos.y != (int)m.ray.y)
		{
			m.x = (m.pos.y - m.n) / m.m;
			if (m.pos.y >= 0 && m.pos.y < 10 * PIXEL_SIZE && m.x >= 0
				&& m.x < 10 * PIXEL_SIZE)
				mlx_put_pixel(cub->main_img, (int)m.x,
					(int)m.pos.y, 0xFF0000FF);
			m.pos.y += m.sum.y;
		}
		i += 3;
	}
}

void	draw_ray_minimap_x(t_cub *cub, t_mmap m, int i)
{
	while (cub->rays[i].x != -1)
	{
		m.pos.x = (cub->map.player_pos.x - 10 * (int)m.dif.x) * PIXEL_SIZE;
		m.ray.y = (cub->rays[i].y - 10 * (int)m.dif.y) * PIXEL_SIZE;
		m.ray.x = (cub->rays[i].x - 10 * (int)m.dif.x) * PIXEL_SIZE;
		m.m = (m.ray.y - ((cub->map.player_pos.y - 10 * (int)m.dif.y)
					* PIXEL_SIZE)) / (m.ray.x - m.pos.x);
		m.n = (((cub->map.player_pos.y - 10 * (int)m.dif.y) * PIXEL_SIZE)
				- (m.m * m.pos.x));
		m.sum.x = get_sum(m.pos.x, m.ray.x);
		while ((int)m.pos.x != (int)m.ray.x)
		{
			m.y = (m.m * m.pos.x) + m.n;
			if (m.y >= 0 && m.y < 10 * PIXEL_SIZE && m.pos.x >= 0
				&& m.pos.x < 10 * PIXEL_SIZE)
				mlx_put_pixel(cub->main_img, (int)m.pos.x,
					(int)m.y, 0xFF0000ff);
			m.pos.x += m.sum.x;
		}
		i += 3;
	}
	draw_ray_minimap_y(cub, m);
}

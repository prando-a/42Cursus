/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:24:20 by prando-a          #+#    #+#             */
/*   Updated: 2024/06/01 03:34:12 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	putsquare(t_cub *cub, int x, int y, int color)
{
	int	i;
	int	j;
	int	div;

	j = x;
	if ((unsigned)color == 0xFF000088)
		div = 2;
	else
		div = 1;
	while (j < x + (PIXEL_SIZE / div))
	{
		i = y;
		while (i < y + (PIXEL_SIZE / div))
		{
			mlx_put_pixel(cub->main_img, j, i, color);
			++i;
		}
		++j;
	}
}

void	draw_map(t_cub *cub, t_point *beg, t_point *end)
{
	int	beg_x;
	int	i;
	int	j;

	j = -1;
	while ((int)beg->y < (int)end->y && ++j + 1)
	{
		beg_x = (int)beg->x;
		i = 0;
		while (beg_x < (int)end->x && cub->map.map[(int)beg->y][beg_x])
		{
			if (cub->map.map[(int)beg->y][(int)beg_x] == '0')
				putsquare(cub, (i * PIXEL_SIZE), (j * PIXEL_SIZE), 0x0000FFFF);
			else if (cub->map.map[(int)beg->y][(int)beg_x] == '1')
				putsquare(cub, (i * PIXEL_SIZE), (j * PIXEL_SIZE), 0xFFFFFFFF);
			else if (cub->map.map[(int)beg->y][(int)beg_x] == 'D')
				putsquare(cub, (i * PIXEL_SIZE), (j * PIXEL_SIZE), 0xFFFF00FF);
			else if (cub->map.map[(int)beg->y][(int)beg_x] == 'd')
				putsquare(cub, (i * PIXEL_SIZE), (j * PIXEL_SIZE), 0x00FF00FF);
			++beg_x;
			++i;
		}
		beg->y += 1;
	}
}

void	set_ends(t_point *end, int height, int width)
{
	if (((int)end->y - (int)end->y % 10) == (height - height % 10))
		end->y += 1;
	if (((int)end->x - (int)end->x % 10) == (width - width % 10))
		end->x += 1;
	if (end->y > height)
		end->y = height;
	if (end->x > width)
		end->x = width;
}

void	minimap(t_cub *cub, t_point *pos)
{
	t_point	beg;
	t_point	end;
	t_mmap	m;

	beg.x = pos->x - (int)pos->x % 10;
	if (beg.x < 0)
		beg.x = -1;
	beg.y = pos->y - (int)pos->y % 10;
	if (beg.y < 0)
		beg.y = -1;
	end.x = (beg.x + 10);
	end.y = (beg.y + 10);
	set_ends(&end, cub->map.height, cub->map.width);
	draw_map(cub, &beg, &end);
	m.dif.x = cub->map.player_pos.x / 10;
	m.dif.y = cub->map.player_pos.y / 10;
	draw_ray_minimap_x(cub, m, 0);
	mlx_put_pixel(cub->main_img, (fmod(pos->x, 10) * PIXEL_SIZE),
		(fmod(pos->y, 10) * PIXEL_SIZE), 0xFF000088);
}

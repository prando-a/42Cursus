/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:24:33 by jose-mgo          #+#    #+#             */
/*   Updated: 2024/05/28 04:40:44 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

uint32_t	img_rgba(uint32_t xy, uint8_t *pixels, unsigned long len)
{
	uint32_t	color;

	if (xy >= len)
		return (0);
	color = ((uint32_t)((uint32_t)pixels[xy] << 24
				| (uint32_t)pixels[xy + 1] << 16
				| (uint32_t)pixels[xy + 2] << 8
				| pixels[xy + 3]));
	return (color);
}

uint32_t	get_pixel_color(t_cub *cub, double scale_y, double y, double x)
{
	y = (int)(y * scale_y);
	return (img_rgba((unsigned int)(((y * cub->text->width) + round(x)) * 4),
		cub->text->pixels, cub->text->width * cub->text->height * 4));
}

int	choose_texture_2(t_cub *cub, double x, double y, double *ray_angle)
{
	if (x - (int)x >= 0.99999)
	{
		if (cub->boolean_door)
			cub->text = cub->tex[DOOR];
		else
			cub->text = cub->tex[EAST];
		*ray_angle = (y - (int)y) * (cub->text->width - 1);
		return (1);
	}
	if (y - (int)y >= 0.99999)
	{
		if (cub->boolean_door)
			cub->text = cub->tex[DOOR];
		else
			cub->text = cub->tex[NORTH];
		*ray_angle = (1 - (x - (int)x)) * (cub->text->width - 1);
		return (1);
	}
	return (1);
}

int	choose_texture(t_cub *cub, double x, double y, double *ray_angle)
{
	if (x - (int)x <= 0.00001)
	{
		if (cub->boolean_door)
			cub->text = cub->tex[DOOR];
		else
			cub->text = cub->tex[WEST];
		*ray_angle = (1 - (y - (int)y)) * (cub->text->width - 1);
		return (1);
	}
	if (y - (int)y <= 0.00001)
	{
		if (cub->boolean_door)
			cub->text = cub->tex[DOOR];
		else
			cub->text = cub->tex[SOUTH];
		return (*ray_angle = (x - (int)x) * (cub->text->width - 1), 1);
	}
	return (choose_texture_2(cub, x, y, ray_angle));
}

void	put_images(int times, t_point pos, t_cub *cub, double ray_angle)
{
	t_images	images;

	images.wall_h = ((PIXEL_Y / 4) / get_distance(pos.x, pos.y, cub)) * 1
		/ cos(cub->map.g * M_PI / 180 - (ray_angle));
	images.limit = PIXEL_Y / 2 + images.wall_h;
	images.i = PIXEL_Y / 2 - images.wall_h;
	images.cpy_i = images.i;
	images.range = images.limit - images.i;
	if (images.limit > PIXEL_Y)
		images.limit = PIXEL_Y;
	if (images.i < 0)
		images.i = 0;
	choose_texture(cub, pos.x, pos.y, &images.x);
	images.j = -1;
	while (++images.j < images.i)
		mlx_put_pixel(cub->main_img, times, images.j, cub->c_color);
	while (images.i < images.limit)
	{
		mlx_put_pixel(cub->main_img, times, images.i,
			get_pixel_color(cub, ((double)cub->text->height - 1)
				/ images.range, images.i - images.cpy_i, images.x));
		++images.i;
	}
	while (images.limit < PIXEL_Y)
		mlx_put_pixel(cub->main_img, times, images.limit++, cub->f_color);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:24:20 by prando-a          #+#    #+#             */
/*   Updated: 2024/05/14 07:58:40 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	display_fps(t_cub *cub)
{
	static long			frame_count = 0;
	static double		start_time = -10;
	double				elapsed_time;
	char				*fps;
	static mlx_image_t	*old_image;

	++frame_count;
	elapsed_time = mlx_get_time() - start_time;
	if (elapsed_time >= 1)
		fps = ft_itoa((int)(frame_count / elapsed_time));
	else
		fps = NULL;
	if (elapsed_time >= 1.0)
	{
		if (old_image)
			mlx_delete_image(cub->mlx, old_image);
		old_image = mlx_put_string(cub->mlx, fps, PIXEL_X - 30, 0);
		frame_count = 0;
		start_time = mlx_get_time();
	}
	ft_free(fps);
}

uint32_t	rgba_to_int(int *color, int alpha)
{
	uint32_t	ret;

	ret = (unsigned int)color[R] << 24;
	ret += (unsigned int)color[G] << 16;
	ret += (unsigned int)color[B] << 8;
	ret += alpha;
	return (ret);
}

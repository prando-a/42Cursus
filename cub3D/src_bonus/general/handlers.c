/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:08:36 by prando-a          #+#    #+#             */
/*   Updated: 2024/06/01 11:16:51 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	calculate_new_pos(t_cub *cub, t_point *pos, char wasd)
{
	if (mlx_is_key_down(cub->mlx, MLX_KEY_LEFT_SHIFT))
		cub->mv_speed = 0.2;
	else
		cub->mv_speed = 0.1;
	if (wasd == 'W' && check_wall_w(cub))
	{
		pos->x += (cub->mv_speed * sin(cub->map.g * M_PI / 180));
		pos->y -= (cub->mv_speed * cos(cub->map.g * M_PI / 180));
	}
	if (wasd == 'A' && check_wall_a(cub))
	{
		pos->x -= (cub->mv_speed * cos(cub->map.g * M_PI / 180));
		pos->y -= (cub->mv_speed * sin(cub->map.g * M_PI / 180));
	}
	if (wasd == 'S' && check_wall_s(cub))
	{
		pos->x -= (cub->mv_speed * sin(cub->map.g * M_PI / 180));
		pos->y += (cub->mv_speed * cos(cub->map.g * M_PI / 180));
	}
	if (wasd == 'D' && check_wall_d(cub))
	{
		pos->x += (cub->mv_speed * cos(cub->map.g * M_PI / 180));
		pos->y += (cub->mv_speed * sin(cub->map.g * M_PI / 180));
	}
}

double	correct_angles(double g)
{
	while (g >= 360)
		g = g - 360;
	while (g < 0)
		g = g + 360;
	return (g);
}

void	handler_graphics(void *param)
{
	t_cub			*cub;
	static int32_t	mouse_x;
	int32_t			mouse_y;
	static int32_t	n_mouse_x;

	cub = param;
	mlx_get_mouse_pos(cub->mlx, &n_mouse_x, &mouse_y);
	if (n_mouse_x > mouse_x)
		cub->map.g = correct_angles(cub->map.g + cub->sensibility);
	else if (n_mouse_x < mouse_x)
		cub->map.g = correct_angles(cub->map.g - cub->sensibility);
	mouse_x = n_mouse_x;
	ray_casting(cub);
}

void	handler_key(void *param)
{
	t_cub	*cub;

	cub = param;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cub->mlx);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_RIGHT))
		cub->map.g = correct_angles(cub->map.g + 3);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_LEFT))
		cub->map.g = correct_angles(cub->map.g - 3);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_W))
		calculate_new_pos(cub, &cub->map.player_pos, 'W');
	if (mlx_is_key_down(cub->mlx, MLX_KEY_A))
		calculate_new_pos(cub, &cub->map.player_pos, 'A');
	if (mlx_is_key_down(cub->mlx, MLX_KEY_S))
		calculate_new_pos(cub, &cub->map.player_pos, 'S');
	if (mlx_is_key_down(cub->mlx, MLX_KEY_D))
		calculate_new_pos(cub, &cub->map.player_pos, 'D');
	if (mlx_is_key_down(cub->mlx, MLX_KEY_ENTER))
		cub->weapons.shooting = 1;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_1) && !(cub->weapons.shooting))
		cub->weapons.current = PUNCH;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_2) && !(cub->weapons.shooting))
		cub->weapons.current = GUN;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_3) && !(cub->weapons.shooting))
		cub->weapons.current = SHOTGUN;
}

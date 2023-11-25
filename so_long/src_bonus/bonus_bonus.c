/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:50:34 by prando-a          #+#    #+#             */
/*   Updated: 2023/11/25 17:25:00 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	write_steps(t_mlxres **mlx)
{
	char		*str;
	static int	steps;

	str = ft_itoa(++steps);
	mlx_image_to_window((*mlx)->mlx, (*mlx)->floor, 0, 0);
	mlx_image_to_window((*mlx)->mlx, (*mlx)->wall, 0, 0);
	mlx_put_string((*mlx)->mlx, str, 15, 15);
	free(str);
}

void	set_enemy_direction(t_mlxres **mlx, char **map, int direction)
{
	int			i;
	int			j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'M')
			{
				mlx_image_to_window((*mlx)->mlx,
					(*mlx)->floor, j * 64, i * 64);
				if (!direction)
					mlx_image_to_window((*mlx)->mlx,
						(*mlx)->enemy_r, j * 64, i * 64);
				else
					mlx_image_to_window((*mlx)->mlx,
						(*mlx)->enemy_l, j * 64, i * 64);
			}
		}
	}
}

void	set_player_direction(t_mlxres **mlx, int x, int y, char *action)
{
	if (ft_strequ(action, "up"))
		mlx_image_to_window((*mlx)->mlx, (*mlx)->player_f, x * 64, y * 64);
	if (ft_strequ(action, "down"))
		mlx_image_to_window((*mlx)->mlx, (*mlx)->player_b, x * 64, y * 64);
	if (ft_strequ(action, "left"))
		mlx_image_to_window((*mlx)->mlx, (*mlx)->player_l, x * 64, y * 64);
	if (ft_strequ(action, "right"))
		mlx_image_to_window((*mlx)->mlx, (*mlx)->player_r, x * 64, y * 64);
}

void	open_exit(t_mlxres **mlx, char **map)
{
	static int	lock;
	int			i;
	int			j;

	j = -1;
	if (!lock && ++lock)
	{
		while (map[++j])
		{
			i = -1;
			while (map[j][++i])
			{
				if (map[j][i] == 'E')
					mlx_image_to_window((*mlx)->mlx,
						(*mlx)->exit_o, i * 64, j * 64);
			}
		}
	}
}

void	sl_texturesinit(t_mlxres **mlx)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./res/wall.png");
	(*mlx)->wall = set_texture((*mlx)->mlx, texture);
	texture = mlx_load_png("./res/floor.png");
	(*mlx)->floor = set_texture((*mlx)->mlx, texture);
	texture = mlx_load_png("./res/collectible.png");
	(*mlx)->collectible = set_texture((*mlx)->mlx, texture);
	texture = mlx_load_png("./res/exit_c.png");
	(*mlx)->exit_c = set_texture((*mlx)->mlx, texture);
	texture = mlx_load_png("./res/exit_o.png");
	(*mlx)->exit_o = set_texture((*mlx)->mlx, texture);
	texture = mlx_load_png("./res/player_f.png");
	(*mlx)->player_f = set_texture((*mlx)->mlx, texture);
	texture = mlx_load_png("./res/player_b.png");
	(*mlx)->player_b = set_texture((*mlx)->mlx, texture);
	texture = mlx_load_png("./res/player_l.png");
	(*mlx)->player_l = set_texture((*mlx)->mlx, texture);
	texture = mlx_load_png("./res/player_r.png");
	(*mlx)->player_r = set_texture((*mlx)->mlx, texture);
	texture = mlx_load_png("./res/enemy_l.png");
	(*mlx)->enemy_l = set_texture((*mlx)->mlx, texture);
	texture = mlx_load_png("./res/enemy_r.png");
	(*mlx)->enemy_r = set_texture((*mlx)->mlx, texture);
}

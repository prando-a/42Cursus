/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coreplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:06:13 by prando-a          #+#    #+#             */
/*   Updated: 2023/11/24 12:54:12 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_pos
{
	int	*x;
	int	*y;
}	t_pos;

void	after_move(t_mlxres **mlx, int x, int y)
{
	static int	steps;
	t_pos		p;

	p.x = &(*mlx)->mapdata->player_posx;
	p.y = &(*mlx)->mapdata->player_posy;
	mlx_image_to_window((*mlx)->mlx, (*mlx)->floor, *p.x * 64, *p.y * 64);
	if ((*mlx)->mapdata->map[*p.y][*p.x] == 'E')
		mlx_image_to_window((*mlx)->mlx, (*mlx)->exit, *p.x * 64, *p.y * 64);
	*p.x = x;
	*p.y = y;
	if ((*mlx)->mapdata->map[y][x] == 'C')
	{
		mlx_image_to_window((*mlx)->mlx, (*mlx)->floor, x * 64, y * 64);
		(*mlx)->mapdata->map[y][x] = '0';
		(*mlx)->mapdata->collectibles--;
		ft_printf("QUEDAN %d coleccionables\n", (*mlx)->mapdata->collectibles);
	}
	mlx_image_to_window((*mlx)->mlx, (*mlx)->player, x * 64, y * 64);
	ft_printf("Número de pasos %d\n", ++steps);
}

void	move_player(char *action, t_mlxres **mlx, int *x, int *y)
{
	if (ft_strequ(action, "up") && (*mlx)->mapdata->map[*y - 1][*x] != '1')
		after_move(mlx, *x, *y - 1);
	if (ft_strequ(action, "down") && (*mlx)->mapdata->map[*y + 1][*x] != '1')
		after_move(mlx, *x, *y + 1);
	if (ft_strequ(action, "left") && (*mlx)->mapdata->map[*y][*x - 1] != '1')
		after_move(mlx, *x - 1, *y);
	if (ft_strequ(action, "right") && (*mlx)->mapdata->map[*y][*x + 1] != '1')
		after_move(mlx, *x + 1, *y);
}

int	map_loader(t_mapdata **map, t_mlxres **mlx)
{
	int	i;
	int	j;

	j = -1;
	while (++j < ft_arrnum((*map)->map))
	{
		i = -1;
		while (++i < (int)ft_strlen((*map)->map[0]))
		{
			mlx_image_to_window((*mlx)->mlx, (*mlx)->floor, i * 64, j * 64);
			if ((*map)->map[j][i] == '1')
				mlx_image_to_window((*mlx)->mlx, (*mlx)->wall, i * 64, j * 64);
			if ((*map)->map[j][i] == 'C')
				mlx_image_to_window((*mlx)->mlx, (*mlx)->collectible,
					i * 64, j * 64);
			if ((*map)->map[j][i] == 'E')
				mlx_image_to_window((*mlx)->mlx, (*mlx)->exit, i * 64, j * 64);
			if ((*map)->map[j][i] == 'P')
				mlx_image_to_window((*mlx)->mlx, (*mlx)->player,
					i * 64, j * 64);
		}
	}
	return (1);
}

void	sl_exit(t_mlxres **mlx, mlx_key_data_t key, int *x, int *y)
{
	int	enabled;

	enabled = 0;
	if (key.key == MLX_KEY_ESCAPE)
		enabled++;
	if ((*mlx)->mapdata->map[*y][*x] == 'E' && !(*mlx)->mapdata->collectibles)
	{
		ft_printf("¡HAS GANADO!\n");
		enabled++;
	}
	if (enabled)
	{
		mlx_terminate((*mlx)->mlx);
		exit(0);
	}
}

void	sl_keyhook(mlx_key_data_t key, void *param)
{
	t_mlxres	*mlx;
	t_pos		pos;

	mlx = (t_mlxres *)param;
	pos.x = &mlx->mapdata->player_posx;
	pos.y = &mlx->mapdata->player_posy;
	if (key.action == MLX_PRESS)
	{
		if (key.key == MLX_KEY_W || key.key == MLX_KEY_UP)
			move_player("up", &mlx, pos.x, pos.y);
		else if (key.key == MLX_KEY_S || key.key == MLX_KEY_DOWN)
			move_player("down", &mlx, pos.x, pos.y);
		else if (key.key == MLX_KEY_A || key.key == MLX_KEY_LEFT)
			move_player("left", &mlx, pos.x, pos.y);
		else if (key.key == MLX_KEY_D || key.key == MLX_KEY_RIGHT)
			move_player("right", &mlx, pos.x, pos.y);
		sl_exit(&mlx, key, pos.x, pos.y);
	}
}

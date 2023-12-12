/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:04:46 by prando-a          #+#    #+#             */
/*   Updated: 2023/12/09 16:21:44 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*set_texture(mlx_t *mlx, mlx_texture_t *texture)
{
	mlx_image_t	*image;

	if (!texture)
		return (NULL);
	image = mlx_texture_to_image(mlx, texture);
	if (!image)
		return (mlx_delete_texture(texture), NULL);
	return (mlx_delete_texture(texture), image);
}

t_mlxres	*sl_mlxinit(t_mapdata **map)
{
	t_mlxres		*mlx;
	mlx_texture_t	*texture;

	mlx = (t_mlxres *)ft_calloc(sizeof(t_mlxres), 1);
	if (!mlx)
		return (NULL);
	mlx->mlx = mlx_init(ft_strlen((*map)->map[0]) * 64,
			ft_arrnum((*map)->map) * 64, "so_long", true);
	texture = mlx_load_png("./res/wall.png");
	mlx->wall = set_texture(mlx->mlx, texture);
	texture = mlx_load_png("./res/floor.png");
	mlx->floor = set_texture(mlx->mlx, texture);
	texture = mlx_load_png("./res/collectible.png");
	mlx->collectible = set_texture(mlx->mlx, texture);
	texture = mlx_load_png("./res/exit_o.png");
	mlx->exit = set_texture(mlx->mlx, texture);
	texture = mlx_load_png("./res/player_f.png");
	mlx->player = set_texture(mlx->mlx, texture);
	if (!mlx->wall || !mlx->floor || !mlx->collectible
		|| !mlx->player || !mlx->exit)
		return ((*map)->error = 10, NULL);
	mlx->mapdata = *map;
	return (mlx);
}

void	error(int type)
{
	ft_printf("Error %d\n", type);
	if (type == -1)
		ft_printf("Formato de archivo no válido\n");
	if (type == 0)
		ft_printf("No se ha especificado un mapa\n");
	if (type == 1)
		ft_printf("El mapa no se encuentra o no ha podido abrirse\n");
	if (type == 2)
		ft_printf("Fallo crítico en el procesamiento de datos del mapa\n");
	if (type == 3)
		ft_printf("El mapa no tiene las dimensiones requeridas\n");
	if (type == 4)
		ft_printf("El mapa no está adecuadamente cerrado\n");
	if (type == 5)
		ft_printf("No hay, al menos, un coleccionable\n");
	if (type == 6)
		ft_printf("Debe haber (y solamente) una posición de salida\n");
	if (type == 7)
		ft_printf("Debe haber (y solamente) una posición inicial\n");
	if (type == 8)
		ft_printf("Se encontraron caracteres desconocidos en el mapa\n");
	if (type == 9)
		ft_printf("No es posible resolver este mapa\n");
	if (type == 10)
		ft_printf("Fallo crítico al procesar los recursos de la MLX42\n");
}

void	sl_error(int type, t_mapdata **map)
{
	error(type);
	if (map)
	{
		if ((*map)->map)
			ft_strdel((*map)->map);
		free(*map);
	}
	exit(1);
}

int	main(int argc, char **argv)
{
	t_mapdata	*map;
	t_mlxres	*mlx;

	if (argc == 1 || !*argv[1])
		sl_error(0, NULL);
	map = (t_mapdata *)ft_calloc(sizeof(t_mapdata), 1);
	if (!map)
		sl_error(2, NULL);
	if (!map_check(&map, argv[1]))
		sl_error(map->error, &map);
	mlx = sl_mlxinit(&map);
	if (!mlx || !map_loader(&map, &mlx))
		sl_error(map->error, &map);
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	mlx_key_hook(mlx->mlx, sl_keyhook, (void *)mlx);
	mlx_loop(mlx->mlx);
}

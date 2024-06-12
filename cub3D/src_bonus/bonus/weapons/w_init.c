/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:46:20 by jose-mgo          #+#    #+#             */
/*   Updated: 2024/05/26 04:59:06 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3D.h"

int	weapons_to_window(t_cub *cub, t_weapons *w)
{
	mlx_image_to_window(cub->mlx, w->punch[0], 0, PIXEL_Y - 720);
	mlx_image_to_window(cub->mlx, w->punch[1], 0, PIXEL_Y - 720);
	mlx_image_to_window(cub->mlx, w->punch[2], 0, PIXEL_Y - 720);
	mlx_image_to_window(cub->mlx, w->gun[0], 0, PIXEL_Y - 720);
	mlx_image_to_window(cub->mlx, w->gun[1], 0, PIXEL_Y - 720);
	mlx_image_to_window(cub->mlx, w->gun[2], 0, PIXEL_Y - 720);
	mlx_image_to_window(cub->mlx, w->gun[3], 0, PIXEL_Y - 720);
	mlx_image_to_window(cub->mlx, w->gun[4], 0, PIXEL_Y - 720);
	mlx_image_to_window(cub->mlx, w->shotgun[0], 0, PIXEL_Y - 720);
	mlx_image_to_window(cub->mlx, w->shotgun[1], 0, PIXEL_Y - 720);
	mlx_image_to_window(cub->mlx, w->shotgun[2], 0, PIXEL_Y - 720);
	mlx_image_to_window(cub->mlx, w->shotgun[3], 0, PIXEL_Y - 720);
	mlx_image_to_window(cub->mlx, w->shotgun[4], 0, PIXEL_Y - 720);
	return (w->punch[0]->enabled = 0, w->punch[1]->enabled = 0,
		w->punch[2]->enabled = 0, w->gun[0]->enabled = 0,
		w->gun[1]->enabled = 0, w->gun[2]->enabled = 0,
		w->gun[3]->enabled = 0, w->gun[4]->enabled = 0,
		w->shotgun[0]->enabled = 0, w->shotgun[1]->enabled = 0,
		w->shotgun[2]->enabled = 0, w->shotgun[3]->enabled = 0,
		w->shotgun[4]->enabled = 0, 0);
}

void	put_weapons(t_cub *cub, t_weapons *weapons, int current)
{
	static int	previous_weapon = -1;

	if (previous_weapon == -1)
		weapons_to_window(cub, weapons);
	if (previous_weapon == PUNCH && previous_weapon != current)
		weapons->punch[0]->enabled = 0;
	if (previous_weapon == GUN && previous_weapon != current)
		weapons->gun[0]->enabled = 0;
	if (previous_weapon == SHOTGUN && previous_weapon != current)
		weapons->shotgun[0]->enabled = 0;
	if (current == PUNCH && !(cub->weapons.shooting))
		weapons->punch[0]->enabled = 1;
	else if (current == GUN && !(cub->weapons.shooting))
		weapons->gun[0]->enabled = 1;
	else if (current == SHOTGUN && !(cub->weapons.shooting))
		weapons->shotgun[0]->enabled = 1;
	previous_weapon = current;
}

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

void	set_gun_and_shotgun(t_cub *cub)
{
	mlx_texture_t	*text;

	text = mlx_load_png("sprites/weapons/shotgun/shotgun0.png");
	cub->weapons.shotgun[0] = set_texture(cub->mlx, text);
	text = mlx_load_png("sprites/weapons/shotgun/shotgun1.png");
	cub->weapons.shotgun[1] = set_texture(cub->mlx, text);
	text = mlx_load_png("sprites/weapons/shotgun/shotgun2.png");
	cub->weapons.shotgun[2] = set_texture(cub->mlx, text);
	text = mlx_load_png("sprites/weapons/shotgun/shotgun3.png");
	cub->weapons.shotgun[3] = set_texture(cub->mlx, text);
	text = mlx_load_png("sprites/weapons/shotgun/shotgun4.png");
	cub->weapons.shotgun[4] = set_texture(cub->mlx, text);
	text = mlx_load_png("sprites/weapons/gun/gun0.png");
	cub->weapons.gun[0] = set_texture(cub->mlx, text);
	text = mlx_load_png("sprites/weapons/gun/gun1.png");
	cub->weapons.gun[1] = set_texture(cub->mlx, text);
	text = mlx_load_png("sprites/weapons/gun/gun2.png");
	cub->weapons.gun[2] = set_texture(cub->mlx, text);
	text = mlx_load_png("sprites/weapons/gun/gun3.png");
	cub->weapons.gun[3] = set_texture(cub->mlx, text);
	text = mlx_load_png("sprites/weapons/gun/gun4.png");
	cub->weapons.gun[4] = set_texture(cub->mlx, text);
}

int	init_weapons(t_cub *cub)
{
	mlx_texture_t	*text;

	text = mlx_load_png("sprites/weapons/punch/punch0.png");
	cub->weapons.punch[0] = set_texture(cub->mlx, text);
	text = mlx_load_png("sprites/weapons/punch/punch1.png");
	cub->weapons.punch[1] = set_texture(cub->mlx, text);
	text = mlx_load_png("sprites/weapons/punch/punch2.png");
	cub->weapons.punch[2] = set_texture(cub->mlx, text);
	set_gun_and_shotgun(cub);
	if (!cub->weapons.punch[0] || !cub->weapons.punch[1]
		|| !cub->weapons.punch[2])
		return (cub_error("Missing one or more PUNCH texture(s)"), 0);
	if (!cub->weapons.gun[0] || !cub->weapons.gun[1] || !cub->weapons.gun[2]
		|| !cub->weapons.gun[3] || !cub->weapons.gun[4])
		return (cub_error("Missing one or more GUN texture(s)"), 0);
	if (!cub->weapons.shotgun[0] || !cub->weapons.shotgun[1]
		|| !cub->weapons.shotgun[2] || !cub->weapons.shotgun[3]
		|| !cub->weapons.shotgun[4])
		return (cub_error("Missing one or more SHOTGUN texture(s)"), 0);
	return (1);
}

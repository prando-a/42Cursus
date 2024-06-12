/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-27 12:05:41 by prando-a          #+#    #+#             */
/*   Updated: 2024-05-27 12:05:41 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3D.h"

t_point	shoot_cast(t_map *m, int weapon)
{
	t_point	hit;
	double	sum;
	int		d;

	d = 0;
	if (weapon == PUNCH)
		d = 1;
	else if (weapon == GUN)
		d = 50;
	else if (weapon == SHOTGUN)
		d = 5;
	sum = 0;
	hit.x = m->player_pos.x;
	hit.y = m->player_pos.y;
	while (sum < d && m->map[(int)hit.y][(int)hit.x] != '1'
		&& m->map[(int)hit.y][(int)hit.x] != 'D'
		&& m->map[(int)hit.y][(int)hit.x] != 'd')
	{
		hit.y += 0.1 * cos((double)(m->g * M_PI / 180)) * -1;
		hit.x += 0.1 * sin((double)(m->g * M_PI / 180));
		sum += 0.1;
	}
	return (hit);
}

void	punch(t_weapons *w, t_map *m)
{
	static int	time = 0;

	if (time == 0)
	{
		w->punch[0]->enabled = 0;
		w->punch[1]->enabled = 1;
	}
	else if (time == 5)
	{
		d_open_close(w, m);
		w->punch[1]->enabled = 0;
		w->punch[2]->enabled = 1;
	}
	else if (time == 15)
	{
		w->punch[2]->enabled = 0;
		w->punch[1]->enabled = 1;
	}
	else if (time == 20)
	{
		w->punch[1]->enabled = 0;
		w->shooting = 0;
		time = -1;
	}
	++time;
}

void	cub_weapons_handler(void *param)
{
	t_cub			*cub;
	static short	time = 0;

	cub = param;
	if (cub->weapons.shooting == 1)
	{
		if (cub->weapons.current == PUNCH)
			punch(&cub->weapons, &cub->map);
		else if (cub->weapons.current == GUN)
			gun(&cub->weapons, &cub->map);
		else if (cub->weapons.current == SHOTGUN)
			shotgun(&cub->weapons, &cub->map);
	}
	++time;
	if (time == 31)
		time = 0;
}

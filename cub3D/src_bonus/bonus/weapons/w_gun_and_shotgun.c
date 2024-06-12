/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_gun_and_shotgun.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-27 18:03:12 by prando-a          #+#    #+#             */
/*   Updated: 2024-05-27 18:03:12 by prando-a         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3D.h"

void	gun_ii(t_weapons *w, int *time)
{
	if (*time == 20)
	{
		w->gun[3]->enabled = 0;
		w->gun[4]->enabled = 1;
	}
	else if (*time == 25)
	{
		w->gun[3]->enabled = 0;
		w->gun[4]->enabled = 1;
	}
	else if (*time == 30)
	{
		w->gun[4]->enabled = 0;
		w->gun[0]->enabled = 1;
		w->shooting = 0;
		*time = -1;
	}
}

void	gun(t_weapons *w, t_map *m)
{
	static int	time = 0;

	if (time == 0)
	{
		w->gun[0]->enabled = 0;
		w->gun[1]->enabled = 1;
		d_open_close(w, m);
	}
	else if (time == 5)
	{
		w->gun[1]->enabled = 0;
		w->gun[2]->enabled = 1;
	}
	else if (time == 15)
	{
		w->gun[2]->enabled = 0;
		w->gun[3]->enabled = 1;
	}
	else
		gun_ii(w, &time);
	++time;
}

void	shotgun_ii(t_weapons *w, int *time)
{
	if (*time == 20)
	{
		w->shotgun[3]->enabled = 0;
		w->shotgun[4]->enabled = 1;
	}
	else if (*time == 25)
	{
		w->shotgun[4]->enabled = 0;
		w->shotgun[0]->enabled = 1;
		w->shooting = 0;
		*time = -1;
	}
}

void	shotgun(t_weapons *w, t_map *m)
{
	static int	time = 0;

	if (time == 0)
	{
		w->shotgun[0]->enabled = 0;
		w->shotgun[1]->enabled = 1;
		d_open_close(w, m);
	}
	else if (time == 5)
	{
		w->shotgun[1]->enabled = 0;
		w->shotgun[2]->enabled = 1;
	}
	else if (time == 10)
	{
		w->shotgun[2]->enabled = 0;
		w->shotgun[3]->enabled = 1;
	}
	else
		shotgun_ii(w, &time);
	++time;
}

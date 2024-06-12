/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-27 13:21:47 by prando-a          #+#    #+#             */
/*   Updated: 2024-05-27 13:21:47 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3D.h"

void	d_open_close(t_weapons *w, t_map *m)
{
	t_point	hit;

	hit = shoot_cast(m, w->current);
	if (m->map[(int)hit.y][(int)hit.x] == 'D')
	{
		m->map[(int)hit.y][(int)hit.x] = 'd';
		m->maps[Q1][(int)hit.y][(int)hit.x] = 'd';
		m->maps[Q2][(int)hit.y][(int)hit.x] = 'd';
		m->maps[Q3][(int)hit.y][(int)hit.x] = 'd';
		m->maps[Q4][(int)hit.y][(int)hit.x] = 'd';
	}
	else if (m->map[(int)hit.y][(int)hit.x] == 'd'
		&& m->map[(int)m->player_pos.y][(int)m->player_pos.x] != 'd')
	{
		m->map[(int)hit.y][(int)hit.x] = 'D';
		m->maps[Q1][(int)hit.y][(int)hit.x] = 'D';
		m->maps[Q2][(int)hit.y][(int)hit.x] = 'D';
		m->maps[Q3][(int)hit.y][(int)hit.x] = 'D';
		m->maps[Q4][(int)hit.y][(int)hit.x] = 'D';
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_mouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:13:25 by prando-a          #+#    #+#             */
/*   Updated: 2024/05/26 04:53:52 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	handler_mouse(mouse_key_t button, action_t action,
			modifier_key_t mods, void *param)
{
	t_cub		*cub;
	t_weapons	*weapons;

	(void)mods;
	cub = param;
	weapons = &cub->weapons;
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
		weapons->shooting = 1;
}

void	handler_scroll(double xdelta, double ydelta, void *param)
{
	t_cub	*cub;

	(void)xdelta;
	cub = param;
	if (ydelta < 0)
		cub->sensibility -= 1;
	else if (ydelta > 0)
		cub->sensibility += 1;
	if (cub->sensibility > 15)
		cub->sensibility = 15;
	else if (cub->sensibility < 1)
		cub->sensibility = 1;
}

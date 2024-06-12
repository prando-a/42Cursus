/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_map_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-27 17:24:37 by prando-a          #+#    #+#             */
/*   Updated: 2024-05-27 17:24:37 by prando-a         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

char	**choose_map_for_check_w(t_cub *cub)
{
	if (cub->map.g >= 0 && cub->map.g < 90)
		return (cub->map.maps[Q2]);
	else if (cub->map.g >= 90 && cub->map.g < 180)
		return (cub->map.maps[Q3]);
	else if (cub->map.g >= 180 && cub->map.g < 270)
		return (cub->map.maps[Q4]);
	else if (cub->map.g >= 270 && cub->map.g < 360)
		return (cub->map.maps[Q1]);
	return (NULL);
}

char	**choose_map_for_check_a(t_cub *cub)
{
	if (cub->map.g >= 0 && cub->map.g < 90)
		return (cub->map.maps[Q1]);
	else if (cub->map.g >= 90 && cub->map.g < 180)
		return (cub->map.maps[Q2]);
	else if (cub->map.g >= 180 && cub->map.g < 270)
		return (cub->map.maps[Q3]);
	else if (cub->map.g >= 270 && cub->map.g < 360)
		return (cub->map.maps[Q4]);
	return (NULL);
}

char	**choose_map_for_check_s(t_cub *cub)
{
	if (cub->map.g >= 0 && cub->map.g < 90)
		return (cub->map.maps[Q4]);
	else if (cub->map.g >= 90 && cub->map.g < 180)
		return (cub->map.maps[Q1]);
	else if (cub->map.g >= 180 && cub->map.g < 270)
		return (cub->map.maps[Q2]);
	else if (cub->map.g >= 270 && cub->map.g < 360)
		return (cub->map.maps[Q3]);
	return (NULL);
}

char	**choose_map_for_check_d(t_cub *cub)
{
	if (cub->map.g >= 0 && cub->map.g < 90)
		return (cub->map.maps[Q3]);
	else if (cub->map.g >= 90 && cub->map.g < 180)
		return (cub->map.maps[Q4]);
	else if (cub->map.g >= 180 && cub->map.g < 270)
		return (cub->map.maps[Q3]);
	else if (cub->map.g >= 270 && cub->map.g < 360)
		return (cub->map.maps[Q2]);
	return (NULL);
}

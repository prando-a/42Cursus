/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:08:58 by prando-a          #+#    #+#             */
/*   Updated: 2023/11/24 12:53:43 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_to_arr(char *mapfile, t_mapdata **map)
{
	char	*raw;
	char	*line;
	int		fd;

	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
		return ((*map)->error = 1, 0);
	if (!ft_strequ(ft_strrchr(mapfile, '.'), ".ber"))
		return ((*map)->error = -1, close(fd), 0);
	line = get_next_line(fd);
	if (!line)
		return ((*map)->error = 2, close(fd), 0);
	raw = ft_calloc(1, 1);
	while (line)
	{
		raw = gnl_strjoin(raw, line, 1);
		if (!raw)
			return ((*map)->error = 2, close(fd), 0);
		free(line);
		line = get_next_line(fd);
	}
	(*map)->map = ft_split(raw, '\n');
	if (!(*map)->map || ft_linecounter(raw) != ft_arrnum((*map)->map))
		return (close(fd), free(raw), (*map)->error = 2, 0);
	return (close(fd), free(raw), 1);
}

int	dimensions_check(t_mapdata **map)
{
	int	width;
	int	i;

	if (ft_arrnum((*map)->map) < 3 || ft_strlen((*map)->map[0]) < 3)
		return ((*map)->error = 3, 0);
	i = 0;
	width = ft_strlen((*map)->map[i]);
	while ((*map)->map[i])
	{
		if ((int)ft_strlen((*map)->map[i++]) != width)
			return ((*map)->error = 3, 0);
	}
	return (1);
}

int	wall_check(t_mapdata **map, int k)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while ((*map)->map[0][++i] && k != 0)
		k = (*map)->map[0][i] == '1';
	if (k == 0)
		return ((*map)->error = 4, 0);
	i = -1;
	while ((*map)->map[ft_arrnum((*map)->map) - 1][++i] && k != 0)
		k = (*map)->map[ft_arrnum((*map)->map) - 1][i] == '1';
	if (k == 0)
		return ((*map)->error = 4, 0);
	while ((*map)->map[++j] && k != 0)
	{
		k = (*map)->map[j][0] == '1';
		if (k == 0)
			return ((*map)->error = 4, 0);
		k = (*map)->map[j][ft_strlen((*map)->map[j]) - 1] == '1';
	}
	if (k == 0)
		return ((*map)->error = 4, 0);
	return (1);
}

int	valid_char(t_mapdata **map)
{
	int	i;
	int	j;
	int	k;

	k = 1;
	i = -1;
	while ((*map)->map[++i] && k != 0)
	{
		j = -1;
		while ((*map)->map[i][++j] && k != 0)
			k = (*map)->map[i][j] == 'C' || (*map)->map[i][j] == 'E'
				|| (*map)->map[i][j] == 'P' || (*map)->map[i][j] == '0'
				|| (*map)->map[i][j] == '1';
	}
	if (k == 0)
		return ((*map)->error = 8, 0);
	return (1);
}

int	map_check(t_mapdata **map, char *mapfile)
{
	if (!file_to_arr(mapfile, map) || !dimensions_check(map)
		|| !wall_check(map, 1) || !valid_char(map)
		|| !check_items(map) || !solve_check(map))
		return (0);
	return (1);
}

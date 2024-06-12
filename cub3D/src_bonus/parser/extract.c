/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:20:44 by prando-a          #+#    #+#             */
/*   Updated: 2024/05/26 04:47:19 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

char	*extract_path(char *line)
{
	char	*path;
	char	**split;

	split = ft_split(line, ' ');
	if (split && split[1])
		path = ft_merge(&split[1], ' ', 1);
	else
		path = NULL;
	ft_strdel(split);
	return (path);
}

int	extract_tex_color(char *rule, char type, int *code)
{
	char	**split;

	split = ft_split(rule, ',');
	if (!split)
		return (cub_error("Failed to parse color codes"), 0);
	split[R] = ft_chrdel(split[R], ' ', 1);
	split[R] = ft_chrdel(split[R], type, 1);
	split[G] = ft_chrdel(split[G], ' ', 1);
	split[B] = ft_chrdel(split[B], ' ', 1);
	if (ft_arrnum(split) != 3 || ft_arr_islf(split) != 1
		|| ft_atoll(split[R]) < 0 || ft_atoll(split[R]) > 256
		|| ft_atoll(split[G]) < 0 || ft_atoll(split[G]) > 256
		|| ft_atoll(split[B]) < 0 || ft_atoll(split[B]) > 256)
		return (ft_strdel(split), cub_error("Wrong F/C color values"),
			code[R] = -1, code[G] = -1, code[B] = -1, 0);
	code[R] = ft_atoll(split[R]);
	code[G] = ft_atoll(split[G]);
	code[B] = ft_atoll(split[B]);
	return (ft_strdel(split), 1);
}

char	**extract_map(char **file)
{
	char	**res;
	char	*aux;
	int		i;

	i = -1;
	res = NULL;
	while (file[++i] && !res)
	{
		aux = ft_chrdel(file[i], ' ', 0);
		aux = ft_chrdel(aux, '\n', 1);
		if (ft_chrcnt(aux, '1') == (int)ft_strlen(aux)
			&& (int)ft_strlen(aux) > 0)
			res = ft_arrdup(&file[i]);
		ft_free(aux);
	}
	i = -1;
	while (res && res[++i])
	{
		res[i] = ft_chrdel(res[i], '\n', 1);
		if (!res[i][0])
			return (cub_error("Empty line(s) in map"), ft_strdel(res), NULL);
	}
	if (!res)
		cub_error("Error getting map data");
	return (res);
}

char	**extract_file(int fd, char *path)
{
	char	*line;
	char	**file;
	int		i;
	int		j;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		++i;
		ft_free(line);
		line = get_next_line(fd);
	}
	file = ft_calloc(sizeof(char *), i + 1);
	close(fd);
	fd = open(path, O_RDONLY);
	if (!file || fd < 0)
		return (ft_strdel(file), NULL);
	j = 0;
	while (j < i)
		file[j++] = get_next_line(fd);
	return (close(fd), file);
}

char	**extract_file_no_nl(char *path)
{
	int		fd;
	char	**file;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (cub_error("The f*cking hell is going on?"), NULL);
	file = ft_file_to_arr(fd);
	close(fd);
	return (file);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:02:12 by prando-a          #+#    #+#             */
/*   Updated: 2024/05/26 04:38:51 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	cub_error(char *msg)
{
	ft_err_msg(RED BOLD"Error"RESET);
	ft_printf(RED);
	if (msg && *msg)
		ft_err_msg(msg);
	ft_printf(RESET);
}

int	check_rules(char **file, char *rule, int silent)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (file[i])
		if (ft_strnequ(file[i++], rule, 2))
			flag++;
	if (flag == 0 && silent)
		return (0);
	else if (flag == 0)
		return (cub_error(""), ft_putstr_fd(RED"Missing ", 2),
			ft_putstr_fd(rule, 2), ft_err_msg(" rule"RESET), 0);
	else if (flag > 1)
		return (ft_err_msg(RED BOLD"Error"),
			ft_putstr_fd(RED"More than one ", 2),
			ft_putstr_fd(rule, 2), ft_err_msg(" rule"RESET), -1);
	return (1);
}

char	**get_file(int argc, char *path, int fd)
{
	char	**file;
	int		i;

	if (argc != 2)
		return (cub_error("Invalid arg count"), NULL);
	if (!ft_strequ(ft_strrchr(path, '.'), ".cub"))
		return (cub_error("Wrong format"), NULL);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (cub_error("Map not found"), NULL);
	file = extract_file(fd, path);
	if (!file)
		return (cub_error("Empty file or permission denied"), NULL);
	if (check_rules(file, "NO", 0) != 1 || check_rules(file, "SO", 0) != 1
		|| check_rules(file, "WE", 0) != 1 || check_rules(file, "EA", 0) != 1
		|| check_rules(file, "F ", 0) != 1 || check_rules(file, "C ", 0) != 1)
		return (ft_strdel(file), NULL);
	i = ft_arrnum(file);
	while (file[i - 1][0] == '\n')
	{
		ft_free(file[i - 1]);
		file[i - 1] = NULL;
		i--;
	}
	return (file);
}

int	rules_settings(t_map *map, char **file)
{
	int	i;

	map->path[NORTH] = NULL;
	map->path[SOUTH] = NULL;
	map->path[EAST] = NULL;
	map->path[WEST] = NULL;
	map->f_color[0] = -2;
	map->c_color[0] = -2;
	i = -1;
	while (file[++i])
	{
		if (ft_strnequ(file[i], "NO", 2))
			map->path[NORTH] = extract_path(file[i]);
		if (ft_strnequ(file[i], "SO", 2))
			map->path[SOUTH] = extract_path(file[i]);
		if (ft_strnequ(file[i], "WE", 2))
			map->path[WEST] = extract_path(file[i]);
		if (ft_strnequ(file[i], "EA", 2))
			map->path[EAST] = extract_path(file[i]);
		if (ft_strnequ(file[i], "F", 1) && map->c_color[0] != -1)
			extract_tex_color(file[i], 'F', map->f_color);
		if (ft_strnequ(file[i], "C", 1) && map->f_color[0] != -1)
			extract_tex_color(file[i], 'C', map->c_color);
	}
	return (ft_strdel(file), 1);
}

int	parser(int argc, char **argv, t_cub *cub)
{
	t_map	map;
	char	**file;
	int		i;

	file = get_file(argc, argv[1], -1);
	if (!file)
		return (0);
	if (!get_map(&map, file))
		return (ft_strdel(file), 0);
	ft_strdel(file);
	rules_settings(&map, extract_file_no_nl(argv[1]));
	cub->map = map;
	i = -1;
	while (++i < 4)
		cub->map.maps[i] = NULL;
	i = -1;
	while (++i < 5)
		cub->tex[i] = NULL;
	if (map.c_color[0] == -1 || map.f_color[0] == -1)
		return (cub_clean(cub), 0);
	if (!map.path[NORTH] || !map.path[SOUTH]
		|| !map.path[EAST] || !map.path[WEST])
		return (cub_error("Failed to parse rules"), cub_clean(cub), 0);
	ft_printf(BLUE UNDLINE "\tPRESS ENTER" RESET "  ");
	return (read(0, "", 1), 1);
}

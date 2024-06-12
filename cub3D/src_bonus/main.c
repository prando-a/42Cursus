/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:04:12 by jose-mgo          #+#    #+#             */
/*   Updated: 2024/05/29 17:53:43 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	cub_clean(t_cub *cub)
{
	int	i;

	ft_strdel(cub->map.map);
	i = -1;
	while (++i < 4)
		ft_free(cub->map.path[i]);
	i = -1;
	while (++i < 4)
		ft_strdel(cub->map.maps[i]);
	i = -1;
	while (++i < 5 && cub->tex[i])
		mlx_delete_texture(cub->tex[i]);
}

int	cub_intro(void)
{
	ft_msg(BOLD BRED"\t\t\t       ..                          ....");
	ft_msg("\t\t         . uW8\"        .x~~\"*Weu.      .xH888888Hx.");
	ft_msg("\t     x.    .     `t888        d8Nu.  9888c   .H8888888888888:");
	ft_printf("      .    .@88k  z88u    8888   .    88888  98888   888*");
	ft_msg("\"\"\"?\"\"*88888X");
	ft_printf(" .udR88N  ~\"8888 ^8888    9888.z88N   \"***\"  9888");
	ft_msg("%  'f     d8x.   ^%88k  ");
	ft_printf("<888'888k   8888  888R    9888  888E");
	ft_msg("       ..@8*\"   '>    <88888X   '?8");
	ft_printf("9888 'Y\"    8888  888R    9888  888E    ");
	ft_msg("````\"8Weu    `:..:`888888>    8>");
	ft_printf("9888        8888  888R    9888  888E");
	ft_msg("   ..    ?8888L         `\"*88     X");
	ft_printf("9888        8888 ,888B .  9888  888E ");
	ft_msg(":@88N   '8888N    .xHHhx..\"      !");
	ft_printf("?8888u../  \"8888Y 8888\"  .8888  888\" ");
	ft_msg("*8888~  '8888F   X88888888hx. ..!");
	ft_putstr_fd(" \"8888P'    `Y\"   'YP     `%888*%", 1);
	ft_msg("\"   '*8\"`   9888%   !   \"*888888888\"");
	ft_printf("   \"P'                       \"`");
	ft_msg("        `~===*%\"`            ^\"***\"`" BLUE);
	ft_msg("\t\t\t\t\t\tby\n\t\t\t\t\t\t  jose-mgo\n\t\t\t\t\t\t  prando-a");
	return (ft_msg(RESET), 1);
}

int	init(t_cub *cub)
{
	cub->mlx = mlx_init(PIXEL_X, PIXEL_Y, "cub3D", 0);
	cub->main_img = mlx_new_image(cub->mlx, PIXEL_X, PIXEL_Y);
	mlx_image_to_window(cub->mlx, cub->main_img, 0, 0);
	mlx_set_cursor_mode(cub->mlx, MLX_MOUSE_DISABLED);
	cub->tex[DOOR] = mlx_load_png("sprites/door.png");
	cub->tex[NORTH] = mlx_load_png(cub->map.path[NORTH]);
	cub->tex[SOUTH] = mlx_load_png(cub->map.path[SOUTH]);
	cub->tex[EAST] = mlx_load_png(cub->map.path[EAST]);
	cub->tex[WEST] = mlx_load_png(cub->map.path[WEST]);
	if (!cub->tex[NORTH] || !cub->tex[SOUTH]
		|| !cub->tex[EAST] || !cub->tex[WEST] || !cub->tex[DOOR])
		return (cub_error("Missing at least one texture"), cub_clean(cub), 0);
	cub->sensibility = 5;
	cub->weapons.current = PUNCH;
	cub->weapons.shooting = 0;
	cub->map.width = ft_strlen(cub->map.map[0]);
	cub->map.height = ft_arrnum(cub->map.map);
	cub->c_color = rgba_to_int(cub->map.c_color, 255);
	cub->f_color = rgba_to_int(cub->map.f_color, 255);
	init_maps(cub);
	if (!init_weapons(cub))
		return (cub_clean(cub), 0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_cub	cub;

	cub_intro();
	if (!parser(argc, argv, &cub) || !init(&cub))
		return (1);
	mlx_loop_hook(cub.mlx, &handler_key, &cub);
	mlx_loop_hook(cub.mlx, &handler_graphics, &cub);
	mlx_loop_hook(cub.mlx, &cub_weapons_handler, &cub);
	mlx_mouse_hook(cub.mlx, &handler_mouse, &cub);
	mlx_scroll_hook(cub.mlx, &handler_scroll, &cub);
	mlx_loop(cub.mlx);
	cub_clean(&cub);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 20:21:16 by prando-a          #+#    #+#             */
/*   Updated: 2023/12/05 12:59:43 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <limits.h>
# include <math.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_mapdata
{
	int			error;
	char		**map;
	int			collectibles;
	int			exit;
	int			player;
	int			player_posx;
	int			player_posy;
}	t_mapdata;

typedef struct s_mlxres
{
	mlx_t			*mlx;
	mlx_image_t		*wall;
	mlx_image_t		*floor;
	mlx_image_t		*collectible;
	mlx_image_t		*exit_c;
	mlx_image_t		*exit_o;
	mlx_image_t		*player_f;
	mlx_image_t		*player_b;
	mlx_image_t		*player_l;
	mlx_image_t		*player_r;
	mlx_image_t		*enemy_l;
	mlx_image_t		*enemy_r;
	t_mapdata		*mapdata;
}	t_mlxres;

typedef struct s_pos
{
	int	*x;
	int	*y;
}	t_pos;

int			ft_printf(char const *str, ...);
void		*ft_calloc(size_t count, size_t size);
int			ft_strequ(char const *s1, char const *s2);
char		*ft_strrchr(const char *s, int c);
char		*get_next_line(int fd);
char		*gnl_strjoin(char *s1, char *s2, int mode);
char		**ft_split(char const *s, char c);
int			ft_arrnum(char **array);
int			ft_linecounter(char *str);
size_t		ft_strlen(const char *str);
char		**ft_arrdup(char **array);
void		ft_strdel(char **as);

int			file_to_arr(char *mapfile, t_mapdata **map);
void		sl_error(int type, t_mapdata **map);
int			map_check(t_mapdata **map, char *mapfile);
int			check_items(t_mapdata **map);
int			solve_check(t_mapdata **map);
void		sl_keyhook(mlx_key_data_t key, void *param);
void		move_player(char *action, t_mlxres **mlx, int *x, int *y);
t_mlxres	*sl_mlxinit(t_mapdata **map);
int			map_loader(t_mapdata **map, t_mlxres **mlx, int i, int j);

void		sl_texturesinit(t_mlxres **mlx);
mlx_image_t	*set_texture(mlx_t *mlx, mlx_texture_t *texture);
void		open_exit(t_mlxres **mlx, char **map);
void		set_player_direction(t_mlxres **mlx, int x, int y, char *action);
void		write_steps(t_mlxres **mlx);
char		*ft_itoa(int n);
void		set_enemy_direction(t_mlxres **mlx, char **map, int direction);

#endif
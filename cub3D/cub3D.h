/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:06:26 by prando-a          #+#    #+#             */
/*   Updated: 2024/05/28 04:34:26 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# ifndef FOV
#  define FOV_DEFAULT 60
#  define FOV FOV_DEFAULT
# elif FOV > 120
#  undef FOV
#  define FOV 60
# endif
# ifndef PIXEL_X
#  define PIXEL_X 1200
# endif
# ifndef PIXEL_Y
#  define PIXEL_Y 1000
# endif
# ifndef PIXEL_SIZE
#  define PIXEL_SIZE 16
# endif
# include <limits.h>
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <math.h>
# define SUM 0
# define DIF 1

enum e_gvalues
{
	N = 0,
	E = 90,
	S = 180,
	W = 270
};

enum e_colors_array_index
{
	R,
	G,
	B
};

enum e_weapon_id
{
	PUNCH,
	GUN,
	SHOTGUN
};

enum e_texture_paths_array_index
{
	NORTH,
	EAST,
	SOUTH,
	WEST,
	DOOR,
};

enum e_door_orientation
{
	D_X,
	D_Y,
};

enum e_quadrant
{
	Q1,
	Q2,
	Q3,
	Q4,
};

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_raycast
{
	t_point	pos;
	double	ray;
	char	**map;
	short	bl;
	int		height;
	int		width;
}	t_raycast;

typedef struct s_images
{
	int				i;
	int				cpy_i;
	int				limit;
	double			range;
	int				wall_h;
	double			x;
	int				j;

}	t_images;

typedef struct s_map
{
	t_point		player_pos;
	double		g;
	char		**map;
	int			f_color[3];
	int			c_color[3];
	char		*path[4];
	char		**maps[4];
	int			width;
	int			height;
}	t_map;

typedef struct s_weapons
{
	mlx_image_t		*punch[3];
	mlx_image_t		*gun[5];
	mlx_image_t		*shotgun[5];
	int				current;
	int				shooting;
}	t_weapons;

typedef struct s_mmap
{
	double			m;
	double			n;
	double			y;
	double			x;
	t_point			pos;
	t_point			ray;
	t_point			sum;
	t_point			dif;
}	t_mmap;

typedef struct s_cub
{
	t_map			map;
	mlx_t			*mlx;
	mlx_image_t		*main_img;
	mlx_texture_t	*text;
	mlx_texture_t	*tex[5];
	t_point			rays[PIXEL_X + 1];
	t_weapons		weapons;
	double			mv_speed;
	int				sensibility;
	bool			boolean_door;
	bool			isdoor;
	bool			dir;
	unsigned int	f_color;
	unsigned int	c_color;
}	t_cub;

// PARSER
int			parser(int argc, char **argv, t_cub *cub);
int			check_rules(char **file, char *rule, int silent);
char		**extract_file(int fd, char *path);
char		**extract_file_no_nl(char *path);
char		*extract_path(char *line);
int			extract_tex_color(char *rule, char type, int *code);
char		**extract_map(char **file);
int			valid_chars(char **map);
int			set_player_pos(t_map *map);
int			get_map(t_map *map, char **file);
int			closed_map(t_map *m);
int			rules_settings(t_map *map, char **file);
void		init_maps(t_cub *cub);

// MAIN
void		cub_error(char *msg);
void		cub_clean(t_cub *cub);

// GRAPHICS
void		ray_casting(t_cub *cub);
void		ray_casting_l(t_cub *cub, t_raycast *rc, int times);
void		ray_casting_r(t_cub *cub, t_raycast *rc, int times);
void		ray_iteration(t_raycast *rc, char **map);
void		ray_iteration2(t_raycast *rc, char **map);
int			choose_texture(t_cub *cub, double x, double y, double *ray_angle);
double		get_distance(double x, double y, t_cub *cub);
void		change_pos(t_cub *cub, char change[4], t_point pos);
void		ch_ray_val(t_point *pos, double val, double ray, int mode);

void		put_images(int times, t_point pos, t_cub *cub, double ray_angle);
void		display_fps(t_cub *cub);
char		**choose_actual_map(t_cub *cub, double ray);
uint32_t	rgba_to_int(int *color, int alpha);

// GENERAL
int			check_wall_w(t_cub *cub);
int			check_wall_a(t_cub *cub);
int			check_wall_s(t_cub *cub);
int			check_wall_d(t_cub *cub);
char		**choose_map_for_check(t_cub *cub, char key);
char		**choose_map_for_check_w(t_cub *cub);
char		**choose_map_for_check_a(t_cub *cub);
char		**choose_map_for_check_s(t_cub *cub);
char		**choose_map_for_check_d(t_cub *cub);
void		handler_graphics(void *param);
void		handler_key(void *param);
double		correct_angles(double g);
void		handler_scroll(double xdelta, double ydelta, void *param);
void		handler_mouse(mouse_key_t button, action_t action,
				modifier_key_t mods, void *param);

// BONUS
int			cub_check_doors(char **map);
void		d_open_close(t_weapons *w, t_map *m);
void		minimap(t_cub *cub, t_point *pos);
void		draw_ray_minimap_x(t_cub *cub, t_mmap m, int i);

// WEAPONS
void		cub_weapons_handler(void *param);
void		put_weapons(t_cub *cub, t_weapons *weapons, int current);
int			init_weapons(t_cub *cub);
t_point		shoot_cast(t_map *m, int weapon);
void		gun(t_weapons *w, t_map *m);
void		shotgun(t_weapons *w, t_map *m);
void		punch(t_weapons *w, t_map *m);

#endif
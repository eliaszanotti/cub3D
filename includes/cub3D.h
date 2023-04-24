/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:08:26 by ezanotti          #+#    #+#             */
/*   Updated: 2023/04/24 14:40:50 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# include "libft.h"
# include "mlx.h"
# include "get_next_line.h"

# ifdef __APPLE__
#  define LEFT_ARROW_KEY 123
#  define RIGHT_ARROW_KEY 124
#  define UP_ARROW_KEY 126
#  define DOWN_ARROW_KEY 125
#  define W_LOWER_KEY 13
#  define S_LOWER_KEY 1
#  define A_LOWER_KEY 0
#  define D_LOWER_KEY 2
#  define ESC_KEY 53
#  define F5_KEY 96
#  define M_KEY 46
# else
#  define LEFT_ARROW_KEY 65361
#  define RIGHT_ARROW_KEY 65363
#  define UP_ARROW_KEY 65362
#  define DOWN_ARROW_KEY 65364
#  define W_LOWER_KEY 119
#  define S_LOWER_KEY 115
#  define A_LOWER_KEY 97
#  define D_LOWER_KEY 100
#  define ESC_KEY 65307
#  define F5_KEY 65474
#  define M_KEY 109
# endif

# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3
# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define CUB_SIZE 16
# define P_OFFSET 100
# define IMG_SIZE 16

typedef struct s_ray
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	raydir_x;
	double	raydir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	move_speed;
	double	rot_speed;
	double	tex_pos;
	double	step;
	double	perp_wall_dist;
	int		draw_start;
	int		draw_end;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		tex_x;
	int		tex_y;
	int		side;
}	t_ray;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	int		x;
	int		y;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
}	t_mlx;

typedef struct s_anim
{
	t_img	img[12];
	int		current_img;
	int		anime_frame;
}	t_anim;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_args
{
	char	**map;
	t_list	*map_list;
	t_mlx	*mlx;
	t_ray	*ray;
	t_img	texture[4];
	t_anim	*anim;
	char	*north_path;
	char	*south_path;
	char	*west_path;
	char	*east_path;
	char	*floor;
	int		floor_color;
	char	*ceiling;
	int		ceiling_color;
	int		expanded;
	int		x_img;
	int		y_img;
	int		keypress;
	int		turn_left;
	int		turn_right;
	int		move_up;
	int		move_down;
	int		move_right;
	int		move_left;
	int		img_size;
	int		last_x;
}	t_args;

//	MLX
int				ft_create_img(t_args *args, char *path, int side);
void			ft_draw_line(t_args *args, t_img *img, int x);
unsigned int	ft_get_color(t_img *img, int x, int y);
int				ft_init_window(t_args *args);
void			ft_mlx_pixel_put(t_img *data, int x, int y, int color);
void			ft_print_cross(t_img *img);
void			ft_print_line(t_img *img, t_point p1, t_point p2, int color);
int				ft_print_minimap(t_args *args, t_img *img);
void			ft_put_player(t_img *img, int color);
void			ft_put_square(t_args *args, t_point p, int color, double angle);
//	PARSING
int				ft_check_walls(t_args *args);
int				ft_convert_list(t_args *args);
int				ft_fill_map(t_args *args);
int				ft_is_valid_map(t_args *args);
int				ft_parse_infos(t_args *args, int fd);
int				ft_parse_map(t_args *args, int fd);
int				ft_parsing(t_args *args, char *cub_file);
int				ft_reset_struct(t_args *args);
//	RAYCASTING
int				ft_calculate_positions(t_args *args);
int				ft_calculate_side_dist(t_args *args);
int				ft_init_ray(t_args *args);
int				ft_init_textures(t_args *args);
int				ft_init_values(t_args *args, int x);
int				ft_loop(t_args *args);
void			ft_move(t_args *args);
int				ft_raycasting(t_args *args);
int				ft_throw_ray(t_args *args);
void			ft_turn_left(t_args *args);
void			ft_turn_right(t_args *args);
//	UTILS
int				ft_error(int error_code);
int				ft_exit(t_args *args);
void			ft_free_str(char **str);
void			ft_free_list(t_list *list);
void			ft_free_mlx(t_args *args);
void			ft_free_struct(t_args *args);
int				hook_keypress(int key, t_args *args);
int				hook_keyrelease(int key, t_args *args);
int				ft_is_extension_correct(char *file, char *extension);
int				ft_reduce_opacity(int color, double opacity);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:08:26 by ezanotti          #+#    #+#             */
/*   Updated: 2023/06/29 16:38:33 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# include "libft.h"
# include "mlx.h"

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
#  define P_KEY 35
#  define SPACE_KEY 49
# else
#  define LEFT_ARROW_KEY 65361
#  define RIGHT_ARROW_KEY 65363
#  define UP_ARROW_KEY 65362
#  define DOWN_ARROW_KEY 65364
#  define W_LOWER_KEY 119
#  define S_LOWER_KEY 115
#  define A_LOWER_KEY 97
#  define D_LOWER_KEY 100
#  define SPACE_KEY 32
#  define ESC_KEY 65307
#  define F5_KEY 65474
#  define M_KEY 109
#  define P_KEY 112
# endif

# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3
# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define CUB_SIZE 16
# define P_OFFSET 180
# define IMG_SIZE 256

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_dpoint
{
	double	x;
	double	y;
}	t_dpoint;

typedef struct s_ray
{
	t_dpoint	pos;
	t_dpoint	dir;
	t_dpoint	plane;
	t_dpoint	raydir;
	t_dpoint	side_dist;
	t_dpoint	delta_dist;
	t_point		map;
	t_point		step_pos;
	t_point		tex;
	double		move_speed;
	double		rot_speed;
	double		tex_pos;
	double		step;
	double		perp_wall_dist;
	int			draw_start;
	int			draw_end;
	int			side;
	int			boolean;
}	t_ray;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
}	t_mlx;

typedef struct s_args
{
	char	**map;
	t_list	*map_list;
	t_mlx	*mlx;
	t_ray	*ray;
	t_img	texture[7];
	char	*north_path;
	char	*south_path;
	char	*west_path;
	char	*east_path;
	char	*floor;
	int		floor_color;
	char	*ceiling;
	int		ceiling_color;
	int		expanded;
	int		turn_left;
	int		turn_right;
	int		move_up;
	int		move_down;
	int		move_right;
	int		move_left;
	int		space_press;
	int		last_x;
	int		is_paused;
	int		door_delay;
	int		screamer;
	int		end;
	int		flash_timer;
}	t_args;

//	MLX
int				ft_create_img(t_args *args, char *path, int side);
int				ft_draw_line(t_args *args, t_img *img, int x);
unsigned int	ft_get_color(t_img *img, int x, int y);
int				ft_init_window(t_args *args);
void			ft_mlx_pixel_put(t_img *data, int x, int y, int color);
int				ft_pause(t_args *args);
void			ft_print_cross(t_img *img);
void			ft_print_line(t_args *args, t_point p1, t_point p2, int color);
int				ft_print_minimap(t_args *args, t_img *img);
void			ft_put_square(t_args *args, t_point p, int color, double angle);
//	PARSING
int				ft_check_walls(t_args *args);
int				ft_convert_list(t_args *args);
int				ft_fill_map(t_args *args);
int				ft_is_valid_map(t_args *args);
int				ft_get_infos(t_args *args, int fd);
int				ft_get_map(t_args *args, int fd);
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
int				ft_mouse_hook(int x, int y, t_args *args);
int				ft_is_correct_extension(char *file, char *extension);
int				ft_reduce_opacity(int color, double opacity);
int				ft_close_doors(t_args *args);
int				ft_check_screamer(t_args *args);
int				ft_check_end(t_args *args);
void			ft_print_square(t_img *img, int x, int y);
int				ft_print_flashlight(t_args *args, t_img *img);

int	ft_parse_colors(t_args *args);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:08:26 by ezanotti          #+#    #+#             */
/*   Updated: 2023/03/30 14:52:09 by elias            ###   ########.fr       */
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
# endif

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 800
#define CUB_SIZE 8

typedef struct s_ray
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	moveSpeed;
	double	rotSpeed;
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
	t_img	image;
}	t_mlx;

typedef struct s_args
{
	char	**map;
	t_list	*map_list;
	t_mlx	*mlx;
	t_ray	*ray;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;
	int		x_player;
	int		y_player;
	int		x_img;
	int		y_img;
	int 	keypress;
	int		move_left;
	int		move_right;
	int		move_up;
	int		move_down;
}	t_args;

//	IMG
void	ft_put_player(t_img *img);
void	ft_put_square(t_img *img, int size, int color);
//	MLX
int		ft_init_window(t_args *args);
//	PARSING
int		ft_check_walls(t_args *args);
int		ft_convert_list(t_args *args);
int		ft_fill_map(t_args *args);
int		ft_is_valid_map(t_args *args);
int		ft_parse_infos(t_args *args, int fd);
int		ft_parse_map(t_args *args, int fd);
int		ft_parsing(t_args *args, char *cub_file);
int		ft_reset_struct(t_args *args);
//	UTILS
void	ft_free_list(t_list *list);
void	ft_free_struct(t_args *args);
int		ft_error(int error_code);
int		ft_is_extension_correct(char *file, char *extension);
int		ft_get_start(t_args *args);

//	CREATE_WINDOW
int		ft_create_minimap(t_args *args, t_img *img);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
int		ft_raycasting(t_args *args);
void	ft_loop(t_args *args);
int		hook_keypress(int key, void *param, t_args *args);
int		hook_keyrelease(int key, t_args *args);
void    ft_move(t_args *args);
#endif

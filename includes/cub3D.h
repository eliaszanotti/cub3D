/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:08:26 by ezanotti          #+#    #+#             */
/*   Updated: 2023/03/29 14:44:40 by tgiraudo         ###   ########.fr       */
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

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 800
#define CUB_SIZE 8

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
	t_img	player;
	t_img	image;
}	t_mlx;

typedef struct s_args
{
	char	**map;
	t_list	*map_list;
	t_mlx	*mlx;
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

//	CREATE_WINDOW
int		ft_create_window(t_args *args);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
int		ft_raycasting(t_args *args);

#endif

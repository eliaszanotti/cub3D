/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:08:26 by ezanotti          #+#    #+#             */
/*   Updated: 2023/03/28 19:54:03 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>

# include "libft.h"
# include "../mlx/mlx.h"
# include "get_next_line.h"

#define SCREEN_WIDTH 3840
#define SCREEN_HEIGHT 2160

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	blue;
	t_img	red;
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
}	t_args;

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

#endif

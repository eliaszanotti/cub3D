/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:08:26 by ezanotti          #+#    #+#             */
/*   Updated: 2023/03/10 18:00:59 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>

# include "libft.h"
# include "get_next_line.h"

typedef struct s_args
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;
}	t_args;

//	PARSING
int	ft_parse_infos(t_args *args, int fd);
int	ft_parsing(t_args *args, char *cub_file);
int	ft_reset_struct(t_args *args);
//	UTILS
int	ft_error(int error_code);
int	ft_is_extension_correct(char *file, char *extension);

#endif

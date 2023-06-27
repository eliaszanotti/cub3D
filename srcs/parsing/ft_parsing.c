/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:57:06 by ezanotti          #+#    #+#             */
/*   Updated: 2023/06/27 12:50:55 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_parse_fd(t_args *args, char *cub_file)
{
	int	fd;

	if (!*cub_file)
		return (ft_error(3));
	if (!ft_is_correct_extension(cub_file, ".cub"))
		return (ft_error(4));
	fd = open(cub_file, O_RDONLY);
	if (fd < 0)
		return (close(fd), ft_error(5));
	if (ft_get_infos(args, fd))
		return (close(fd), ft_free_struct(args), close(fd), 1);
	if (ft_get_map(args, fd))
		return (close(fd), ft_free_list(args->map_list), ft_free_struct(args), 1);
	close(fd);
	return (0);
}

static int	ft_parse_map(t_args *args)
{
	if (!ft_is_valid_map(args))
		return (ft_free_list(args->map_list), ft_free_struct(args), \
			ft_error(6));
	if (ft_fill_map(args))
		return (ft_free_list(args->map_list), ft_free_struct(args), 1);
	if (ft_convert_list(args))
		return (ft_free_list(args->map_list), ft_free_struct(args), 1);
	if (ft_check_walls(args))
		return (ft_free_str(args->map), ft_free_struct(args), 1);
	return (0);
}

int	ft_parsing(t_args *args, char *cub_file)
{
	if (ft_parse_fd(args, cub_file))
		return (1);
	if (ft_parse_map(args))
		return (1);
	return (0);
}

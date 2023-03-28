/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:57:06 by ezanotti          #+#    #+#             */
/*   Updated: 2023/03/28 14:10:18 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_parsing(t_args *args, char *cub_file)
{
	int	fd;

	if (!*cub_file)
		return (ft_error(3));
	if (!ft_is_extension_correct(cub_file, ".cub"))
		return (ft_error(4));
	fd = open(cub_file, O_RDONLY);
	if (fd < 0)
		return (ft_error(5));
	if (ft_parse_infos(args, fd))
		return (ft_free_struct(args), close(fd), 1);
	if (ft_parse_map(args, fd))
		return (ft_free_struct(args), 1);
	close(fd);
	if (!ft_is_valid_map(args))
		return (ft_free_struct(args), ft_error(6));
	if (ft_fill_map(args))
		return (ft_free_struct(args), 1);
	if (ft_convert_list(args))
		return (ft_free_struct(args), 1);
	if (ft_check_walls(args))
		return (ft_free_struct(args), 1);
	return (0);
}

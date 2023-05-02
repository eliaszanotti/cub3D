/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:57:06 by ezanotti          #+#    #+#             */
/*   Updated: 2023/05/02 16:52:37 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_finish_gnl(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
			printf("%s", line);
	}
	free(line);
	return (0);
}

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
		return (ft_free_list(args->map_list), ft_free_struct(args), 1);
	if (!ft_is_valid_map(args))
		return (ft_free_list(args->map_list), ft_free_struct(args), \
			ft_error(6));
	if (ft_fill_map(args))
		return (ft_free_list(args->map_list), ft_free_struct(args), 1);
	if (ft_convert_list(args))
		return (ft_free_list(args->map_list), ft_free_struct(args), 1);
	if (ft_check_walls(args))
		return (ft_free_str(args->map), ft_free_struct(args), 1);
	ft_finish_gnl(fd);
	close(fd);
	return (0);
}

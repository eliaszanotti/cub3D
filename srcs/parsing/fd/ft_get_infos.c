/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_infos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:57:56 by ezanotti          #+#    #+#             */
/*   Updated: 2023/04/06 14:45:29 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_is_filled(t_args *args)
{
	if (!args->north_path || !args->south_path || \
	!args->west_path || !args->east_path)
		return (0);
	if (!args->floor || !args->ceiling)
		return (0);
	return (1);
}

static int	ft_compare_line(t_args *args, char *line)
{
	if (!ft_strncmp("NO", line, 2) && !args->north_path)
		args->north_path = ft_substr(line, 3, ft_strlen(line) - 4);
	else if (!ft_strncmp("SO", line, 2) && !args->south_path)
		args->south_path = ft_substr(line, 3, ft_strlen(line) - 4);
	else if (!ft_strncmp("WE", line, 2) && !args->west_path)
		args->west_path = ft_substr(line, 3, ft_strlen(line) - 4);
	else if (!ft_strncmp("EA", line, 2) && !args->east_path)
		args->east_path = ft_substr(line, 3, ft_strlen(line) - 4);
	else if (!ft_strncmp("F", line, 1) && !args->floor)
		args->floor = ft_substr(line, 2, ft_strlen(line) - 3);
	else if (!ft_strncmp("C", line, 1) && !args->ceiling)
		args->ceiling = ft_substr(line, 2, ft_strlen(line) - 3);
	return (0);
}

static int	ft_fill_infos(t_args *args, int fd)
{
	char	*line;
	int		i;

	while (!ft_is_filled(args))
	{
		i = 0;
		line = get_next_line(fd);
		if (!line)
			return (ft_error(6));
		while (line[i] == ' ')
			i++;
		if (*line && ft_compare_line(args, line + i))
			return (free(line), 1);
		free(line);
	}
	return (0);
}

int	ft_get_infos(t_args *args, int fd)
{
	if (ft_fill_infos(args, fd))
		return (1);
	if (ft_parse_colors(args))
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_infos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:57:56 by ezanotti          #+#    #+#             */
/*   Updated: 2023/03/10 17:58:37 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_is_filled(t_args *args)
{
	if (!args->north || !args->south || !args->west || !args->east)
		return (0);
	if (!args->floor || !args->ceiling)
		return (0);
	return (1);
}

static int	ft_compare_line(t_args *args, char *line)
{
	if (!ft_strncmp("NO", line, 2))
		args->north = ft_strdup(line + 2);
	else if (!ft_strncmp("SO", line, 2))
		args->south = ft_strdup(line + 2);
	else if (!ft_strncmp("WE", line, 2))
		args->west = ft_strdup(line + 2);
	else if (!ft_strncmp("EA", line, 2))
		args->east = ft_strdup(line + 2);
	else if (!ft_strncmp("F", line, 1))
		args->floor = ft_strdup(line + 1);
	else if (!ft_strncmp("C", line, 1))
		args->ceiling = ft_strdup(line + 1);
	return (0);
}

int	ft_parse_infos(t_args *args, int fd)
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
			return (1);
		free(line);
	}
	return (0);
}

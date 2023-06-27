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

static int	ft_convert_hexa(char **split_color)
{
	int	total;
	int	atoi;
	int	size;
	int	i;

	total = 0;
	size = -1;
	while (split_color[++size])
	{
		i = -1;
		while (split_color[size][++i])
			if (!ft_isdigit(split_color[size][i]))
				return (-1);
		atoi = ft_atoi(split_color[size]);
		if (atoi > 255 || atoi < 0)
			return (-1);
		total += atoi << (2 - size) * 8;
	}
	return (total);
}

static int	ft_parse_colors(char *element)
{
	char	**split_color;
	int		size;
	int		total;

	split_color = ft_split(element, ',');
	if (!split_color)
		return (-1);
	size = 0;
	while (split_color[size])
		size++;
	if (size != 3)
		return (-1);
	total = ft_convert_hexa(split_color);
	if (total == -1)
		return (-1);
	size = -1;
	while (split_color[++size])
		free(split_color[size]);
	free(split_color);
	return (total);
}

int	ft_get_infos(t_args *args, int fd)
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
	args->floor_color = ft_parse_colors(args->floor);
	args->ceiling_color = ft_parse_colors(args->ceiling);
	if (args->floor_color == -1 || args->ceiling_color == -1)
		return (ft_error(8));
	return (0);
}

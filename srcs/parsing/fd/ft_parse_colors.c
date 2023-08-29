/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:03:27 by elias             #+#    #+#             */
/*   Updated: 2023/08/29 14:21:48 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_split_size(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return (0);
	while (split[i])
		i++;
	return (i);
}

static char	**ft_split_color(char *element)
{
	char	**split_color;
	char	*trim_color;	
	int		i;

	split_color = ft_split(element, ',');
	if (!split_color)
		return (NULL);
	i = -1;
	while (split_color[++i])
	{
		trim_color = ft_strtrim(split_color[i], " \t\n");
		if (!trim_color)
			return (NULL);
		free(split_color[i]);
		split_color[i] = trim_color;
	}
	return (split_color);
}

static int	ft_get_total(char *current_char, int size, int total)
{
	int	i;
	int	atoi;

	i = -1;
	while (current_char[++i])
		if (current_char[i] != ' ' && \
			!ft_isdigit(current_char[i]))
			return (-1);
	atoi = ft_atoi(current_char);
	if (atoi > 255 || atoi < 0)
		return (-1);
	total += atoi << (2 - size) * 8;
	return (total);
}

static int	ft_convert_hexa(char **split_color)
{
	int	total;
	int	size;

	total = 0;
	size = -1;
	while (split_color[++size])
	{
		total = ft_get_total(split_color[size], size, total);
		if (total == -1)
			return (-1);
	}
	ft_free_str(split_color);
	return (total);
}

int	ft_parse_colors(t_args *args)
{
	char	**split_color;

	split_color = ft_split_color(args->floor);
	if (!split_color)
		return (ft_error(99));
	if (ft_split_size(split_color) != 3)
		return (ft_free_str(split_color), ft_error(8));
	args->floor_color = ft_convert_hexa(split_color);
	if (args->floor_color == -1)
		return (ft_free_str(split_color), ft_error(8));
	split_color = ft_split_color(args->ceiling);
	if (!split_color)
		return (ft_error(99));
	if (ft_split_size(split_color) != 3)
		return (ft_free_str(split_color), ft_error(8));
	args->ceiling_color = ft_convert_hexa(split_color);
	if (args->ceiling_color == -1)
		return (ft_free_str(split_color), ft_error(8));
	return (0);
}

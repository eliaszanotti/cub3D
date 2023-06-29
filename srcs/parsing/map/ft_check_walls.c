/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:34:41 by elias             #+#    #+#             */
/*   Updated: 2023/04/05 13:03:39 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_is_wall(char c)
{
	if (c == '1' || c == '2')
		return (1);
	return (0);
}

static int	ft_check_void(t_args *args, int i, int j)
{
	int	width;
	int	height;

	width = ft_strlen(args->map[i]) - 1;
	height = 0;
	while (args->map[height])
		height++;
	if (i < height - 1 && !ft_is_wall(args->map[i + 1][j]))
		return (1);
	if (i > 0 && !ft_is_wall(args->map[i - 1][j]))
		return (1);
	if (j < width && !ft_is_wall(args->map[i][j + 1]))
		return (1);
	if (j > 0 && !ft_is_wall(args->map[i][j - 1]))
		return (1);
	return (0);
}

int	ft_check_walls(t_args *args)
{
	int	i;
	int	j;
	int	width;
	int	height;

	width = ft_strlen(args->map[0]) - 1;
	height = 0;
	while (args->map[height])
		height++;
	i = -1;
	while (args->map[++i])
	{
		j = -1;
		while (args->map[i][++j])
		{
			if (args->map[i][j] == '2' && ft_check_void(args, i, j))
				return (ft_error(7));
			if ((i == 0 || i == height - 1) && !ft_is_wall(args->map[i][j]))
				return (ft_error(7));
			if ((j == 0 || j == width) && !ft_is_wall(args->map[i][j]))
				return (ft_error(7));
		}
	}
	return (0);
}

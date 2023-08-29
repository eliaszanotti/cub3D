/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:42:42 by elias             #+#    #+#             */
/*   Updated: 2023/08/29 17:12:25 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_set_direction(t_args *args, double dir_x, double dir_y)
{
	args->ray->dir.x = dir_x;
	args->ray->dir.y = dir_y;
	return (0);
}

static int	ft_set_plane(t_args *args, double plane_x, double plane_y)
{
	args->ray->plane.x = plane_x;
	args->ray->plane.y = plane_y;
	return (0);
}

static int	ft_init_direction(t_args *args, char c)
{
	if (c == 'N')
	{
		ft_set_direction(args, -1, 0);
		ft_set_plane(args, 0, 0.66);
	}
	else if (c == 'S')
	{
		ft_set_direction(args, 1, 0);
		ft_set_plane(args, 0, -0.66);
	}
	else if (c == 'E')
	{
		ft_set_direction(args, 0, 1);
		ft_set_plane(args, 0.66, 0);
	}
	else if (c == 'W')
	{
		ft_set_direction(args, 0, -1);
		ft_set_plane(args, -0.66, 0);
	}
	return (0);
}

int	ft_init_ray(t_args *args)
{
	int	i;
	int	j;

	args->ray = malloc(sizeof(t_ray));
	if (!args->ray)
		return (ft_error(99));
	ft_reset_ray(args->ray);
	i = -1;
	while (args->map[++i])
	{
		j = -1;
		while (args->map[i][++j])
		{
			if (ft_isalpha(args->map[i][j]))
			{
				ft_init_direction(args, args->map[i][j]);
				args->ray->pos.x = i + 0.5;
				args->ray->pos.y = j + 0.5;
				return (0);
			}
		}
	}
	return (0);
}

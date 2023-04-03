/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_throw_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:26:52 by elias             #+#    #+#             */
/*   Updated: 2023/04/03 13:27:42 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_throw_ray(t_args *args)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (args->ray->side_dist_x < args->ray->side_dist_y)
		{
			args->ray->side_dist_x += args->ray->delta_dist_x;
			args->ray->map_x += args->ray->step_x;
			args->ray->side = NORTH;
			if (args->ray->map_x > args->ray->pos_x)
				args->ray->side = SOUTH;
		}
		else
		{
			args->ray->side_dist_y += args->ray->delta_dist_y;
			args->ray->map_y += args->ray->step_y;
			args->ray->side = WEST;
			if (args->ray->map_y > args->ray->pos_y)
				args->ray->side = EAST;
		}
		if (args->map[args->ray->map_x][args->ray->map_y] == '1')
			hit = 1;
	}
	return (0);
}

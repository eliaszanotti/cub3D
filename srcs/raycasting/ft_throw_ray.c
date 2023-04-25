/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_throw_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:26:52 by elias             #+#    #+#             */
/*   Updated: 2023/04/25 16:21:07 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_throw_ray(t_args *args)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (args->ray->side_dist.x < args->ray->side_dist.y)
		{
			args->ray->side_dist.x += args->ray->delta_dist.x;
			args->ray->map.x += args->ray->step_pos.x;
			args->ray->side = NORTH;
			if (args->ray->map.x > args->ray->pos.x)
				args->ray->side = SOUTH;
			if (args->map[args->ray->map.x][args->ray->map.y] == '3')
				args->ray->side = 4;
			args->ray->bool = 1;
		}
		else
		{
			args->ray->side_dist.y += args->ray->delta_dist.y;
			args->ray->map.y += args->ray->step_pos.y;
			args->ray->side = WEST;
			if (args->ray->map.y > args->ray->pos.y)
				args->ray->side = EAST;
			if (args->map[args->ray->map.x][args->ray->map.y] == '3')
				args->ray->side = 4;
			args->ray->bool = 0;
		}
		if (args->map[args->ray->map.x][args->ray->map.y] == '1' || args->map[args->ray->map.x][args->ray->map.y] == '3')
			hit = 1;
	}
	return (0);
}

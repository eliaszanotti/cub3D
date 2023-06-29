/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_throw_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:26:52 by elias             #+#    #+#             */
/*   Updated: 2023/06/29 15:09:11 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_hit_ns(t_args *args)
{
	args->ray->side_dist.x += args->ray->delta_dist.x;
	args->ray->map.x += args->ray->step_pos.x;
	args->ray->side = NORTH;
	if (args->ray->map.x > args->ray->pos.x)
		args->ray->side = SOUTH;
	if (args->map[args->ray->map.x][args->ray->map.y] == '3')
		args->ray->side = 4;
	args->ray->boolean = 1;
}

static void	ft_hit_ew(t_args *args)
{
	args->ray->side_dist.y += args->ray->delta_dist.y;
	args->ray->map.y += args->ray->step_pos.y;
	args->ray->side = WEST;
	if (args->ray->map.y > args->ray->pos.y)
		args->ray->side = EAST;
	if (args->map[args->ray->map.x][args->ray->map.y] == '3')
		args->ray->side = 4;
	args->ray->boolean = 0;
}

int	ft_throw_ray(t_args *args)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (args->ray->side_dist.x < args->ray->side_dist.y)
			ft_hit_ns(args);
		else
			ft_hit_ew(args);
		if (args->map[args->ray->map.x][args->ray->map.y] == '1' || \
			args->map[args->ray->map.x][args->ray->map.y] == '3')
			hit = 1;
	}
	return (0);
}

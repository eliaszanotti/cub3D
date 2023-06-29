/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_side_dist.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:10:11 by elias             #+#    #+#             */
/*   Updated: 2023/04/03 13:10:38 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_calculate_side_dist(t_args *args)
{
	if (args->ray->raydir.x < 0)
	{
		args->ray->step_pos.x = -1;
		args->ray->side_dist.x = (args->ray->pos.x - args->ray->map.x) \
			* args->ray->delta_dist.x;
	}
	else
	{
		args->ray->step_pos.x = 1;
		args->ray->side_dist.x = (args->ray->map.x + 1.0 - args->ray->pos.x) \
			* args->ray->delta_dist.x;
	}
	if (args->ray->raydir.y < 0)
	{
		args->ray->step_pos.y = -1;
		args->ray->side_dist.y = (args->ray->pos.y - args->ray->map.y) \
			* args->ray->delta_dist.y;
	}
	else
	{
		args->ray->step_pos.y = 1;
		args->ray->side_dist.y = (args->ray->map.y + 1.0 - args->ray->pos.y) \
			* args->ray->delta_dist.y;
	}
	return (0);
}

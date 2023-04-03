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
	if (args->ray->raydir_x < 0)
	{
		args->ray->step_x = -1;
		args->ray->side_dist_x = (args->ray->pos_x - args->ray->map_x) \
			* args->ray->delta_dist_x;
	}
	else
	{
		args->ray->step_x = 1;
		args->ray->side_dist_x = (args->ray->map_x + 1.0 - args->ray->pos_x) \
			* args->ray->delta_dist_x;
	}
	if (args->ray->raydir_y < 0)
	{
		args->ray->step_y = -1;
		args->ray->side_dist_y = (args->ray->pos_y - args->ray->map_y) \
			* args->ray->delta_dist_y;
	}
	else
	{
		args->ray->step_y = 1;
		args->ray->side_dist_y = (args->ray->map_y + 1.0 - args->ray->pos_y) \
			* args->ray->delta_dist_y;
	}
	return (0);
}

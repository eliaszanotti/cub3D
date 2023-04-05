/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:01:43 by elias             #+#    #+#             */
/*   Updated: 2023/04/05 12:30:55 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_init_values(t_args *args, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	args->ray->raydir_x = args->ray->dir_x + args->ray->plane_x * camera_x;
	args->ray->raydir_y = args->ray->dir_y + args->ray->plane_y * camera_x;
	args->ray->map_x = (int)args->ray->pos_x;
	args->ray->map_y = (int)args->ray->pos_y;
	args->ray->delta_dist_x = 1 / args->ray->raydir_x;
	args->ray->delta_dist_y = 1 / args->ray->raydir_y;
	if (args->ray->delta_dist_x < 0)
		args->ray->delta_dist_x *= -1;
	if (args->ray->delta_dist_y < 0)
		args->ray->delta_dist_y *= -1;
	args->ray->move_speed = 0.5;
	args->ray->rot_speed = 0.1;
	return (0);
}

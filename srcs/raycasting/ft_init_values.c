/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:01:43 by elias             #+#    #+#             */
/*   Updated: 2023/04/25 16:34:56 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_init_values(t_args *args, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	args->ray->raydir.x = args->ray->dir.x + args->ray->plane.x * camera_x;
	args->ray->raydir.y = args->ray->dir.y + args->ray->plane.y * camera_x;
	args->ray->map.x = (int)args->ray->pos.x;
	args->ray->map.y = (int)args->ray->pos.y;
	args->ray->delta_dist.x = 1 / args->ray->raydir.x;
	args->ray->delta_dist.y = 1 / args->ray->raydir.y;
	if (args->ray->delta_dist.x < 0)
		args->ray->delta_dist.x *= -1;
	if (args->ray->delta_dist.y < 0)
		args->ray->delta_dist.y *= -1;
	args->ray->move_speed = 0.14;
	args->ray->rot_speed = 0.66 * args->ray->move_speed;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:56:24 by ezanotti          #+#    #+#             */
/*   Updated: 2023/08/29 17:12:49 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_reset_ray(t_ray *ray)
{
	ray->pos.x = 0;
	ray->pos.y = 0;
	ray->dir.x = 0;
	ray->dir.y = 0;
	ray->plane.x = 0;
	ray->plane.y = 0;
	ray->raydir.x = 0;
	ray->raydir.y = 0;
	ray->side_dist.x = 0;
	ray->side_dist.y = 0;
	ray->delta_dist.x = 0;
	ray->delta_dist.y = 0;
	ray->map.x = 0;
	ray->map.y = 0;
	ray->step_pos.x = 0;
	ray->step_pos.y = 0;
	ray->move_speed = 0;
	ray->rot_speed = 0;
	ray->tex_pos = 0;
	ray->step = 0;
	ray->perp_wall_dist = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
	ray->side = 0;
	ray->boolean = 0;
}

int	ft_reset_struct(t_args *args)
{
	args->north_path = NULL;
	args->south_path = NULL;
	args->west_path = NULL;
	args->east_path = NULL;
	args->floor = NULL;
	args->ceiling = NULL;
	args->map_list = NULL;
	args->expanded = 0;
	args->turn_left = 0;
	args->turn_right = 0;
	args->move_up = 0;
	args->move_down = 0;
	args->move_left = 0;
	args->move_right = 0;
	args->last_x = -1;
	args->is_paused = 0;
	args->flash_timer = 0;
	args->door_delay = 0;
	return (0);
}

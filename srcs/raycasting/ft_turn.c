/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:27:16 by ezanotti          #+#    #+#             */
/*   Updated: 2023/04/11 16:35:39 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_turn_left(t_args *args)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = args->ray->dir_x;
	args->ray->dir_x = args->ray->dir_x * cos(args->ray->rot_speed) - \
		args->ray->dir_y * sin(args->ray->rot_speed);
	args->ray->dir_y = olddir_x * sin(args->ray->rot_speed) + \
		args->ray->dir_y * cos(args->ray->rot_speed);
	oldplane_x = args->ray->plane_x;
	args->ray->plane_x = args->ray->plane_x * cos(args->ray->rot_speed) \
		- args->ray->plane_y * sin(args->ray->rot_speed);
	args->ray->plane_y = oldplane_x * sin(args->ray->rot_speed) \
		+ args->ray->plane_y * cos(args->ray->rot_speed);
}

void	ft_turn_right(t_args *args)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = args->ray->dir_x;
	args->ray->dir_x = args->ray->dir_x * cos(-args->ray->rot_speed) \
		- args->ray->dir_y * sin(-args->ray->rot_speed);
	args->ray->dir_y = olddir_x * sin(-args->ray->rot_speed) \
		+ args->ray->dir_y * cos(-args->ray->rot_speed);
	oldplane_x = args->ray->plane_x;
	args->ray->plane_x = args->ray->plane_x * cos(-args->ray->rot_speed) \
		- args->ray->plane_y * sin(-args->ray->rot_speed);
	args->ray->plane_y = oldplane_x * sin(-args->ray->rot_speed) \
		+ args->ray->plane_y * cos(-args->ray->rot_speed);
}

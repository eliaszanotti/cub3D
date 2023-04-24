/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:27:16 by ezanotti          #+#    #+#             */
/*   Updated: 2023/04/24 16:52:27 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_turn_left(t_args *args)
{
	double	olddir_x;
	double	oldplane_x;
	double	rot;

	rot = args->ray->rot_speed;
	olddir_x = args->ray->dir_x;
	args->ray->dir_x = args->ray->dir_x * cos(rot) - \
		args->ray->dir_y * sin(rot);
	args->ray->dir_y = olddir_x * sin(rot) + \
		args->ray->dir_y * cos(rot);
	oldplane_x = args->ray->plane_x;
	args->ray->plane_x = args->ray->plane_x * cos(rot) \
		- args->ray->plane_y * sin(rot);
	args->ray->plane_y = oldplane_x * sin(rot) \
		+ args->ray->plane_y * cos(rot);
}

void	ft_turn_right(t_args *args)
{
	double	olddir_x;
	double	oldplane_x;
	double	rot;

	rot = args->ray->rot_speed;
	olddir_x = args->ray->dir_x;
	args->ray->dir_x = args->ray->dir_x * cos(-rot) \
		- args->ray->dir_y * sin(-rot);
	args->ray->dir_y = olddir_x * sin(-rot) \
		+ args->ray->dir_y * cos(-rot);
	oldplane_x = args->ray->plane_x;
	args->ray->plane_x = args->ray->plane_x * cos(-rot) \
		- args->ray->plane_y * sin(-rot);
	args->ray->plane_y = oldplane_x * sin(-rot) \
		+ args->ray->plane_y * cos(-rot);
}

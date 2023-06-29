/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_positions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:55:35 by elias             #+#    #+#             */
/*   Updated: 2023/06/29 15:42:20 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_calculate_height(t_args *args)
{
	if (args->ray->boolean)
		args->ray->perp_wall_dist = \
			(args->ray->side_dist.x - args->ray->delta_dist.x);
	else
		args->ray->perp_wall_dist = \
			(args->ray->side_dist.y - args->ray->delta_dist.y);
	return ((int)(SCREEN_HEIGHT / args->ray->perp_wall_dist));
}

static int	ft_calculate_range(t_args *args, int line_height)
{
	args->ray->draw_start = -line_height / 2 + SCREEN_HEIGHT / 2;
	if (args->ray->draw_start < 0)
		args->ray->draw_start = 0;
	args->ray->draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
	if (args->ray->draw_end >= SCREEN_HEIGHT)
		args->ray->draw_end = SCREEN_HEIGHT - 1;
	return (0);
}

static int	ft_calculate_textures(t_args *args, int line_height)
{
	double	wall_x;

	if (args->ray->boolean)
		wall_x = args->ray->pos.y + args->ray->perp_wall_dist * \
			args->ray->raydir.y;
	else
		wall_x = args->ray->pos.x + args->ray->perp_wall_dist * \
			args->ray->raydir.x;
	args->ray->tex.x = (int)(wall_x * IMG_SIZE);
	if (args->ray->side <= 1 && args->ray->raydir.x > 0)
		args->ray->tex.x = IMG_SIZE - args->ray->tex.x - 1;
	else if (args->ray->side >= 2 && args->ray->raydir.y < 0)
		args->ray->tex.x = IMG_SIZE - args->ray->tex.x - 1;
	args->ray->step = 1.0 * IMG_SIZE / line_height;
	args->ray->tex_pos = (args->ray->draw_start - SCREEN_HEIGHT / 2 + \
	line_height / 2) * args->ray->step;
	return (0);
}

int	ft_calculate_positions(t_args *args)
{
	int	line_height;

	line_height = ft_calculate_height(args);
	if (ft_calculate_range(args, line_height))
		return (1);
	if (ft_calculate_textures(args, line_height))
		return (1);
	return (0);
}

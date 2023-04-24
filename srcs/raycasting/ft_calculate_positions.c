/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_positions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:55:35 by elias             #+#    #+#             */
/*   Updated: 2023/04/05 13:53:32 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_calculate_height(t_args *args)
{
	if (args->ray->side == 0 || args->ray->side == 1)
		args->ray->perp_wall_dist = \
			(args->ray->side_dist_x - args->ray->delta_dist_x);
	else
		args->ray->perp_wall_dist = \
			(args->ray->side_dist_y - args->ray->delta_dist_y);
	return ((int)(SCREEN_HEIGHT / args->ray->perp_wall_dist));
}

int	ft_calculate_positions(t_args *a)
{
	double	wall_x;
	int		line_height;

	line_height = ft_calculate_height(a);
	a->ray->draw_start = -line_height / 2 + SCREEN_HEIGHT / 2;
	if (a->ray->draw_start < 0)
		a->ray->draw_start = 0;
	a->ray->draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
	if (a->ray->draw_end >= SCREEN_HEIGHT)
		a->ray->draw_end = SCREEN_HEIGHT - 1;
	if (a->ray->side == 0 || a->ray->side == 1)
		wall_x = a->ray->pos_y + a->ray->perp_wall_dist * a->ray->raydir_y;
	else
		wall_x = a->ray->pos_x + a->ray->perp_wall_dist * a->ray->raydir_x;
	a->ray->tex_x = (int)(wall_x * IMG_SIZE);
	if (a->ray->side <= 1 && a->ray->raydir_x > 0)
		a->ray->tex_x = IMG_SIZE - a->ray->tex_x - 1;
	else if (a->ray->side >= 2 && a->ray->raydir_y < 0)
		a->ray->tex_x = IMG_SIZE - a->ray->tex_x - 1;
	a->ray->step = 1.0 * IMG_SIZE / line_height;
	a->ray->tex_pos = (a->ray->draw_start - SCREEN_HEIGHT / 2 + \
	line_height / 2) * a->ray->step;
	return (0);
}

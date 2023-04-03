/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:37:46 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/04/03 10:39:51 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3D.h"

void	ft_init_raycasting(t_args *args, int x)
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
	args->ray->move_speed = 5 * 0.032;
	args->ray->rot_speed = 3 * 0.032;
}

void	ft_calcul_side_dist(t_args *args)
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
}

void	ft_throw_ray(t_args *args)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (args->ray->side_dist_x < args->ray->side_dist_y)
		{
			args->ray->side_dist_x += args->ray->delta_dist_x;
			args->ray->map_x += args->ray->step_x;
			args->ray->side = NORTH;
			if (args->ray->map_x > args->ray->pos_x)
				args->ray->side = SOUTH;
		}
		else
		{
			args->ray->side_dist_y += args->ray->delta_dist_y;
			args->ray->map_y += args->ray->step_y;
			args->ray->side = WEST;
			if (args->ray->map_y > args->ray->pos_y)
				args->ray->side = EAST;
		}
		if (args->map[args->ray->map_x][args->ray->map_y] == '1')
			hit = 1;
	}
}

void	ft_calcul(t_args *a)
{
	double	wall_x;
	int		line_height;

	if (a->ray->side == 0 || a->ray->side == 1)
		a->ray->perp_wall_dist = (a->ray->side_dist_x - a->ray->delta_dist_x);
	else
		a->ray->perp_wall_dist = (a->ray->side_dist_y - a->ray->delta_dist_y);
	line_height = (int)(SCREEN_HEIGHT / a->ray->perp_wall_dist);
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
	a->ray->tex_x = (int)(wall_x * 64.0);
	if (a->ray->side <= 1 && a->ray->raydir_x > 0)
		a->ray->tex_x = 64 - a->ray->tex_x - 1;
	if (a->ray->side >= 2 && a->ray->raydir_y < 0)
		a->ray->tex_x = 64 - a->ray->tex_x - 1;
	a->ray->step = 1.0 * 64 / line_height;
	a->ray->tex_pos = (a->ray->draw_start - SCREEN_HEIGHT / 2 + \
	line_height / 2) * a->ray->step;
}

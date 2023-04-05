/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 12:13:46 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/04/05 12:03:21 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_turn_left(t_args *args)
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

static void	ft_turn_right(t_args *args)
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
	args->ray->plane_y = oldplane_x * sin(-args->ray->rot_speed) + \
	args->ray->plane_y * cos(-args->ray->rot_speed);
}

static void	ft_move_up(t_args *args)
{
	if (args->map[(int)(args->ray->pos_x + args->ray->dir_x * \
	args->ray->move_speed)][(int)args->ray->pos_y] != '1')
		args->ray->pos_x += args->ray->dir_x * args->ray->move_speed;
	if (args->map[(int)args->ray->pos_x][(int)(args->ray->pos_y + \
	args->ray->dir_y * args->ray->move_speed)] != '1')
		args->ray->pos_y += args->ray->dir_y * args->ray->move_speed;
}

static void	ft_move_down(t_args *args)
{
	if (args->map[(int)(args->ray->pos_x - args->ray->dir_x * \
	args->ray->move_speed)][(int)args->ray->pos_y] != '1')
		args->ray->pos_x -= args->ray->dir_x * args->ray->move_speed;
	if (args->map[(int)args->ray->pos_x][(int)(args->ray->pos_y - \
	args->ray->dir_y * args->ray->move_speed)] != '1')
		args->ray->pos_y -= args->ray->dir_y * args->ray->move_speed;
}

static void	ft_move_right(t_args *args)
{
	if (args->map[(int)(args->ray->pos_x + args->ray->dir_y * \
	args->ray->move_speed)][(int)args->ray->pos_y] != '1')
		args->ray->pos_x += args->ray->dir_y * args->ray->move_speed;
	if (args->map[(int)args->ray->pos_x][(int)(args->ray->pos_y - \
	args->ray->dir_x * args->ray->move_speed)] != '1')
		args->ray->pos_y -= args->ray->dir_x * args->ray->move_speed;
}

static void	ft_move_left(t_args *args)
{
	if (args->map[(int)(args->ray->pos_x - args->ray->dir_y * \
	args->ray->move_speed)][(int)args->ray->pos_y] != '1')
		args->ray->pos_x -= args->ray->dir_y * args->ray->move_speed;
	if (args->map[(int)args->ray->pos_x][(int)(args->ray->pos_y + \
	args->ray->dir_x * args->ray->move_speed)] != '1')
		args->ray->pos_y += args->ray->dir_x * args->ray->move_speed;
}

void	ft_move(t_args *args)
{
	if (args->turn_left)
		ft_turn_left(args);
	if (args->turn_right)
		ft_turn_right(args);
	if (args->move_up)
		ft_move_up(args);
	if (args->move_down)
		ft_move_down(args);
	if (args->move_right)
		ft_move_right(args);
	if (args->move_left)
		ft_move_left(args);
}

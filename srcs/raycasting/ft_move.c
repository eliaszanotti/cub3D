/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 12:13:46 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/04/11 16:27:52 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

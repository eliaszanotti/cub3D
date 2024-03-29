/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 12:13:46 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/04/25 18:35:50 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_move_up(t_args *args)
{
	t_point	value;

	value.x = args->map[(int)(args->ray->pos.x + args->ray->dir.x * \
		args->ray->move_speed)][(int)args->ray->pos.y];
	value.y = args->map[(int)args->ray->pos.x][(int)(args->ray->pos.y + \
		args->ray->dir.y * args->ray->move_speed)];
	if (value.x != '1' && value.x != '3')
		args->ray->pos.x += args->ray->dir.x * args->ray->move_speed;
	if (value.y != '1' && value.y != '3')
		args->ray->pos.y += args->ray->dir.y * args->ray->move_speed;
}

static void	ft_move_down(t_args *args)
{
	t_point	value;

	value.x = args->map[(int)(args->ray->pos.x - args->ray->dir.x * \
		args->ray->move_speed)][(int)args->ray->pos.y];
	value.y = args->map[(int)args->ray->pos.x][(int)(args->ray->pos.y - \
		args->ray->dir.y * args->ray->move_speed)];
	if (value.x != '1' && value.y != '3')
		args->ray->pos.x -= args->ray->dir.x * args->ray->move_speed;
	if (value.y != '1' && value.y != '3')
		args->ray->pos.y -= args->ray->dir.y * args->ray->move_speed;
}

static void	ft_move_right(t_args *args)
{
	t_point	value;

	value.x = args->map[(int)(args->ray->pos.x + args->ray->dir.y * \
		args->ray->move_speed)][(int)args->ray->pos.y];
	value.y = args->map[(int)args->ray->pos.x][(int)(args->ray->pos.y - \
		args->ray->dir.x * args->ray->move_speed)];
	if (value.x != '1' && value.x != '3')
		args->ray->pos.x += args->ray->dir.y * args->ray->move_speed;
	if (value.y != '1' && value.y != '3')
		args->ray->pos.y -= args->ray->dir.x * args->ray->move_speed;
}

static void	ft_move_left(t_args *args)
{
	t_point	value;

	value.x = args->map[(int)(args->ray->pos.x - args->ray->dir.y * \
		args->ray->move_speed)][(int)args->ray->pos.y];
	value.y = args->map[(int)args->ray->pos.x][(int)(args->ray->pos.y + \
		args->ray->dir.x * args->ray->move_speed)];
	if (value.x != '1' && value.x != '3')
		args->ray->pos.x -= args->ray->dir.y * args->ray->move_speed;
	if (value.y != '1' && value.y != '3')
		args->ray->pos.y += args->ray->dir.x * args->ray->move_speed;
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

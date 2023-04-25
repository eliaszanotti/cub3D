/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:43:39 by elias             #+#    #+#             */
/*   Updated: 2023/04/25 18:32:37 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_state_door(t_args *args)
{
	if (args->map[(int)(args->ray->pos.x + round(args->ray->dir.x))] \
		[(int)(args->ray->pos.y + round(args->ray->dir.y))] == '3')
	{
		args->map[(int)(args->ray->pos.x + round(args->ray->dir.x))] \
			[(int)(args->ray->pos.y + round(args->ray->dir.y))] = '4';
	}
	else if (args->map[(int)(args->ray->pos.x + round(args->ray->dir.x))] \
		[(int)(args->ray->pos.y + round(args->ray->dir.y))] == '4')
		args->map[(int)(args->ray->pos.x + round(args->ray->dir.x))] \
			[(int)(args->ray->pos.y + round(args->ray->dir.y))] = '3';
	printf("%c\n", args->map[(int)(args->ray->pos.x + round(args->ray->dir.x))] \
	[(int)(args->ray->pos.y + round(args->ray->dir.y))]);
}

int	hook_keypress(int key, t_args *args)
{
	if (key == P_KEY)
		args->is_paused = args->is_paused ^ 1;
	if (args->is_paused)
		return (0);
	if (key == ESC_KEY)
		ft_exit(args);
	if (key == LEFT_ARROW_KEY)
		args->turn_left = 1;
	else if (key == RIGHT_ARROW_KEY)
		args->turn_right = 1;
	else if (key == W_LOWER_KEY)
		args->move_up = 1;
	else if (key == S_LOWER_KEY)
		args->move_down = 1;
	else if (key == A_LOWER_KEY)
		args->move_left = 1;
	else if (key == D_LOWER_KEY)
		args->move_right = 1;
	else if (key == M_KEY)
		args->expanded = args->expanded ^ 1;
	else if (key == SPACE_KEY)
		ft_state_door(args);
	return (0);
}

int	hook_keyrelease(int key, t_args *args)
{
	(void)key;
	if (key == LEFT_ARROW_KEY)
		args->turn_left = 0;
	else if (key == RIGHT_ARROW_KEY)
		args->turn_right = 0;
	else if (key == W_LOWER_KEY)
		args->move_up = 0;
	else if (key == S_LOWER_KEY)
		args->move_down = 0;
	else if (key == A_LOWER_KEY)
		args->move_left = 0;
	else if (key == D_LOWER_KEY)
		args->move_right = 0;
	else if (key == SPACE_KEY)
		args->space_press = 0;
	return (0);
}

int	ft_mouse_hook(int x, int y, t_args *args)
{
	(void)y;
	if (args->is_paused)
		return (0);
	if (args->last_x == -1)
		x = SCREEN_WIDTH / 2;
	if (x != args->last_x)
	{
		args->turn_left = 0;
		args->turn_right = 0;
	}
	if (args->last_x > x + 5 && x != (int)(SCREEN_WIDTH / 2))
		args->turn_left = 1;
	else if (args->last_x < x - 5 && x != (int)(SCREEN_WIDTH / 2))
		args->turn_right = 1;
	args->last_x = x;
	return (0);
}

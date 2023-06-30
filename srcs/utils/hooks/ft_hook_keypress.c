/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_keypress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:43:39 by elias             #+#    #+#             */
/*   Updated: 2023/06/30 12:20:32 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_change_state_door(t_args *args)
{
	if (args->map[(int)(args->ray->pos.x + round(args->ray->dir.x))] \
		[(int)(args->ray->pos.y + round(args->ray->dir.y))] == '3')
	{
		args->map[(int)(args->ray->pos.x + round(args->ray->dir.x))] \
			[(int)(args->ray->pos.y + round(args->ray->dir.y))] = '4';
		args->door_delay = 0;
	}
}

int	ft_hook_keypress(int key, t_args *args)
{
	if (key == P_KEY)
		args->is_paused = args->is_paused ^ 1;
	if (key == ESC_KEY)
		ft_exit(args);
	if (args->is_paused)
		return (0);
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
	else if (key == M_KEY && args->flash_timer > 100)
		args->expanded = args->expanded ^ 1;
	else if (key == SPACE_KEY)
		ft_change_state_door(args);
	return (0);
}

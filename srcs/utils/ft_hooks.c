/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:43:39 by elias             #+#    #+#             */
/*   Updated: 2023/04/24 17:03:27 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	hook_keypress(int key, t_args *args)
{
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
	return (0);
}

int	ft_mouse_hook(int x, int y, t_args *args)
{
	(void)y;
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

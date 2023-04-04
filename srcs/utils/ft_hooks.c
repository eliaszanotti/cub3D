/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:43:39 by elias             #+#    #+#             */
/*   Updated: 2023/04/04 11:19:16 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	hook_keypress(int key, t_args *args)
{
	if (key == ESC_KEY)
		exit(0);
	if (key == LEFT_ARROW_KEY)
		args->move_left = 1;
	if (key == UP_ARROW_KEY)
		args->move_up = 1;
	if (key == RIGHT_ARROW_KEY)
		args->move_right = 1;
	if (key == DOWN_ARROW_KEY)
		args->move_down = 1;
	if (key == M_KEY)
		args->expanded = args->expanded ^ 1;
	ft_move(args);
	mlx_destroy_image(args->mlx->mlx, args->mlx->img.img);
	ft_loop(args);
	return (0);
}

int	hook_keyrelease(int key, t_args *args)
{
	if (key == LEFT_ARROW_KEY)
		args->move_left = 0;
	if (key == UP_ARROW_KEY)
		args->move_up = 0;
	if (key == RIGHT_ARROW_KEY)
		args->move_right = 0;
	if (key == DOWN_ARROW_KEY)
		args->move_down = 0;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:18:39 by elias             #+#    #+#             */
/*   Updated: 2023/06/30 12:19:03 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

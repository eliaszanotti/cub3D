/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_keyrelease.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:23:02 by elias             #+#    #+#             */
/*   Updated: 2023/06/30 12:23:10 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_hook_keyrelease(int key, t_args *args)
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

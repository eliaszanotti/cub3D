/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:56:24 by ezanotti          #+#    #+#             */
/*   Updated: 2023/08/29 16:21:43 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_reset_struct(t_args *args)
{
	args->north_path = NULL;
	args->south_path = NULL;
	args->west_path = NULL;
	args->east_path = NULL;
	args->floor = NULL;
	args->ceiling = NULL;
	args->map_list = NULL;
	args->expanded = 0;
	args->turn_left = 0;
	args->turn_right = 0;
	args->move_up = 0;
	args->move_down = 0;
	args->move_left = 0;
	args->move_right = 0;
	args->last_x = -1;
	args->is_paused = 0;
	args->flash_timer = 0;
	args->door_delay = 0;
	return (0);
}

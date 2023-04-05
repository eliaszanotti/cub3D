/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:56:24 by ezanotti          #+#    #+#             */
/*   Updated: 2023/04/05 13:18:33 by tgiraudo         ###   ########.fr       */
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
	args->expanded = 1;
	args->turn_left = 0;
	args->turn_right = 0;
	args->move_up = 0;
	args->move_down = 0;
	args->move_left = 0;
	args->move_right = 0;
	return (0);
}

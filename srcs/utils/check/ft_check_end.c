/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:42:32 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/06/30 12:09:09 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_check_end(t_args *args)
{
	t_point	pos;

	pos.x = args->ray->pos.x;
	pos.y = args->ray->pos.y;
	if (args->map[pos.x][pos.y] == '6')
	{
		args->is_paused = 1;
		args->end = 1;
	}
	else
		args->end = 0;
	return (0);
}

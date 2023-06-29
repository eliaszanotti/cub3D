/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_doors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:45:15 by elias             #+#    #+#             */
/*   Updated: 2023/06/29 16:45:42 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_close_doors(t_args *args)
{
	int		i;
	int		j;

	i = -1;
	while (args->map[++i])
	{
		j = -1;
		while (args->map[i][++j])
		{
			if (args->map[i][j] == '4' && ((int)args->ray->pos.y != j || \
				(int)args->ray->pos.x != i))
				args->map[i][j] = '3';
		}
	}
	args->door_delay = 0;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_screamer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:08:33 by elias             #+#    #+#             */
/*   Updated: 2023/06/30 12:11:38 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_check_screamer(t_args *args)
{
	t_point	pos;

	pos.x = args->ray->pos.x;
	pos.y = args->ray->pos.y;
	if (args->map[pos.x][pos.y] == '5')
		args->screamer = 1;
	else
		args->screamer = 0;
	return (0);
}

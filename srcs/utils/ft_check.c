/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:42:32 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/06/29 16:40:34 by elias            ###   ########.fr       */
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

void	ft_print_square(t_img *img, int x, int y)
{
	int	i;
	int	j;

	i = x - 1;
	while (++i < x + 20)
	{
		j = y - 1;
		while (++j < y + 20)
			ft_mlx_pixel_put(img, i, j, 0xFCA510);
	}
}

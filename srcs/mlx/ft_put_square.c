/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:12:38 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/04/03 15:56:46 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_put_square(t_args *args, int x, int y, int color)
{
	int	i;
	int	j;
	int	dx;
	int	dy;

	i = -1;
	if (x < 0 || y < 0)
		return ;
	while (++i < CUB_SIZE)
	{
		j = -1;
		dx = abs((x * CUB_SIZE) + i - 110);
		while (++j < CUB_SIZE)
		{
			dy = abs((y * CUB_SIZE) + j - 110);
			if (args->expanded == 1 && sqrt(dx * dx + dy * dy) < 100)
				ft_mlx_pixel_put(&args->mlx->img, (x * CUB_SIZE) + i, \
					(y * CUB_SIZE) + j, color);
			if (args->expanded == 0 && sqrt(dx * dx + dy * dy) < 40)
				ft_mlx_pixel_put(&args->mlx->img, (x * CUB_SIZE) + i, \
					(y * CUB_SIZE) + j, color);
		}
	}
}

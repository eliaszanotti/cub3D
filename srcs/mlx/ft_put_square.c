/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:12:38 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/04/03 15:22:42 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_put_square(t_img *img, int x, int y, int color)
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
		dx = abs((x * CUB_SIZE) + i - 100);
		while (++j < CUB_SIZE)
		{
			dy = abs((y * CUB_SIZE) + j - 100);
			if (sqrt(dx * dx + dy * dy) < 80)
				ft_mlx_pixel_put(img, (x * CUB_SIZE) + i, \
					(y * CUB_SIZE) + j, color);
		}
	}
}

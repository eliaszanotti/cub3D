/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:39:01 by elias             #+#    #+#             */
/*   Updated: 2023/03/30 18:23:52 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_put_square(t_img *img, int x, int y, int color)
{
	int	i;
	int	j;

	i = -1;
	if (x < 0 || y < 0)
		return ;
	while (++i < CUB_SIZE)
	{
		j = -1;
		while (++j < CUB_SIZE)
			my_mlx_pixel_put(img, (x * CUB_SIZE) + i, \
				(y * CUB_SIZE) + j, color);
	}
}

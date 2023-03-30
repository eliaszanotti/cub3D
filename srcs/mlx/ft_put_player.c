/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:39:00 by elias             #+#    #+#             */
/*   Updated: 2023/03/30 18:35:06 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_put_player(t_img *img, int color)
{
	int	i;
	int	j;

	i = CUB_SIZE / 4 - 1;
	while (++i < CUB_SIZE / 2 + CUB_SIZE / 4)
	{
		j = CUB_SIZE / 4 - 1;
		while (++j < CUB_SIZE / 2 + CUB_SIZE / 4)
			my_mlx_pixel_put(img, (10 * CUB_SIZE + CUB_SIZE) + i, \
				(10 * CUB_SIZE + CUB_SIZE) + j, color);
	}	
}

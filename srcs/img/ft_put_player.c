/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:39:00 by elias             #+#    #+#             */
/*   Updated: 2023/03/29 15:39:05 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_put_player(t_img *img)
{
	int	i;
	int	j;

	i = -1;
	while (++i < CUB_SIZE / 2)
	{
		j = -1;
		while (j++ < CUB_SIZE / 2)
			my_mlx_pixel_put(img, (img->x * CUB_SIZE + 8) + i, (img->y * CUB_SIZE + 8) + j, 0x0000FF);
	}	
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_minimap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:46:07 by elias             #+#    #+#             */
/*   Updated: 2023/03/30 17:46:56 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int ft_print_minimap(t_args *args, t_img *img)
{
	img->y = -1;
	while (args->map[++img->y])
	{
		img->x = -1;
		while (args->map[img->y][++img->x])
		{
			if (args->map[img->y][img->x] == '1')
				ft_put_square(img, CUB_SIZE, 0xFFFFFF);
			else if (args->map[img->y][img->x] != '1' && \
				args->map[img->y][img->x] != '2')
				ft_put_square(img, CUB_SIZE, args->floor_color);
		}	
	}
	args->mlx->image.y = args->ray->posX - 1;
	args->mlx->image.x = args->ray->posY - 1;
	ft_put_player(img, 0x0000FF);
    return (0);
}

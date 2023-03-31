/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_minimap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:46:07 by elias             #+#    #+#             */
/*   Updated: 2023/03/31 15:07:11 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int ft_print_minimap(t_args *args, t_img *img)
{
	int	x;
	int	y;

	img->y = -1;
	while (args->map[++img->y])
	{
		img->x = -1;
		while (args->map[img->y][++img->x])
		{
			x = img->x + 12 - args->ray->y;
			y = img->y + 12 - args->ray->x;
			if (args->map[img->y][img->x] == '1')
				ft_put_square(img, x, y, 0xFFFFFF);
			else if (args->map[img->y][img->x] != '1' && \
					args->map[img->y][img->x] != '2')
				ft_put_square(img, x, y, args->floor_color);
		}	
	}
	args->mlx->img.y = args->ray->x - 1;
	args->mlx->img.x = args->ray->y - 1;

	printf("posx= %f\n", args->ray->x);


	ft_put_player(img, 0xFFFF00);
    return (0);
}

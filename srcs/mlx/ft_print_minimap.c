/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_minimap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:12:00 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/04/01 12:20:10 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_print_minimap(t_args *args, t_img *img)
{
	int	x;
	int	y;

	img->y = -1;
	while (args->map[++img->y])
	{
		img->x = -1;
		while (args->map[img->y][++img->x])
		{
			x = img->x + 12 - args->ray->pos_y;
			y = img->y + 12 - args->ray->pos_x;
			if (args->map[img->y][img->x] == '1')
				ft_put_square(img, x, y, 0xFFFFFF);
			else if (args->map[img->y][img->x] != '1' && \
					args->map[img->y][img->x] != '2')
				ft_put_square(img, x, y, args->floor_color);
		}	
	}
	args->mlx->img.y = args->ray->pos_x - 1;
	args->mlx->img.x = args->ray->pos_y - 1;
	ft_put_player(img, 0xFFFF00);
	return (0);
}

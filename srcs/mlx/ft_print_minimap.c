	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_minimap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:12:00 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/04/03 16:04:09 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_add_background(t_args *args)
{
	int	x;
	int	y;

	x = 0;
	while (x < 27)
	{
		y = 0;
		while (y < 27)
			ft_put_square(args, x, y++, 0);
		x++;
	}
}

int	ft_print_minimap(t_args *args, t_img *img)
{
	int	x;
	int	y;

	ft_add_background(args);
	img->y = -1;
	while (args->map[++img->y])
	{
		img->x = -1;
		while (args->map[img->y][++img->x])
		{
			x = img->x + P_OFFSET + 2 - args->ray->pos_y;
			y = img->y + P_OFFSET + 2 - args->ray->pos_x;
			if (args->map[img->y][img->x] == '1')
				ft_put_square(args, x, y, args->floor_color);
			else if (args->map[img->y][img->x] != '1' && \
					args->map[img->y][img->x] != '2')
				ft_put_square(args, x, y, 0xFFFFFF);
		}	
	}
	args->mlx->img.y = args->ray->pos_x - 1;
	args->mlx->img.x = args->ray->pos_y - 1;
	ft_put_player(img, 0x00002A);
	return (0);
}

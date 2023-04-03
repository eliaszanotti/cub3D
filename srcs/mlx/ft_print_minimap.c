/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_minimap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:12:00 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/04/03 15:29:49 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_add_background(t_img *img)
{
	int	x;
	int	y;

	x = 0;
	while (x < 25)
	{
		y = 0;
		while (y < 25)
			ft_put_square(img, x, y++, 0);
		x++;
	}
}

int	ft_print_minimap(t_args *args, t_img *img)
{
	int	x;
	int	y;

	ft_add_background(img);
	img->y = -1;
	while (args->map[++img->y])
	{
		img->x = -1;
		while (args->map[img->y][++img->x])
		{
			x = img->x + 13 - args->ray->pos_y;
			y = img->y + 13 - args->ray->pos_x;
			if (args->map[img->y][img->x] == '1')
				ft_put_square(img, x, y, args->floor_color);
			else if (args->map[img->y][img->x] != '1' && \
					args->map[img->y][img->x] != '2')
				ft_put_square(img, x, y, 0xFFFFFF);
		}	
	}
	args->mlx->img.y = args->ray->pos_x - 1;
	args->mlx->img.x = args->ray->pos_y - 1;
	ft_put_player(img, 0x228B22);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_minimap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:12:00 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/04/04 19:06:16 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_add_background(t_img *img)
{
	int	x;
	int	y;

	x = 0;
	while (x < (P_OFFSET + 10) * 2)
	{
		y = 0;
		while (y < (P_OFFSET + 10) * 2)
			ft_mlx_pixel_put(img, x, y++, 0);
		x++;
	}
}

static double	ft_get_angle(t_args *args)
{
	double	angle;

	if (args->ray->dir_y >= 0)
		angle = acos(args->ray->dir_x);
	else
		angle = (2 * M_PI) - acos(args->ray->dir_x);
	angle = M_PI - angle;
	return (angle);
}

int	ft_print_minimap(t_args *args, t_img *img)
{
	t_point	p;
	double	angle;
	char	c;

	angle = ft_get_angle(args);
	ft_add_background(img);
	img->y = -1;
	while (args->map[++img->y])
	{
		img->x = -1;
		while (args->map[img->y][++img->x])
		{
			p.x = img->x * CUB_SIZE;
			p.y = img->y * CUB_SIZE;
			c = args->map[img->y][img->x];
			if (c == '1')
				ft_put_square(args, p, args->floor_color, angle);
			else if (c != '1' && c != '2')
				ft_put_square(args, p, 0xFFFFFF, angle);
		}	
	}
	args->mlx->img.y = args->ray->pos_x - 1;
	args->mlx->img.x = args->ray->pos_y - 1;
	ft_put_player(img, 0x00002A);
	return (0);
}

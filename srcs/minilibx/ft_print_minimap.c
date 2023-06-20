/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_minimap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:12:00 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/04/25 17:08:03 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_add_background(t_args *args, t_img *img)
{
	int	x;
	int	y;
	int	dx;
	int	dy;

	x = -1;
	while (++x < (P_OFFSET + 10) * 2)
	{
		dx = abs(x - P_OFFSET);
		y = -1;
		while (++y < (P_OFFSET + 10) * 2)
		{
			dy = abs(y - P_OFFSET);
			if (sqrt(dx * dx + dy * dy) < 150 && args->expanded)
				ft_mlx_pixel_put(img, x, y, 0);
			else if (sqrt(dx * dx + dy * dy) < 40 && !args->expanded)
				ft_mlx_pixel_put(img, x, y, 0);
		}
	}
}

static double	ft_get_angle(t_args *args)
{
	double	angle;

	if (args->ray->dir.y >= 0)
		angle = acos(args->ray->dir.x);
	else
		angle = (2 * M_PI) - acos(args->ray->dir.x);
	angle = M_PI - angle;
	return (angle);
}

static void	ft_choose_color(t_args *args, t_point p, t_img *img, double angle)
{
	char	c;

	c = args->map[img->y][img->x];
	if (c == '1')
		ft_put_square(args, p, args->floor_color, angle);
	else if (c == '3' || c == '4')
		ft_put_square(args, p, 0xA9CCE3, angle);
	else if (c != '1' && c != '2')
		ft_put_square(args, p, 0xFFFFFF, angle);
}

int	ft_print_minimap(t_args *args, t_img *img)
{
	t_point	p;
	double	angle;

	angle = ft_get_angle(args);
	ft_add_background(args, img);
	img->y = -1;
	while (args->map[++img->y])
	{
		img->x = -1;
		while (args->map[img->y][++img->x])
		{
			p.x = img->x * CUB_SIZE;
			p.y = img->y * CUB_SIZE;
			ft_choose_color(args, p, img, angle);
		}	
	}
	args->mlx->img.y = args->ray->pos.x - 1;
	args->mlx->img.x = args->ray->pos.y - 1;
	ft_put_player(img, 0x00002A);
	return (0);
}

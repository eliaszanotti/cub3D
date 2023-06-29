/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:11:02 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/06/29 15:40:57 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3D.h"

static int	ft_flash_light(t_args *args, t_img *img, int x, int y)
{
	int		color;
	double	opacity;

	if (args->expanded)
		opacity = 1 - ((double)args->ray->draw_start / (SCREEN_HEIGHT / 2)) \
			+ 0.5;
	else
		opacity = 1 - ((double)args->ray->draw_start / (SCREEN_HEIGHT / 2)) \
			- 0.1;
	if (y >= args->ray->draw_start && y <= args->ray->draw_end)
	{
		args->ray->tex.y = (int)args->ray->tex_pos & 255;
		args->ray->tex_pos += args->ray->step;
		color = ft_get_color(&args->texture[args->ray->side], args->ray->tex.x, \
			args->ray->tex.y);
		ft_mlx_pixel_put(img, x, y, ft_reduce_opacity(color, opacity));
	}
	return (0);
}

static int	ft_draw_ceiling(t_args *args, t_img *img, int x, int y)
{
	double	opacity;

	if (args->expanded)
		opacity = 1 - ((double)y / (SCREEN_HEIGHT / 2)) + 0.6;
	else
		opacity = 1 - ((double)y / (SCREEN_HEIGHT / 2)) - 0.5;
	if (y < args->ray->draw_start)
		ft_mlx_pixel_put(img, x, y, \
			ft_reduce_opacity(args->ceiling_color, opacity));
	return (0);
}

static int	ft_draw_floor(t_args *args, t_img *img, int x, int y)
{
	double	opacity;

	if (args->expanded)
		opacity = ((double)(y - SCREEN_HEIGHT / 2) \
			/ (SCREEN_HEIGHT / 2)) + 0.6;
	else
		opacity = ((double)(y - SCREEN_HEIGHT / 2) \
			/ (SCREEN_HEIGHT / 2)) - 0.5;
	if (y > args->ray->draw_end)
		ft_mlx_pixel_put(img, x, y, \
				ft_reduce_opacity(args->floor_color, opacity));
	return (0);
}

int	ft_draw_line(t_args *args, t_img *img, int x)
{
	int		y;

	y = 0;
	while (y++ <= SCREEN_HEIGHT)
	{
		if (ft_draw_ceiling(args, img, x, y))
			return (1);
		if (ft_flash_light(args, img, x, y))
			return (1);
		if (ft_draw_floor(args, img, x, y))
			return (1);
	}
	return (0);
}

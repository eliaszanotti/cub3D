/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:11:02 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/04/25 18:36:34 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3D.h"

void	ft_flash_light(t_args *a, t_img *img, int x, int y)
{
	int		color;
	double	opacity;

	if (a->expanded)
		opacity = 1 - ((double)a->ray->draw_start / (SCREEN_HEIGHT / 2)) + 0.5;
	else
		opacity = 1 - ((double)a->ray->draw_start / (SCREEN_HEIGHT / 2)) - 0.1;
	if (y >= a->ray->draw_start && y <= a->ray->draw_end)
	{
		a->ray->tex.y = (int)a->ray->tex_pos & 255;
		a->ray->tex_pos += a->ray->step;
		color = ft_get_color(&a->texture[a->ray->side], a->ray->tex.x, \
			a->ray->tex.y);
		ft_mlx_pixel_put(img, x, y, ft_reduce_opacity(color, opacity));
	}
}

void	ft_draw_line(t_args *a, t_img *img, int x)
{
	int		y;
	double	opacity;

	y = 0;
	while (y++ <= SCREEN_HEIGHT)
	{
		if (a->expanded)
			opacity = 1 - ((double)y / (SCREEN_HEIGHT / 2)) + 0.6;
		else
			opacity = 1 - ((double)y / (SCREEN_HEIGHT / 2)) - 0.5;
		if (y < a->ray->draw_start)
			ft_mlx_pixel_put(img, x, y, \
				ft_reduce_opacity(a->ceiling_color, opacity));
		ft_flash_light(a, img, x, y);
		if (a->expanded)
			opacity = ((double)(y - SCREEN_HEIGHT / 2) \
				/ (SCREEN_HEIGHT / 2)) + 0.6;
		else
			opacity = ((double)(y - SCREEN_HEIGHT / 2) \
				/ (SCREEN_HEIGHT / 2)) - 0.5;
		if (y > a->ray->draw_end)
			ft_mlx_pixel_put(img, x, y, \
				ft_reduce_opacity(a->floor_color, opacity));
	}
}

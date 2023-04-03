/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:11:02 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/04/03 14:46:53 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3D.h"

void	ft_flash_light(t_args *a, t_img *img, int x, int y)
{
	int	color;
	int	dx;
	int	dy;
	int	hyp;

	dx = abs(x - SCREEN_WIDTH / 2);
	if (y >= a->ray->draw_start && y <= a->ray->draw_end)
	{
		dy = abs(y - SCREEN_HEIGHT / 2);
		hyp = sqrt(dx * dx + dy * dy);
		a->ray->tex_y = (int)a->ray->tex_pos & 63;
		a->ray->tex_pos += a->ray->step;
		color = ft_get_color(&a->texture[a->ray->side], a->ray->tex_x, \
		a->ray->tex_y);
		if (hyp * (a->ray->draw_end - a->ray->draw_start) / SCREEN_HEIGHT > 160)
			ft_mlx_pixel_put(img, x, y, (color >> 4) & 986895);
		else if (hyp * (a->ray->draw_end - a->ray->draw_start) / \
			SCREEN_HEIGHT > 50)
			ft_mlx_pixel_put(img, x, y, (color >> 1) & 8355711);
		ft_mlx_pixel_put(img, x, y, color);
	}
}

void	ft_draw_line(t_args *a, t_img *img, int x)
{
	int	y;

	y = 0;
	while (y++ <= SCREEN_HEIGHT)
	{
		if (y < a->ray->draw_start)
			ft_mlx_pixel_put(img, x, y, a->ceiling_color);
		ft_flash_light(a, img, x, y);
		if (y > a->ray->draw_end)
			ft_mlx_pixel_put(img, x, y, a->floor_color);
	}
}

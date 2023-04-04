/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:47:32 by elias             #+#    #+#             */
/*   Updated: 2023/04/04 18:50:00 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_print_border(t_img *img, int x, int y, int color)
{
	ft_mlx_pixel_put(img, x, y, color);
	ft_mlx_pixel_put(img, x + 1, y + 1, color);
	ft_mlx_pixel_put(img, x - 1, y - 1, color);
	ft_mlx_pixel_put(img, x + 1, y - 1, color);
	ft_mlx_pixel_put(img, x - 1, y + 1, color);
	ft_mlx_pixel_put(img, x, y + 1, color);
	ft_mlx_pixel_put(img, x, y - 1, color);
	ft_mlx_pixel_put(img, x + 1, y, color);
	ft_mlx_pixel_put(img, x + 1, y, color);
}

void	ft_print_line(t_img *img, t_point p1, t_point p2, int color)
{
	double	delta_x;
	double	delta_y;
	int		pixels;
	double	pixel_x;
	double	pixel_y;

	delta_x = p2.x - p1.x;
	delta_y = p2.y - p1.y;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = p1.x;
	pixel_y = p1.y;
	while (pixels--)
	{
		ft_print_border(img, pixel_x, pixel_y, color);
		pixel_x += delta_x;
		pixel_y += delta_y;
	}
}

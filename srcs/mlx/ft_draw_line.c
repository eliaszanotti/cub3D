/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:11:02 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/04/03 08:56:28 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3D.h"

void	ft_draw_line(t_args *a, t_img *img, int x)
{
	int	dx;
	int	dy;
	int	hyp;
	int	color;
	int	tex_y;
	int	y;

	dx = abs(x - SCREEN_WIDTH / 2);
	y = 0;
	while (y++ <= SCREEN_HEIGHT)
	{
		dy = abs(y - SCREEN_HEIGHT / 2);
		hyp = sqrt(dx * dx + dy * dy);
		if (y < a->ray->draw_start)
			my_mlx_pixel_put(img, x, y, a->ceiling_color);
		else if (y >= a->ray->draw_start && y <= a->ray->draw_end)
		{
			tex_y = (int)a->ray->tex_pos & 63;
			a->ray->tex_pos += a->ray->step;
			color = ft_get_color(&a->texture[a->ray->side], a->ray->tex_x, tex_y);
			if (hyp * (a->ray->draw_end - a->ray->draw_start) / SCREEN_HEIGHT > 160)
			{
				if (a->ray->angle > tan(dx / (SCREEN_HEIGHT - 100 - dy)))
					a->ray->angle = tan(dx / (SCREEN_HEIGHT - 100 - dy));
				my_mlx_pixel_put(img, x, y, (color >> 4) & 986895);
			}
			else if (hyp * (a->ray->draw_end - a->ray->draw_start) / SCREEN_HEIGHT > 50)
				my_mlx_pixel_put(img, x, y, (color >> 1) & 8355711);
			else
				my_mlx_pixel_put(img, x, y, color);
		}
		else if (tan(dx / (SCREEN_HEIGHT - 100 - dy)) < a->ray->angle)
			my_mlx_pixel_put(img, x, y, a->floor_color);
	}
}



// void	ft_draw_line(t_args *a, t_img *img, int x)
// {
// 	int	dx;
// 	int	dy;
// 	int	hyp;
// 	int	color;
// 	int	tex_y;

// 	dx = abs(x - SCREEN_WIDTH / 2);
// 	while (a->ray->draw_start++ < a->ray->draw_end)
// 	{
// 		tex_y = (int)a->ray->tex_pos & 63;
// 		a->ray->tex_pos += a->ray->step;
// 		color = ft_get_color(&a->texture[a->ray->side], a->ray->tex_x, tex_y);
// 		dy = abs(a->ray->draw_start - SCREEN_HEIGHT / 2);
// 		hyp = sqrt(dx * dx + dy * dy);
// 		if (hyp > 200)
// 			my_mlx_pixel_put(img, x, a->ray->draw_start, (color >> 4) & 986895);
// 		// else if (hyp > 300)
// 		// 	my_mlx_pixel_put(img, x, a->ray->draw_start, (color >> 3) & 2039583);
// 		// else if (hyp > 200)
// 		// 	my_mlx_pixel_put(img, x, a->ray->draw_start, (color >> 2) & 4144959);
// 		else if (hyp > 100)
// 			my_mlx_pixel_put(img, x, a->ray->draw_start, (color >> 1) & 8355711);
// 		else
// 			my_mlx_pixel_put(img, x, a->ray->draw_start, color);
// 	}
// }
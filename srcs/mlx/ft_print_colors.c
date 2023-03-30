/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:39:34 by elias             #+#    #+#             */
/*   Updated: 2023/03/30 18:07:04 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_print_colors(t_args *args)
{
	t_img	*img;
	int		i;
	int		j;

	i = -1;
	img = &args->mlx->img;
	while (++i < SCREEN_HEIGHT)
	{
		j = -1;
		while (++j < SCREEN_WIDTH)
		{
			if (i > SCREEN_HEIGHT / 2)
				my_mlx_pixel_put(img, j, i, args->floor_color);
			else
				my_mlx_pixel_put(img, j, i, args->ceiling_color);
		}
	}
}

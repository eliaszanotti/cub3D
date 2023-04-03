/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:11:33 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/03/31 19:11:38 by thibaultgir      ###   ########.fr       */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cross.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:39:51 by elias             #+#    #+#             */
/*   Updated: 2023/03/30 17:43:28 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_print_cross(t_img *img)
{
	int	i;
	int	j;

	i = ((SCREEN_HEIGHT / 2) - 1);
	while (i++ < ((SCREEN_HEIGHT / 2) + 1))
	{
		j = ((SCREEN_WIDTH / 2) - 10);
		while (j++ < ((SCREEN_WIDTH / 2) + 10))
			my_mlx_pixel_put(img, j, i, 0xFFFFFF);
	}
	i = ((SCREEN_HEIGHT / 2) - 10);
	while (i++ < ((SCREEN_HEIGHT / 2) + 10))
	{
		j = ((SCREEN_WIDTH / 2) - 1);
		while (j++ < ((SCREEN_WIDTH / 2) + 1))
			my_mlx_pixel_put(img, j, i, 0xFFFFFF);
	}
}

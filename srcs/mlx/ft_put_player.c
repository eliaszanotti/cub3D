/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:12:26 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/04/04 18:57:24 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_put_player(t_img *img, int color)
{
	int	x;
	int	y;

	x = P_OFFSET - 2;
	while (x <= P_OFFSET + 2)
	{
		y = P_OFFSET - 2;
		while (y <= P_OFFSET + 2)
			ft_mlx_pixel_put(img, x, y++, color);
		x++;
	}
}

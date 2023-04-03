/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:12:26 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/03/31 19:12:29 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_put_player(t_img *img, int color)
{
	int	i;
	int	j;

	i = CUB_SIZE / 4 - 1;
	while (++i < CUB_SIZE / 2 + CUB_SIZE / 4)
	{
		j = CUB_SIZE / 4 - 1;
		while (++j < CUB_SIZE / 2 + CUB_SIZE / 4)
			my_mlx_pixel_put(img, (10 * CUB_SIZE + CUB_SIZE) + i, \
				(10 * CUB_SIZE + CUB_SIZE) + j, color);
	}	
}

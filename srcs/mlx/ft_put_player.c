/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:12:26 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/04/03 16:03:54 by elias            ###   ########.fr       */
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
			ft_mlx_pixel_put(img, (P_OFFSET * CUB_SIZE + CUB_SIZE) + i, \
				(P_OFFSET * CUB_SIZE + CUB_SIZE) + j, color);
	}	
}

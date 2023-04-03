/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cross.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:11:49 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/03/31 19:11:52 by thibaultgir      ###   ########.fr       */
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

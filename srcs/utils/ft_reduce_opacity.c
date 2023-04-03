/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reduce_opacity.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:50:24 by elias             #+#    #+#             */
/*   Updated: 2023/04/03 17:35:26 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_reduce_opacity(int color, double opacity)
{
	double	red;
	double	green;
	double	blue;
	int		total;

	if (opacity < 0)
		opacity = 0;
	if (opacity > 1)
		opacity = 1;
	red = (double)((color & 0xFF0000) >> 16) * opacity;
	green = (double)((color & 0x00FF00) >> 8) * opacity;
	blue = (double)(color & 0x0000FF) * opacity;
	total = blue + ((int)green << 8) + ((int)red << 16);
	return (total);
}

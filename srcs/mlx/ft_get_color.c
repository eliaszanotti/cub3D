/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:11:12 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/04/24 14:17:57 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3D.h"

unsigned int	ft_get_color(t_img *data, int x, int y)
{
	int		color;
	char	*dst;

	if (x < 0)
		x *= -1;
	if (y < 0)
		y *= -1;
	dst = data->addr + (y % 16 * data->line_length + x % 16 * \
		(data->bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

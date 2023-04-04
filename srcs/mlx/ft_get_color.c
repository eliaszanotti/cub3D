/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:11:12 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/04/04 11:34:55 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3D.h"

unsigned int	ft_get_color(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y % IMG_SIZE * img->line_length + x % IMG_SIZE * \
			(img->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

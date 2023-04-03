/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:11:12 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/04/01 12:16:46 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3D.h"

unsigned int	ft_get_color(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y % 64 * img->line_length + x % 64 * \
			(img->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 21:31:52 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/04/01 12:19:50 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3D.h"

t_img	ft_create_img(t_args *args, char *path)
{
	int		height;
	int		width;
	t_img	img;

	img.img = mlx_xpm_file_to_image(args->mlx->mlx, path, &width, &height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	return (img);
}

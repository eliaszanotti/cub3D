/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 21:31:52 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/06/30 12:47:42 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3D.h"

int	ft_create_img(t_args *args, char *path, int side)
{
	int		height;
	int		width;
	t_img	img;

	img.img = mlx_xpm_file_to_image(args->mlx->mlx, path, &width, &height);
	if (!img.img)
	{
		printf("Can't open texture : "\
			"%d\n0 : NO\n1 : SO\n2 : WE\n3 : EA\n", side);
		mlx_destroy_image(args->mlx->mlx, args->mlx->img.img);
		return (ft_error(9));
	}
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
		&img.line_length, &img.endian);
	args->texture[side] = img;
	return (0);
}

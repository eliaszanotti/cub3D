/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_xpm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:51:09 by elias             #+#    #+#             */
/*   Updated: 2023/06/29 14:51:32 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_open_xpm(t_args *args, char *path, int i)
{
	int		height;
	int		width;
	t_img	img;

	img.img = mlx_xpm_file_to_image(args->mlx->mlx, path, &width, &height);
	if (!img.img)
	{
		printf("Can't open texture : ");
		printf("%d\n0 : NO\n1 : SO\n2 : WE\n3 : EA\n", i);
		return (ft_error(9));
	}
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
		&img.line_length, &img.endian);
	return (0);
}

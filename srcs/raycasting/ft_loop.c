/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:58:14 by elias             #+#    #+#             */
/*   Updated: 2023/04/03 13:04:31 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_loop(t_args *args)
{
	t_mlx	*mlx;
	int		x;

	mlx = args->mlx;
	mlx->img.img = mlx_new_image(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel, \
		&mlx->img.line_length, &mlx->img.endian);
	x = 0;
	while (x++ < SCREEN_WIDTH)
	{
		ft_init_values(args, x);
		ft_calcul_side_dist(args);
		ft_throw_ray(args);
		ft_calcul(args);
		ft_draw_line(args, &args->mlx->img, x);
	}
	ft_print_minimap(args, &mlx->img);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, \
		0, 0);
	ft_print_cross(&mlx->img);
	return (0);
}

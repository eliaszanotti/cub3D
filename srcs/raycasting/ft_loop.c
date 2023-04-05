/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:58:14 by elias             #+#    #+#             */
/*   Updated: 2023/04/05 13:24:00 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_loop(t_args *args)
{
	t_mlx	*mlx;
	int		x;

	mlx = args->mlx;
	ft_move(args);
	x = 0;
	while (x++ < SCREEN_WIDTH)
	{
		if (ft_init_values(args, x))
			return (1);
		if (ft_calculate_side_dist(args))
			return (1);
		if (ft_throw_ray(args))
			return (1);
		if (ft_calculate_positions(args))
			return (1);
		ft_draw_line(args, &args->mlx->img, x);
	}
	ft_print_minimap(args, &mlx->img);
	ft_print_cross(&mlx->img);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
	return (0);
}

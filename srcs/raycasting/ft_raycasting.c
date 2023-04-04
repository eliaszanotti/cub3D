/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:46:11 by elias             #+#    #+#             */
/*   Updated: 2023/04/04 14:53:37 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_raycasting(t_args *args)
{
	t_mlx	*mlx;
	
	mlx = args->mlx;
	mlx->img.img = mlx_new_image(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	 mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel, \
	 	&mlx->img.line_length, &mlx->img.endian);
	if (ft_init_ray(args))
		return (ft_free_mlx(args), ft_free_str(args->map), \
			ft_free_struct(args), 1);
	if (ft_init_textures(args))
	{
		//mlx_destroy_image(&args->texture[0], args->texture[0].img);
		return (ft_free_mlx(args), ft_free_str(args->map), \
			ft_free_struct(args), 1);
	}
	mlx_hook(args->mlx->win, 2, 1L << 0, hook_keypress, args);
	mlx_hook(args->mlx->win, 3, 1L << 1, hook_keyrelease, args);
	mlx_hook(args->mlx->win, 17, 0, ft_exit, args);
	mlx_loop_hook(args->mlx->mlx, ft_loop, args);
	mlx_loop(args->mlx->mlx);
	return (0);
}

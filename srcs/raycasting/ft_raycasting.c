/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:46:11 by elias             #+#    #+#             */
/*   Updated: 2023/08/29 16:32:56 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_init_images(t_args *args)
{
	t_mlx	*mlx;

	mlx = args->mlx;
	mlx->img.img = mlx_new_image(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel, \
		&mlx->img.line_length, &mlx->img.endian);
	args->mlx = mlx;
	return (0);
}

static int	ft_mlx_hook_loop(t_args *args)
{
	mlx_hook(args->mlx->win, 2, 1L << 0, ft_hook_keypress, args);
	mlx_hook(args->mlx->win, 3, 1L << 1, ft_hook_keyrelease, args);
	// mlx_hook(args->mlx->win, 6, 1L << 6, ft_mouse_hook, args);
	mlx_hook(args->mlx->win, 17, 0, ft_exit, args);
	mlx_loop_hook(args->mlx->mlx, ft_loop, args);
	mlx_loop(args->mlx->mlx);
	return (0);
}

int	ft_raycasting(t_args *args)
{
	if (ft_init_images(args))
		return (1);
	if (ft_init_ray(args))
		return (ft_free_mlx(args), ft_free_str(args->map), \
			ft_free_struct(args), 1);
	if (ft_init_textures(args))
		return (ft_free_mlx(args), ft_free_str(args->map), \
			ft_free_struct(args), 1);
	if (ft_mlx_hook_loop(args))
		return (1);
	return (0);
}

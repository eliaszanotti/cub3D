/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:26:46 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/03/28 16:48:20 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int ft_create_window(t_args *args)
{
    t_mlx   *mlx;
    mlx = args->mlx;

    mlx->mlx = mlx_init();
    mlx->win = mlx_new_window(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Raycasting");
    mlx->img = mlx_new_image(mlx, 1920, 1080);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, &mlx->line_length, &mlx->endian);
	mlx_pixel_put(&mlx->mlx, &mlx->win, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx->mlx, mlx->img, 0, 0);
	mlx_loop(mlx);
    return (0);
}
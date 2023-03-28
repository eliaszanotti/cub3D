/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:26:46 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/03/28 18:16:54 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int ft_create_window(t_args *args)
{
	(void)args;
    t_mlx   mlx;

    mlx.mlx = mlx_init();
    mlx.win = mlx_new_window(mlx.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D");
    //mlx->img = mlx_new_image(mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	//mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, &mlx->line_length, &mlx->endian);
	//mlx_pixel_put(&mlx->mlx, &mlx->win, 5, 5, 0x00FF0000);
	//mlx_put_image_to_window(mlx, mlx->mlx, mlx->img, 0, 0);
	mlx_loop(mlx.mlx);
    return (0);
}

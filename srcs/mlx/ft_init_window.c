/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 21:11:57 by elias             #+#    #+#             */
/*   Updated: 2023/03/30 11:04:04 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_init_window(t_args *args)
{
    t_mlx   *mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (ft_error(99));
    mlx->mlx = mlx_init();
    mlx->win = mlx_new_window(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D");
	args->mlx = mlx;
	args->x_player = 12 * CUB_SIZE;
	args->y_player = 22 * CUB_SIZE;
	return (0);
}
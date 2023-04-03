/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:11:24 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/04/03 11:55:24 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_init_window(t_args *args)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (ft_error(99));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D");
	args->mlx = mlx;
	args->x_player = 12 * CUB_SIZE;
	args->y_player = 22 * CUB_SIZE; //TODO
	return (0);
}

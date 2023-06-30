/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:14:16 by elias             #+#    #+#             */
/*   Updated: 2023/06/30 12:14:40 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_free_mlx(t_args *args)
{
	mlx_clear_window(args->mlx->mlx, args->mlx->win);
	mlx_destroy_window(args->mlx->mlx, args->mlx->win);
	free(args->mlx->mlx);
	free(args->mlx);
	free(args->ray);
}

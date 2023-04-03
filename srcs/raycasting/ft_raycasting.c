/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:46:11 by elias             #+#    #+#             */
/*   Updated: 2023/04/03 14:45:38 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_raycasting(t_args *args)
{
	if (ft_init_ray(args))
		return (1);
	if (ft_init_textures(args))
		return (1);
	if (ft_loop(args))
		return (1);
	mlx_hook(args->mlx->win, 2, 1L << 0, hook_keypress, args);
	mlx_hook(args->mlx->win, 3, 1L << 1, hook_keyrelease, args);
	mlx_loop(args->mlx->mlx);
	return (0);
}

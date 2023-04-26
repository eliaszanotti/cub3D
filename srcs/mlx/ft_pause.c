/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pause.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:58:56 by elias             #+#    #+#             */
/*   Updated: 2023/04/26 17:58:57 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_pause(t_args *args)
{
	t_mlx	*mlx;

	mlx = args->mlx;
	if (!args->is_paused)
	{
		mlx_mouse_hide(mlx->mlx, mlx->win);
		mlx_mouse_move(mlx->mlx, mlx->win, (int)(SCREEN_WIDTH / 2), \
			(int)(SCREEN_HEIGHT / 2));
	}
	else
		mlx_mouse_show(mlx->mlx, mlx->win);
	return (0);
}

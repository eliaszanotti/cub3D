/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:49:12 by elias             #+#    #+#             */
/*   Updated: 2023/04/06 14:23:01 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_exit(t_args *args)
{
	mlx_destroy_image(args->mlx->mlx, args->mlx->img.img);
	mlx_destroy_image(args->mlx->mlx, args->texture[0].img);
	mlx_destroy_image(args->mlx->mlx, args->texture[1].img);
	mlx_destroy_image(args->mlx->mlx, args->texture[2].img);
	mlx_destroy_image(args->mlx->mlx, args->texture[3].img);
	ft_free_struct(args);
	ft_free_str(args->map);
	ft_free_mlx(args);
	exit(0);
	return (0);
}

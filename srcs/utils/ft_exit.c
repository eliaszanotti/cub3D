/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:49:12 by elias             #+#    #+#             */
/*   Updated: 2023/04/04 14:32:25 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_exit(t_args *args)
{
	mlx_destroy_image(args->mlx->mlx, args->mlx->img.img);
	ft_free_struct(args);
	ft_free_str(args->map);
	ft_free_mlx(args);
	exit(0);
	return (0);
}

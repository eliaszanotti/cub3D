/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:49:12 by elias             #+#    #+#             */
/*   Updated: 2023/08/29 15:34:53 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_exit(t_args *args)
{
	int	i;

	i = -1;
	while (++i <= 6)
	{
		if (args->texture[i].img)
			mlx_destroy_image(args->mlx->mlx, args->texture[i].img);
	}
	mlx_destroy_image(args->mlx->mlx, args->mlx->img.img);
	ft_free_struct(args);
	ft_free_str(args->map);
	ft_free_mlx(args);
	exit(0);
	return (0);
}

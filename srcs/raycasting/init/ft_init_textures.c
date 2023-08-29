/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:58:57 by elias             #+#    #+#             */
/*   Updated: 2023/08/29 17:43:28 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_free_tab(t_args *args, int i)
{
	while (i >= 0)
	{
		mlx_destroy_image(args->mlx->mlx, args->texture[i].img);
		i--;
	}
}

int	ft_init_textures(t_args *args)
{
	if (ft_create_img(args, args->north_path, NORTH))
		return (1);
	if (ft_create_img(args, args->south_path, SOUTH))
		return (ft_free_tab(args, 0), 1);
	if (ft_create_img(args, args->west_path, WEST))
		return (ft_free_tab(args, 1), 1);
	if (ft_create_img(args, args->east_path, EAST))
		return (ft_free_tab(args, 2), 1);
	if (ft_create_img(args, "textures/door.xpm", 4))
		return (ft_free_tab(args, 3), 1);
	if (ft_create_img(args, "textures/scream.xpm", 5))
		return (ft_free_tab(args, 4), 1);
	if (ft_create_img(args, "textures/end.xpm", 6))
		return (ft_free_tab(args, 5), 1);
	return (0);
}

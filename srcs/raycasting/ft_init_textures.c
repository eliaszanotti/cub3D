/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:58:57 by elias             #+#    #+#             */
/*   Updated: 2023/04/03 12:46:43 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_init_textures(t_args *args)
{
	if (ft_create_img(args, args->north_path, NORTH))
		return (1);
	if (ft_create_img(args, args->south_path, SOUTH))
		return (1);
	if (ft_create_img(args, args->west_path, WEST))
		return (1);
	if (ft_create_img(args, args->east_path, EAST))
		return (1);
	return (0);
}

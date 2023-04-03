/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:36:06 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/04/03 10:36:20 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3D.h"

int	ft_load_texture(t_args *args)
{
	args->texture = malloc(sizeof(t_img) * 4);
	args->texture[NORTH] = ft_create_img(args, "textures/CRATE_1I.xpm");
	args->texture[SOUTH] = ft_create_img(args, "textures/CRATE_1N.xpm");
	args->texture[WEST] = ft_create_img(args, "textures/FLOOR_1B.xpm");
	args->texture[EAST] = ft_create_img(args, "textures/TECH_4C.xpm");
	return (0);
}

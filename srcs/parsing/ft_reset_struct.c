/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:56:24 by ezanotti          #+#    #+#             */
/*   Updated: 2023/04/03 15:54:55 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_reset_struct(t_args *args)
{
	args->north_path = NULL;
	args->south_path = NULL;
	args->west_path = NULL;
	args->east_path = NULL;
	args->floor = NULL;
	args->ceiling = NULL;
	args->map_list = NULL;
	args->expanded = 1;
	return (0);
}

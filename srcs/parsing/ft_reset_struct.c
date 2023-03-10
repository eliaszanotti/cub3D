/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:56:24 by ezanotti          #+#    #+#             */
/*   Updated: 2023/03/10 17:57:30 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_reset_struct(t_args *args)
{
	args->north = NULL;
	args->south = NULL;
	args->west = NULL;
	args->east = NULL;
	args->floor = NULL;
	args->ceiling = NULL;
	return (0);
}

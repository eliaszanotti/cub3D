/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:04:19 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/03/31 13:47:22 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_get_dir(t_args *args, char c)
{
	if (c == 'N')
	{
		args->ray->dirX = -1;
		args->ray->dirY = 0;
		args->ray->planeX = 0;
		args->ray->planeY = 0.66;
	}
	if (c == 'S')
	{
		args->ray->dirX = 1;
		args->ray->dirY = 0;
		args->ray->planeX = 0;
		args->ray->planeY = -0.66;
	}
	if (c == 'E')
	{
		args->ray->dirX = 0;
		args->ray->dirY = 1;
		args->ray->planeX = 0.66;
		args->ray->planeY = 0;
	}
	if (c == 'W')
	{
		args->ray->dirX = 0;
		args->ray->dirY = -1;
		args->ray->planeX = -0.66;
		args->ray->planeY = 0;
	}
}

int	ft_get_start(t_args *args)
{
	int	i;
	int	j;

	i = -1;
	args->ray = malloc(sizeof(t_ray));
	while(args->map[++i])
	{
		j = -1;
		while(args->map[i][++j])
		{
			if(ft_isalpha(args->map[i][j]))
			{
				ft_get_dir(args, args->map[i][j]);
				args->ray->x = i + 0.5;
				args->ray->y = j + 0.5;
			}
		}
	}
	return (0);
}

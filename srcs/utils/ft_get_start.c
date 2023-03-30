/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:04:19 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/03/30 12:05:25 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_get_dir(t_args *args, char c)
{
	if (c == 'N')
	{
		args->ray->dirX = 1;
		args->ray->dirY = 0;
	}
	if (c == 'S')
	{
		args->ray->dirX = 1;
		args->ray->dirY = 0;
	}
	if (c == 'E')
	{
		args->ray->dirX = -1;
		args->ray->dirY = 1;
	}
	if (c == 'W')
	{
		args->ray->dirX = -1;
		args->ray->dirY = -1;
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
				args->ray->posX = i;
				args->ray->posY = j;
			}
		}
	}
	return (0);
}
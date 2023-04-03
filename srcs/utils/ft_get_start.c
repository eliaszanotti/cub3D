/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:28:42 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/04/03 10:33:02 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_give_dir(t_args *args, double dir_x, double dir_y)
{
	args->ray->dir_x = dir_x;
	args->ray->dir_y = dir_y;
}

void	ft_give_plane(t_args *args, double plane_x, double plane_y)
{
	args->ray->plane_x = plane_x;
	args->ray->plane_y = plane_y;
}

void	ft_get_dir(t_args *args, char c)
{
	if (c == 'N')
	{
		ft_give_dir(args, -1, 0);
		ft_give_plane(args, 0, 0.66);
	}
	if (c == 'S')
	{
		ft_give_dir(args, 1, 0);
		ft_give_plane(args, 0, -0.66);
	}
	if (c == 'E')
	{
		ft_give_dir(args, 0, 1);
		ft_give_plane(args, 0.66, 0);
	}
	if (c == 'W')
	{
		ft_give_dir(args, 0, -1);
		ft_give_plane(args, -0.66, 0);
	}
}

int	ft_get_start(t_args *args)
{
	int	i;
	int	j;

	i = -1;
	args->ray = malloc(sizeof(t_ray));
	while (args->map[++i])
	{
		j = -1;
		while (args->map[i][++j])
		{
			if (ft_isalpha(args->map[i][j]))
			{
				ft_get_dir(args, args->map[i][j]);
				args->ray->pos_x = i + 0.5;
				args->ray->pos_y = j + 0.5;
			}
		}
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:12:38 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/04/12 15:13:50 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static t_point	ft_rotate_point(t_point p, double angle)
{
	t_point	new_point;
	int		xm;
	int		ym;

	xm = p.x - P_OFFSET;
	ym = p.y - P_OFFSET;
	new_point.x = xm * cos(angle) + ym * sin(angle) + P_OFFSET;
	new_point.y = -xm * sin(angle) + ym * cos(angle) + P_OFFSET;
	return (new_point);
}

void	ft_put_square(t_args *args, t_point p, int color, double angle)
{
	int		i;
	t_point	p1;
	t_point	p2;

	if (p.x < 0 || p.y < 0)
		return ;
	if (args->expanded == 0)
		color = ft_reduce_opacity(color, 0.3);
	i = -1;
	while (++i < CUB_SIZE)
	{
		p1.x = P_OFFSET + p.x + i - args->ray->pos.y * CUB_SIZE;
		p1.y = P_OFFSET + p.y - args->ray->pos.x * CUB_SIZE;
		p2.x = P_OFFSET + p.x + i - args->ray->pos.y * CUB_SIZE;
		p2.y = P_OFFSET + p.y + CUB_SIZE - args->ray->pos.x * CUB_SIZE;
		ft_print_line(&args->mlx->img, ft_rotate_point(p1, angle), \
			ft_rotate_point(p2, angle), color);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:58:51 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/08/29 14:25:28 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_close_doors(t_args *args)
{
	int		i;
	int		j;

	i = -1;
	while (args->map[++i])
	{
		j = -1;
		while (args->map[i][++j])
		{
			if (args->map[i][j] == '4' && ((int)args->ray->pos.y != j || \
				(int)args->ray->pos.x != i))
				args->map[i][j] = '3';
		}
	}
	args->door_delay = 0;
	return (0);
}

static void	ft_print_square(t_img *img, int x, int y)
{
	int	i;
	int	j;

	i = x - 1;
	while (++i < x + 20)
	{
		j = y - 1;
		while (++j < y + 20)
			ft_mlx_pixel_put(img, i, j, 0xFCA510);
	}
}

int	ft_print_flashlight(t_args *args, t_img *img)
{
	if (args->flash_timer <= 0)
		args->expanded = 0;
	if (args->flash_timer > 0)
		ft_print_square(img, SCREEN_WIDTH - 165, 20);
	if (args->flash_timer > 200)
		ft_print_square(img, SCREEN_WIDTH - 140, 20);
	if (args->flash_timer > 400)
		ft_print_square(img, SCREEN_WIDTH - 115, 20);
	if (args->flash_timer > 600)
		ft_print_square(img, SCREEN_WIDTH - 90, 20);
	if (args->flash_timer > 800)
		ft_print_square(img, SCREEN_WIDTH - 65, 20);
	if (args->flash_timer > 990)
		ft_print_square(img, SCREEN_WIDTH - 40, 20);
	return (0);
}

int	ft_check_screamer(t_args *args)
{
	t_point	pos;

	pos.x = args->ray->pos.x;
	pos.y = args->ray->pos.y;
	if (args->map[pos.x][pos.y] == '5')
		args->screamer = 1;
	else
		args->screamer = 0;
	return (0);
}

int	ft_check_end(t_args *args)
{
	t_point	pos;

	pos.x = args->ray->pos.x;
	pos.y = args->ray->pos.y;
	if (args->map[pos.x][pos.y] == '6')
	{
		args->is_paused = 1;
		args->end = 1;
	}
	else
		args->end = 0;
	return (0);
}

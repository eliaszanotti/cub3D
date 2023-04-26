/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:58:14 by elias             #+#    #+#             */
/*   Updated: 2023/04/26 15:40:31 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_update_animation(t_anim	*anim)
{
	static int	frame;

	if (anim->anime_frame == 0)
		return ;
	if (anim->current_img == 11)
	{
		anim->current_img = 0;
		frame = 0;
	}
	else if (frame >= anim->anime_frame * 2)
	{
		anim->current_img++;
		frame = 0;
	}
	frame += 1;
}

static int	ft_pause(t_args *args)
{
	t_mlx	*mlx;

	mlx = args->mlx;
	if (!args->is_paused)
	{
		mlx_mouse_hide(mlx->mlx, mlx->win);
		mlx_mouse_move(mlx->mlx, mlx->win, (int)(SCREEN_WIDTH / 2), \
			(int)(SCREEN_HEIGHT / 2));
	}
	else
		mlx_mouse_show(mlx->mlx, mlx->win);
	return (0);
}

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

int	ft_loop(t_args *args)
{
	t_mlx	*mlx;
	int		x;

	mlx = args->mlx;
	ft_pause(args);
	ft_move(args);
	x = 0;
	while (x++ < SCREEN_WIDTH)
	{
		if (ft_init_values(args, x))
			return (1);
		if (ft_calculate_side_dist(args))
			return (1);
		if (ft_throw_ray(args))
			return (1);
		if (ft_calculate_positions(args))
			return (1);
		ft_draw_line(args, &args->mlx->img, x);
	}
	if (!args->is_paused)
	{
		ft_print_minimap(args, &mlx->img);
		ft_print_cross(&mlx->img);
	}
	if (args->door_delay++ > 100)
		ft_close_doors(args);
	ft_check_screamer(args);
	if (!args->screamer)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
	else
		mlx_put_image_to_window(mlx->mlx, mlx->win, args->texture[5].img, 0, 0);
	if (args->map[(int)args->ray->pos.x][(int)args->ray->pos.y] == '6')
	{
		mlx_string_put(mlx->mlx, mlx->win, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0x0, "END");
		args->is_paused = 1;
	}
	//ft_update_animation(args->anim);
	//mlx_put_image_to_window(mlx->mlx, mlx->win, args->anim->img[args->anim->current_img].img, 0, 0);
	return (0);
}

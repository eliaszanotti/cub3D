/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:58:14 by elias             #+#    #+#             */
/*   Updated: 2023/04/26 19:27:19 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_close_doors(t_args *args)
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

static int	ft_check_screamer(t_args *args)
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

static int	ft_check_end(t_args *args)
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

static int	ft_print_flashlight(t_args *args, t_img *img) // TODO a virer ailleurs
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

static int	ft_check_state(t_args *args)
{
	t_mlx	*mlx;

	mlx = args->mlx;
	if (args->expanded && args->flash_timer > 0)
		args->flash_timer -= 10;
	else if (!args->expanded && args->flash_timer < 1000)
		args->flash_timer++;
	if (!args->is_paused)
	{
		ft_print_minimap(args, &mlx->img);
		ft_print_cross(&mlx->img);
		ft_print_flashlight(args, &mlx->img);
	}
	if (args->door_delay++ > 100)
		ft_close_doors(args);
	ft_check_screamer(args);
	ft_check_end(args);
	if (args->screamer)
		mlx_put_image_to_window(mlx->mlx, mlx->win, args->texture[5].img, 0, 0);
	else if (args->end)
		mlx_put_image_to_window(mlx->mlx, mlx->win, args->texture[6].img, 0, 0);
	else
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
	return (0);
}	

int	ft_loop(t_args *args)
{
	int		x;

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
	ft_check_state(args);
	return (0);
}

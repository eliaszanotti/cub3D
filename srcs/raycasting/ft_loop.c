/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:58:14 by elias             #+#    #+#             */
/*   Updated: 2023/05/02 12:52:12 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

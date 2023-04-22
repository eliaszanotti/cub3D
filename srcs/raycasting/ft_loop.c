/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:58:14 by elias             #+#    #+#             */
/*   Updated: 2023/04/22 17:11:32 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_update_animation(t_anim	*anim)
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

void	ft_reset_moves(t_args *args)
{
	if (args->turn_left == 1)
		args->turn_left = 0;
	if (args->turn_right == 1)
		args->turn_right = 0;
}

int	ft_loop(t_args *args)
{
	t_mlx	*mlx;
	int		x;

	mlx = args->mlx;
	printf("new win\n");
	mlx_mouse_hide(mlx->mlx, mlx->win);
	mlx_mouse_move(mlx->mlx, mlx->win, (int)(SCREEN_WIDTH / 2), (int)(SCREEN_HEIGHT / 2));
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
	ft_print_minimap(args, &mlx->img);
	ft_print_cross(&mlx->img);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
	ft_update_animation(args->anim);
	mlx_put_image_to_window(mlx->mlx, mlx->win, args->anim->img[args->anim->current_img].img, 0, 0);
	//ft_reset_moves(args);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:58:14 by elias             #+#    #+#             */
/*   Updated: 2023/04/05 15:26:07 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_open_xpm(t_args *args, char *path, int i)
{
	int		height;
	int		width;
	t_img	img;

	img.img = mlx_xpm_file_to_image(args->mlx->mlx, path, &width, &height);
	if (!img.img)
	{
		printf("Can't open texture : \
			%d\n0 : NO\n1 : SO\n2 : WE\n3 : EA\n", i);
		return (ft_error(9));
	}
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
		&img.line_length, &img.endian);
	args->animation[i] = img;
	return (0);
}

int	ft_print_animation(t_args *args)
{
	int i = 0;
	while (i++ < 11)
	{
		mlx_put_image_to_window(args->mlx->mlx, args->mlx->win, args->animation[i].img, 0, 0);
		sleep(2);
	}
	return (0);
}

int	ft_loop(t_args *args)
{
	t_mlx	*mlx;
	// int		x;

	mlx = args->mlx;
	ft_move(args);
	// x = 0;
	// while (x++ < SCREEN_WIDTH)
	// {
	// 	if (ft_init_values(args, x))
	// 		return (1);
	// 	if (ft_calculate_side_dist(args))
	// 		return (1);
	// 	if (ft_throw_ray(args))
	// 		return (1);
	// 	if (ft_calculate_positions(args))
	// 		return (1);
	// 	ft_draw_line(args, &args->mlx->img, x);
	// }
	if (ft_open_xpm(args, "textures/AnyConv.com__00.xpm", 0))
		return (1);
	if (ft_open_xpm(args, "textures/AnyConv.com__10.xpm", 1))
		return (1);
	if (ft_open_xpm(args, "textures/AnyConv.com__20.xpm", 2))
		return (1);
	if (ft_open_xpm(args, "textures/AnyConv.com__30.xpm", 3))
		return (1);
	if (ft_open_xpm(args, "textures/AnyConv.com__40.xpm", 4))
		return (1);
	if (ft_open_xpm(args, "textures/AnyConv.com__50.xpm", 5))
		return (1);
	if (ft_open_xpm(args, "textures/AnyConv.com__60.xpm", 6))
		return (1);
	if (ft_open_xpm(args, "textures/AnyConv.com__70.xpm", 7))
		return (1);
	if (ft_open_xpm(args, "textures/AnyConv.com__80.xpm", 8))
		return (1);
	if (ft_open_xpm(args, "textures/AnyConv.com__90.xpm", 9))
		return (1);
	if (ft_open_xpm(args, "textures/AnyConv.com__100.xpm", 10))
		return (1);
	if (ft_open_xpm(args, "textures/AnyConv.com__110.xpm", 11))
		return (1);
	mlx_loop_hook(mlx->mlx, ft_print_animation, args);
	// ft_print_animation(args);
	// ft_print_minimap(args, &mlx->img);
	// ft_print_cross(&mlx->img);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
	return (0);
}

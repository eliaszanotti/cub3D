/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:46:11 by elias             #+#    #+#             */
/*   Updated: 2023/04/24 17:03:55 by elias            ###   ########.fr       */
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
		printf("Can't open texture : ");
		printf("%d\n0 : NO\n1 : SO\n2 : WE\n3 : EA\n", i);
		return (ft_error(9));
	}
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
		&img.line_length, &img.endian);
	args->anim->img[i] = img;
	return (0);
}

int	ft_raycasting(t_args *args)
{
	t_mlx	*mlx;

	mlx = args->mlx;
	mlx->img.img = mlx_new_image(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel, \
		&mlx->img.line_length, &mlx->img.endian);
	if (ft_init_ray(args))
		return (ft_free_mlx(args), ft_free_str(args->map), \
			ft_free_struct(args), 1);
	if (ft_init_textures(args))
		return (ft_free_mlx(args), ft_free_str(args->map), \
			ft_free_struct(args), 1);
	args->anim = malloc(sizeof(t_anim));
	args->anim->anime_frame = 1;
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
	args->anim->current_img = 0;
	mlx_hook(args->mlx->win, 2, 1L << 0, hook_keypress, args);
	mlx_hook(args->mlx->win, 3, 1L << 1, hook_keyrelease, args);
	mlx_hook(args->mlx->win, 6, 1L << 6, ft_mouse_hook, args);
	mlx_hook(args->mlx->win, 17, 0, ft_exit, args);
	mlx_loop_hook(args->mlx->mlx, ft_loop, args);
	mlx_loop(args->mlx->mlx);
	return (0);
}

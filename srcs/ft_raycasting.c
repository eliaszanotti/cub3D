/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:18:59 by thibaultgir       #+#    #+#             */
/*   Updated: 2023/04/03 10:38:02 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3D.h"

void	ft_loop(t_args *args)
{
	t_mlx	*mlx;
	int		x;

	mlx = args->mlx;
	mlx->img.img = mlx_new_image(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel, \
	&mlx->img.line_length, &mlx->img.endian);
	x = 0;
	while (x++ < SCREEN_WIDTH)
	{
		ft_init_raycasting(args, x);
		ft_calcul_side_dist(args);
		ft_throw_ray(args);
		ft_calcul(args);
		ft_draw_line(args, &args->mlx->img, x);
	}
	ft_print_minimap(args, &mlx->img);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, \
		0, 0);
	ft_print_cross(&mlx->img);
}

int	ft_raycasting(t_args *args)
{
	ft_get_start(args);
	ft_load_texture(args);
	ft_loop(args);
	mlx_hook(args->mlx->win, 2, 1L << 0, hook_keypress, args);
	mlx_hook(args->mlx->win, 3, 1L << 1, hook_keyrelease, args);
	mlx_loop(args->mlx->mlx);
	return (0);
}

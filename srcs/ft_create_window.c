/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:26:46 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/03/29 14:47:24 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	hook_key(int key, t_args *args)
{
	if (key == 65307) //echap 
		exit (0);
	if (key == 65361 && args->map[args->y_player/32][(args->x_player - 32)/32] == '0') //left
		args->x_player -= CUB_SIZE;
	if (key == 65362 && args->map[(args->y_player - 32)/32][args->x_player/32] == '0') //up
		args->y_player -= CUB_SIZE;
	if (key == 65363 && args->map[args->y_player/32][(args->x_player + 32)/32] == '0') //right
		args->x_player += CUB_SIZE;
	if (key == 65364 && args->map[(args->y_player + 32)/32][args->x_player/32] == '0') //down
		args->y_player += CUB_SIZE;
	// mlx_destroy_image(args->mlx.mlx, args->mlx.image.img);
	ft_create_window(args);
	return (0);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;
	if (x < SCREEN_WIDTH || y < SCREEN_HEIGHT)
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

int ft_create_window(t_args *args)
{
	t_mlx *mlx;

	mlx = args->mlx;
	mlx->image.img = mlx_new_image(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx->image.addr = mlx_get_data_addr(mlx->image.img, &mlx->image.bits_per_pixel, &mlx->image.line_length, &mlx->image.endian);
	
	mlx->image.y = -1;
	while (args->map[++mlx->image.y])
	{
		mlx->image.x = -1;
		while (args->map[mlx->image.y][++mlx->image.x])
		{
			if (args->map[mlx->image.y][mlx->image.x] == '1')
				ft_put_square(&mlx->image, 8, 0xFF0000);
			else if (args->map[mlx->image.y][mlx->image.x] != '1' && args->map[mlx->image.y][mlx->image.x] != '2')
				ft_put_square(&mlx->image, 8, 0xFFFFFF);
		}	
	}
	mlx->image.y = args->y_player/8;
	mlx->image.x = args->x_player/8;
	
	ft_put_player(&mlx->image);
	ft_raycasting(args);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image.img, \
		0, 0);
	mlx_hook(mlx->win, 2, 1L<<0, hook_key, args);
	mlx_loop(mlx->mlx);
    return (0);
}

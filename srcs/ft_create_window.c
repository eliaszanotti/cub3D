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
		args->x_player -= 32;
	if (key == 65362 && args->map[(args->y_player - 32)/32][args->x_player/32] == '0') //up
		args->y_player -= 32;
	if (key == 65363 && args->map[args->y_player/32][(args->x_player + 32)/32] == '0') //right
		args->x_player += 32;
	if (key == 65364 && args->map[(args->y_player + 32)/32][args->x_player/32] == '0') //down
		args->y_player += 32;
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

void	ft_put_square(t_img *img, int size, int color)
{
	int i = -1;
	int j;
	// printf("put square : %p\n", args->mlx->image.img);
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			my_mlx_pixel_put(img, (img->x * 32) + i, (img->y * 32) + j, color);
	}
}

int ft_create_window(t_args *args)
{
	t_mlx mlx;

	mlx = *args->mlx;
	mlx.image.img = mlx_new_image(mlx.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx.image.addr = mlx_get_data_addr(mlx.image.img, &mlx.image.bits_per_pixel, &mlx.image.line_length, &mlx.image.endian);
    // mlx.air.img = mlx_new_image(mlx.mlx, 32, 32);
	// mlx.air.addr = mlx_get_data_addr(mlx.air.img, &mlx.air.bits_per_pixel, &mlx.air.line_length, &mlx.air.endian);
    // mlx.wall.img = mlx_new_image(mlx.mlx, 32, 32);
	// mlx.wall.addr = mlx_get_data_addr(mlx.wall.img, &mlx.wall.bits_per_pixel, &mlx.wall.line_length, &mlx.wall.endian);
    mlx.player.img = mlx_new_image(mlx.mlx, 16, 16);
	mlx.player.addr = mlx_get_data_addr(mlx.player.img, &mlx.player.bits_per_pixel, &mlx.player.line_length, &mlx.player.endian);
	
	mlx.image.y = -1;
	while (args->map[++mlx.image.y])
	{
		mlx.image.x = -1;
		while (args->map[mlx.image.y][++mlx.image.x])
		{
			if (args->map[mlx.image.y][mlx.image.x] == '1')
			{
				ft_put_square(&mlx.image, 32, 0xFF0000);
			}
			else if (args->map[mlx.image.y][mlx.image.x] != '1' && args->map[mlx.image.y][mlx.image.x] != '2')
			{
				ft_put_square(&mlx.image, 32, 0xFFFFFF);
			}	
		}	
	}
	mlx.image.y = args->y_player/32;
	mlx.image.x = args->x_player/32;
	
	// printf("create : %p\n", args->mlx->image.img);
	ft_put_square(&mlx.image, 16, 0x0000FF);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.image.img, \
		0, 0);
	mlx_hook(mlx.win, 2, 1L<<0, hook_key, args);
	mlx_loop(mlx.mlx);
    return (0);
}

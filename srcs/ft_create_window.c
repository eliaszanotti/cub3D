/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:26:46 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/03/28 20:16:15 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	hook_key(int key, t_mlx *mlx)
{
	(void)mlx;
	if (key == 65307)
		exit (0);
	return (0);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;
	if (x < SCREEN_WIDTH || y < SCREEN_HEIGHT)
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_put_square(t_img *data, int size, int color)
{
	int i = 0;
	int j;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			my_mlx_pixel_put(data, i, j, color);
	}
	
}

int ft_create_window(t_args *args)
{
	(void)args;
    t_mlx   mlx;

    mlx.mlx = mlx_init();
    mlx.win = mlx_new_window(mlx.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D");
    mlx.blue.img = mlx_new_image(mlx.mlx, 32, 32);
	mlx.blue.addr = mlx_get_data_addr(mlx.blue.img, &mlx.blue.bits_per_pixel, &mlx.blue.line_length, &mlx.blue.endian);
    mlx.red.img = mlx_new_image(mlx.mlx, 32, 32);
	mlx.red.addr = mlx_get_data_addr(mlx.red.img, &mlx.red.bits_per_pixel, &mlx.red.line_length, &mlx.red.endian);
	
	
	int i = -1;
	int j;
	while (args->map[++i])
	{
		j = -1;
		while (args->map[i][++j])
		{
			if (args->map[i][j] == '1')
			{
				ft_put_square(&mlx.red, 32, 0xFF0000);
				mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.red.img, \
					j * 32 + j, i * 32 + i);
			}
			else if (args->map[i][j] != '1' && args->map[i][j] != '2')
			{
				ft_put_square(&mlx.blue, 32, 0xFFFFFF);
				mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.blue.img, \
					j * 32 + j, i * 32 + i);
			}	
		}	
	}
	mlx_key_hook(mlx.win, hook_key, &mlx);
	mlx_loop(mlx.mlx);
    return (0);
}

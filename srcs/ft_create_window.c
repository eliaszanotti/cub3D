/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:26:46 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/03/28 19:44:14 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;
	if (x < SCREEN_WIDTH || y < SCREEN_HEIGHT)
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_put_square(t_mlx *data, int size, int color)
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
    mlx.img = mlx_new_image(mlx.mlx, 32, 32);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.line_length, &mlx.endian);
	
	
	int i = -1;
	int j;
	while (args->map[++i])
	{
		j = -1;
		while (args->map[i][++j])
		{
			printf("i = %d , j = %d, value = %c\n", i , j, args->map[i][j]);
			//printf("%c", args->map[i][j]);
			if (args->map[i][j] == '1')
			{
				ft_put_square(&mlx, 32, 0xFF0000);
				mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, j * 32 + j, i * 32 + i);
			}
			else
			{
				ft_put_square(&mlx, 32, 0x00000FF);
				mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, j * 32 + j, i * 32 + i);

				
			}	
				// ft_put_square(&mlx, 32, 0xFFFFFF);
			// else	
			// 	ft_put_square(&mlx, 32, 0x0000FF);
			
		}	
		printf("\n");
	}
	mlx_loop(mlx.mlx);
    return (0);
}

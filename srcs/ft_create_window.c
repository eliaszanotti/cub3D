/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:26:46 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/03/30 10:30:16 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	hook_key(int key, t_args *args)
{
	if (key == ESC_KEY) //echap 
		exit (0);
	if (key == LEFT_ARROW_KEY) //left
	{
		double oldDirX = args->ray->dirX;
		args->ray->dirX = args->ray->dirX * cos(args->ray->rotSpeed) - args->ray->dirY * sin(args->ray->rotSpeed);
		args->ray->dirY = oldDirX * sin(args->ray->rotSpeed) + args->ray->dirY * cos(args->ray->rotSpeed);
		double oldPlaneX = args->ray->planeX;
		args->ray->planeX = args->ray->planeX * cos(args->ray->rotSpeed) - args->ray->planeY * sin(args->ray->rotSpeed);
		args->ray->planeY = oldPlaneX * sin(args->ray->rotSpeed) + args->ray->planeY * cos(args->ray->rotSpeed);
    }
	if (key == UP_ARROW_KEY) //up
    {
		if(args->map[(int)(args->ray->posX + args->ray->dirX * args->ray->moveSpeed)][(int)args->ray->posY] == '0') 
			args->ray->posX += args->ray->dirX * args->ray->moveSpeed;
		if(args->map[(int)args->ray->posX][(int)(args->ray->posY + args->ray->dirY * args->ray->moveSpeed)] == '0')
			args->ray->posY += args->ray->dirY * args->ray->moveSpeed;
    }
	if (key == RIGHT_ARROW_KEY) //right
	{
		double oldDirX = args->ray->dirX;
		args->ray->dirX = args->ray->dirX * cos(-args->ray->rotSpeed) - args->ray->dirY * sin(-args->ray->rotSpeed);
		args->ray->dirY = oldDirX * sin(-args->ray->rotSpeed) + args->ray->dirY * cos(-args->ray->rotSpeed);
		double oldPlaneX = args->ray->planeX;
		args->ray->planeX = args->ray->planeX * cos(-args->ray->rotSpeed) - args->ray->planeY * sin(-args->ray->rotSpeed);
		args->ray->planeY = oldPlaneX * sin(-args->ray->rotSpeed) + args->ray->planeY * cos(-args->ray->rotSpeed);
    }
	if (key == DOWN_ARROW_KEY) //down
    {
		if(args->map[(int)(args->ray->posX - args->ray->dirX * args->ray->moveSpeed)][(int)args->ray->posY] == '0')
			args->ray->posX -= args->ray->dirX * args->ray->moveSpeed;
		if(args->map[(int)args->ray->posX][(int)(args->ray->posY - args->ray->dirY * args->ray->moveSpeed)] == '0')
			args->ray->posY -= args->ray->dirY * args->ray->moveSpeed;
    }
	mlx_destroy_image(args->mlx->mlx, args->mlx->image.img);
	ft_loop(args);
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
	// mlx->image.img = mlx_new_image(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	// mlx->image.addr = mlx_get_data_addr(mlx->image.img, &mlx->image.bits_per_pixel, &mlx->image.line_length, &mlx->image.endian);
	
	// mlx->image.y = -1;
	// while (args->map[++mlx->image.y])
	// {
	// 	mlx->image.x = -1;
	// 	while (args->map[mlx->image.y][++mlx->image.x])
	// 	{
	// 		if (args->map[mlx->image.y][mlx->image.x] == '1')
	// 			ft_put_square(&mlx->image, 8, 0xFF0000);
	// 		else if (args->map[mlx->image.y][mlx->image.x] != '1' && args->map[mlx->image.y][mlx->image.x] != '2')
	// 			ft_put_square(&mlx->image, 8, 0xFFFFFF);
	// 	}	
	// }
	// mlx->image.y = args->y_player/8;
	// mlx->image.x = args->x_player/8;
	
	// ft_put_player(&mlx->image);
	ft_raycasting(args);
	// mlx_hook(mlx->win, 2, 1L<<0, hook_key, args);
	// mlx_loop(mlx->mlx);
    return (0);
}

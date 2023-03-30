/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:56:41 by thibault          #+#    #+#             */
/*   Updated: 2023/03/30 13:34:23 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3D.h"

void	ft_draw_line(int x, int start, int end, int color, t_img *img)
{
	int dx;
	int dy;
	int hyp;

	dx = abs(x - SCREEN_WIDTH / 2);
	while(start++ < end)
	{
		dy = abs(start - SCREEN_HEIGHT / 2);
		hyp = sqrt(dx * dx + dy * dy);
		if (hyp > 800)
			my_mlx_pixel_put(img, x, start, (color & 0xfefefe) >> 4);
		else if (hyp > 600)
			my_mlx_pixel_put(img, x, start, (color & 0xfefefe) >> 3);
		else if (hyp > 400)
			my_mlx_pixel_put(img, x, start, (color & 0xfefefe) >> 2);
		else if (hyp > 200)
			my_mlx_pixel_put(img, x, start, (color & 0xfefefe) >> 1);
		else
			my_mlx_pixel_put(img, x, start, color);
	}
}

void	ft_color(t_img *img)
{
	int i;
	int j;

	i = -1;
	while(++i < SCREEN_HEIGHT)
	{
		j = -1;
		while(++j < SCREEN_WIDTH)
		{
			if (i > SCREEN_HEIGHT / 2)
				my_mlx_pixel_put(img, j, i, 0x2f243a);
			else 
				my_mlx_pixel_put(img, j, i, 0x273469);
		}
	}
}

void	ft_print_cross(t_img *img)
{
	int i;
	int j;

	i = ((SCREEN_HEIGHT / 2) - 2);
	while (i++ < ((SCREEN_HEIGHT / 2) + 2))
	{
		j = ((SCREEN_WIDTH / 2) - 25);
		while (j++ < ((SCREEN_WIDTH / 2) + 25))
			my_mlx_pixel_put(img, j, i, 0xFF0000);
	}
	i = ((SCREEN_HEIGHT / 2) - 25);
	while (i++ < ((SCREEN_HEIGHT / 2) + 25))
	{
		j = ((SCREEN_WIDTH / 2) - 2);
		while (j++ < ((SCREEN_WIDTH / 2) + 2))
			my_mlx_pixel_put(img, j, i, 0xFF0000);
	}

}

void ft_loop(t_args *args)
{
	t_mlx *mlx;

	mlx = args->mlx;
	mlx->image.img = mlx_new_image(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx->image.addr = mlx_get_data_addr(mlx->image.img, &mlx->image.bits_per_pixel, &mlx->image.line_length, &mlx->image.endian);
	ft_color(&mlx->image);
	for(int x = 0; x < SCREEN_WIDTH; x++)
    {
		//calculate ray position and direction
		double cameraX = 2 * x / (double)SCREEN_WIDTH - 1; //x-coordinate in camera space
		double rayDirX = args->ray->dirX + args->ray->planeX * cameraX;
		double rayDirY = args->ray->dirY + args->ray->planeY * cameraX;
		//which box of the map we're in
		int mapX = (int)args->ray->posX;
		int mapY = (int)args->ray->posY;

		double sideDistX;
		double sideDistY;
		double deltaDistX = 1 / rayDirX;
		double deltaDistY = 1 / rayDirY;

		if (deltaDistX < 0)
			deltaDistX *= -1;
		if (deltaDistY < 0)
			deltaDistY *= -1;

		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?
		//calculate step and initial sideDist
		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (args->ray->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - args->ray->posX) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (args->ray->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - args->ray->posY) * deltaDistY;
		}
		//perform DDA
		while(hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if(sideDistX < sideDistY)
			{
			sideDistX += deltaDistX;
			mapX += stepX;
			side = 0;
			}
			else
			{
			sideDistY += deltaDistY;
			mapY += stepY;
			side = 1;
			}
			//Check if ray has hit a wall
			if(args->map[mapX][mapY] == '1') hit = 1;
		}
		if (side == 0) 
      		perpWallDist = (sideDistX - deltaDistX);
		else
      		perpWallDist = (sideDistY - deltaDistY);

		//Calculate height of line to draw on screen
		int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
		if(drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
		if(drawEnd >= SCREEN_HEIGHT) drawEnd = SCREEN_HEIGHT - 1;

		//choose wall color
		int color;
		switch(args->map[mapX][mapY])
		{
		case '1':   color = 0x0080FF;   break; //red
		case '2':   color = 0x00FF00;   break; //green
		case '3':   color = 0x0000FF;    break; //blue
		case '4':   color = 0xFFFFFF;   break; //white
		default: color = 0xFFFF00; break; //yellow
		}
		//give x and y sides different brightness
		if(side == 1) {color = 0x008000;}

		//draw the pixels of the stripe as a vertical line
		// printf("color : %X", color);
		ft_draw_line(SCREEN_WIDTH - x, drawStart, drawEnd, color, &args->mlx->image);
	}
    // circleBres(&args->mlx->image, 400);
    args->ray->moveSpeed = 5 * 0.032; //the constant value is in squares/second
    args->ray->rotSpeed = 3 * 0.032; //the constant value is in radians/second
	ft_create_minimap(args, &mlx->image);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image.img, \
		0, 0);
}

int ft_raycasting(t_args *args)
{
	ft_get_start(args);
    args->ray->planeX = 0;
	args->ray->planeY = 0.66;

    ft_loop(args);
	mlx_hook(args->mlx->win, 2, 1L<<0, hook_keypress, args);
	mlx_hook(args->mlx->win, 3, 1L<<1, hook_keyrelease, args);
	mlx_loop(args->mlx->mlx);
	return (0);
}
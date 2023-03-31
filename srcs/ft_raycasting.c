/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:56:41 by thibault          #+#    #+#             */
/*   Updated: 2023/03/31 15:00:59 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3D.h"

unsigned int ft_get_color(t_img *img, int x, int y)
{
	char *dst;

	dst = img->addr + (y % 64 * img->line_length + x % 64 * \
			(img->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	ft_draw_line(t_args *args, t_img *img, int x, int start, int end)
{
	int dx;
	int dy;
	int hyp;
	int color;
	int texY;

	dx = abs(x - SCREEN_WIDTH / 2);
	while(start++ < end)
	{
		texY = (int)args->ray->texPos & 63;
		args->ray->texPos += args->ray->step;
		color = ft_get_color(&args->texture[args->ray->side], args->ray->texX, texY);
		dy = abs(start - SCREEN_HEIGHT / 2);
		hyp = sqrt(dx * dx + dy * dy);
		if (hyp > 400)
			my_mlx_pixel_put(img, x, start, (color >> 4) & 0b000011110000111100001111);
		else if (hyp > 300)
			my_mlx_pixel_put(img, x, start, (color >> 3) & 0b000111110001111100011111);
		else if (hyp > 200)
			my_mlx_pixel_put(img, x, start, (color >> 2) & 0b001111110011111100111111);
		else if (hyp > 100)
			my_mlx_pixel_put(img, x, start, (color >> 1) & 8355711);
		else
			my_mlx_pixel_put(img, x, start, color);
	}
}

void ft_loop(t_args *args)
{
	t_mlx *mlx;

	mlx = args->mlx;
	mlx->img.img = mlx_new_image(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel, &mlx->img.line_length, &mlx->img.endian);
	ft_print_colors(args);
	for(int x = 0; x < SCREEN_WIDTH; x++)
    {
		//calculate ray position and direction
		double cameraX = 2 * x / (double)SCREEN_WIDTH - 1; //x-coordinate in camera space
		double rayDirX = args->ray->dirX + args->ray->planeX * cameraX;
		double rayDirY = args->ray->dirY + args->ray->planeY * cameraX;
		//which box of the map we're in
		int mapX = (int)args->ray->x;
		int mapY = (int)args->ray->y;

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
		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (args->ray->x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - args->ray->x) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (args->ray->y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - args->ray->y) * deltaDistY;
		}
		//perform DDA
		while(hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if(sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				args->ray->side = 0;
				if (mapX > args->ray->x)
					args->ray->side = 1;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				args->ray->side = 2;
				if (mapY > args->ray->y)
					args->ray->side = 3;
			}
			//Check if ray has hit a wall
			if(args->map[mapX][mapY] == '1') hit = 1;
		}
		// printf("mapX : %d, mapY : %d\n", mapX, mapY);
		if (args->ray->side == 0 || args->ray->side == 1) 
      		perpWallDist = (sideDistX - deltaDistX);
		else
      		perpWallDist = (sideDistY - deltaDistY);

		//Calculate height of line to draw on screen
		int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);

		//calculate lowest_path and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
		if(drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
		if(drawEnd >= SCREEN_HEIGHT) drawEnd = SCREEN_HEIGHT - 1;
		
		double wallX;
		if (args->ray->side == 0 || args->ray->side == 1)
			wallX = args->ray->y + perpWallDist * rayDirY;
		else 
			wallX = args->ray->x + perpWallDist * rayDirX;
		
		args->ray->texX = (int)(wallX * 64.0);
		if (args->ray->side <= 1 && rayDirX > 0)
			args->ray->texX = 64 - args->ray->texX - 1;
		if (args->ray->side >= 2 && rayDirY < 0)
			args->ray->texX = 64 - args->ray->texX - 1;
		
		args->ray->step = 1.0 * 64 / lineHeight;
		args->ray->texPos = (drawStart - SCREEN_HEIGHT / 2 + lineHeight / 2) * args->ray->step;
		ft_draw_line(args, &args->mlx->img, x, drawStart, drawEnd);
	}
    // circleBres(&args->mlx->image, 400);
    args->ray->moveSpeed = 5 * 0.032; //the constant value is in squares/second
    args->ray->rotSpeed = 3 * 0.032; //the constant value is in radians/second
	ft_print_minimap(args, &mlx->img);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, \
		0, 0);
	ft_print_cross(&mlx->img);
}

t_img	ft_create_img(t_args *args, char *path)
{
	int		height;
	int		width;
	t_img	img;
	printf("%s\n\n", path);
	printf("%d\n\n", open(path, O_RDONLY));
	img.img = mlx_xpm_file_to_image(args->mlx->mlx, path, &width, &height);
	printf("%p\n\n", args->mlx->mlx);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	return (img);
}

int	ft_load_texture(t_args *args)
{
	args->texture = malloc(sizeof(t_img) * 4);
	args->texture[0] = ft_create_img(args, "textures/CRATE_1I.xpm");
	args->texture[1] = ft_create_img(args, "textures/CRATE_1N.xpm");
	args->texture[2] = ft_create_img(args, "textures/FLOOR_1B.xpm");
	args->texture[3] = ft_create_img(args, "textures/TECH_4C.xpm");
	// args->west_img = ft_create_img(args, args->west_path);
	// args->east_img = ft_create_img(args, args->east_path);
	return (0);
}

int ft_raycasting(t_args *args)
{
	ft_get_start(args);
	ft_load_texture(args);
    ft_loop(args);
	mlx_hook(args->mlx->win, 2, 1L<<0, hook_keypress, args);
	mlx_hook(args->mlx->win, 3, 1L<<1, hook_keyrelease, args);
	mlx_loop(args->mlx->mlx);
	return (0);
}

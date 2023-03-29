/* ************************************************************************** */
/*                                                                              */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:56:41 by thibault          #+#    #+#             */
/*   Updated: 2023/03/29 13:09:44 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3D.h"

void	ft_draw_line(int x, int start, int end, int color, t_img *img)
{
	while(start++ < end)
		my_mlx_pixel_put(img, x, start, color);
}

int ft_raycasting(t_args *args)
{
    double posX = 22, posY = 12;   //x and y start position
    double dirX = -1, dirY = 0; //initial direction vector
    double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

    // double time = 0; //time of current frame
    // double oldTime = 0; //time of previous frame

    for(int x = 0; x < SCREEN_WIDTH; x++)
    {
		//calculate ray position and direction
		double cameraX = 2 * x / (double)SCREEN_WIDTH - 1; //x-coordinate in camera space
		double rayDirX = dirX + planeX * cameraX;
		double rayDirY = dirY + planeY * cameraX;
		//which box of the map we're in
		int mapX = (int)posX;
		int mapY = (int)posY;

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
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
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
		if(side == 0) perpWallDist = (sideDistX - deltaDistX);
		else    perpWallDist = (sideDistY - deltaDistY);

		//Calculate height of line to draw on screen
		int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
		if(drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
		if(drawEnd >= SCREEN_HEIGHT) drawEnd = SCREEN_HEIGHT - 1;

		//choose wall color
		int color;
		printf("index : %c\n", args->map[mapX][mapY]);
		switch(args->map[mapX][mapY])
		{
		case '1':   color = 0xFF0000;   break; //red
		case '2':   color = 0x00FF00;   break; //green
		case '3':   color = 0x0000FF;    break; //blue
		case '4':   color = 0xFFFFFF;   break; //white
		default: color = 0xFFFF00; break; //yellow
		}
		//give x and y sides different brightness
		if(side == 1) {color = 0x990000;}

		//draw the pixels of the stripe as a vertical line
		// printf("color : %X", color);
		ft_draw_line(x, drawStart, drawEnd, color, &args->mlx->image);
	}
	return (0);
    //timing for input and FPS counter
    // oldTime = time;
    // time = getTicks();
    // double frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
    // print(1.0 / frameTime); //FPS counter
    // redraw();
    // cls();

    // //speed modifiers
    // double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
    // double rotSpeed = frameTime * 3.0; //the constant value is in radians/second
    // readKeys();
    // //move forward if no wall in front of you
    // if(keyDown(SDLK_UP))
    // {
    // if(args->map[int(posX + dirX * moveSpeed)][int(posY)] == false) 
    // posX += dirX * moveSpeed;
    // if(args->map[int(posX)][int(posY + dirY * moveSpeed)] == false)
    // posY += dirY * moveSpeed;
    // }
    // //move backwards if no wall behind you
    // if(keyDown(SDLK_DOWN))
    // {
    // if(args->map[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
    // if(args->map[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
    // }
    // //rotate to the right
    // if(keyDown(SDLK_RIGHT))
    // {
    // //both camera direction and camera plane must be rotated
    // double oldDirX = dirX;
    // dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
    // dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
    // double oldPlaneX = planeX;
    // planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
    // planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
    // }
    // //rotate to the left
    // if(keyDown(SDLK_LEFT))
    // {
    // //both camera direction and camera plane must be rotated
    // double oldDirX = dirX;
    // dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
    // dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
    // double oldPlaneX = planeX;
    // planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
    // planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
    // }
}
/* ************************************************************************** */
/*                                                                            */
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

int ft_raycasting(t_args *args)
{
	double dirX = -1;
	double dirY = 0;
	double planeX = 0;
	double planeY = 0.66;
	double time = 0;
	double old_time = 0;
	int	x = 0;

	while (x++ < SCREEN_WIDHT)
	{
		double cameraX = 2 * x / (double)w - 1; //x-coordinate in camera space
     	double rayDirX = dirX + planeX * cameraX;
      	double rayDirY = dirY + planeY * cameraX;
     	int mapX = args->x_player;
      	int mapY = args->y_player;

		double sideDistX;
		double sideDistY;
		double deltaDistX = 1/rayDirX;
		double deltaDistY = 1/rayDirY;
		
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
        if(worldMap[mapX][mapY] > 0) hit = 1;
      }
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:19:29 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/03/30 13:22:12 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    ft_move(t_args *args)
{
    if (args->move_left)
    {
        double oldDirX = args->ray->dirX;
        args->ray->dirX = args->ray->dirX * cos(args->ray->rotSpeed) - args->ray->dirY * sin(args->ray->rotSpeed);
        args->ray->dirY = oldDirX * sin(args->ray->rotSpeed) + args->ray->dirY * cos(args->ray->rotSpeed);
        double oldPlaneX = args->ray->planeX;
        args->ray->planeX = args->ray->planeX * cos(args->ray->rotSpeed) - args->ray->planeY * sin(args->ray->rotSpeed);
        args->ray->planeY = oldPlaneX * sin(args->ray->rotSpeed) + args->ray->planeY * cos(args->ray->rotSpeed);
    }
    if (args->move_right)
    {
        double oldDirX = args->ray->dirX;
			args->ray->dirX = args->ray->dirX * cos(-args->ray->rotSpeed) - args->ray->dirY * sin(-args->ray->rotSpeed);
			args->ray->dirY = oldDirX * sin(-args->ray->rotSpeed) + args->ray->dirY * cos(-args->ray->rotSpeed);
			double oldPlaneX = args->ray->planeX;
			args->ray->planeX = args->ray->planeX * cos(-args->ray->rotSpeed) - args->ray->planeY * sin(-args->ray->rotSpeed);
			args->ray->planeY = oldPlaneX * sin(-args->ray->rotSpeed) + args->ray->planeY * cos(-args->ray->rotSpeed);
    }
    if (args->move_up)
    {
        if(args->map[(int)(args->ray->posX + args->ray->dirX * args->ray->moveSpeed)][(int)args->ray->posY] == '0') 
				args->ray->posX += args->ray->dirX * args->ray->moveSpeed;
			if(args->map[(int)args->ray->posX][(int)(args->ray->posY + args->ray->dirY * args->ray->moveSpeed)] == '0')
				args->ray->posY += args->ray->dirY * args->ray->moveSpeed;
    }
    if (args->move_down)
    {
        if(args->map[(int)(args->ray->posX - args->ray->dirX * args->ray->moveSpeed)][(int)args->ray->posY] == '0')
				args->ray->posX -= args->ray->dirX * args->ray->moveSpeed;
			if(args->map[(int)args->ray->posX][(int)(args->ray->posY - args->ray->dirY * args->ray->moveSpeed)] == '0')
				args->ray->posY -= args->ray->dirY * args->ray->moveSpeed;
    }
}
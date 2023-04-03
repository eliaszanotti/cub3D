/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_create_window.c								 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: thibaultgiraudon <thibaultgiraudon@stud	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/03/28 16:26:46 by tgiraudo		  #+#	#+#			 */
/*   Updated: 2023/03/30 18:07:45 by elias			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "cub3D.h"

int	hook_keypress(int key, t_args *args)
{
	if (key == ESC_KEY)
		exit(0);
	if (key == LEFT_ARROW_KEY)
		args->move_left = 1;
	if (key == UP_ARROW_KEY)
		args->move_up = 1;
	if (key == RIGHT_ARROW_KEY)
		args->move_right = 1;
	if (key == DOWN_ARROW_KEY)
		args->move_down = 1;
	ft_move(args);
	mlx_destroy_image(args->mlx->mlx, args->mlx->img.img);
	ft_loop(args);
	return (0);
}

int	hook_keyrelease(int key, t_args *args)
{
	(void)key;
	args->move_down = 0;
	args->move_left = 0;
	args->move_up = 0;
	args->move_right = 0;
	return (0);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	if (x < SCREEN_WIDTH && y < SCREEN_HEIGHT)
	{
		dst = data->addr + (y * data->line_length + x * \
			(data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

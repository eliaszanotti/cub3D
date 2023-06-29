/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flashlight.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:40:06 by elias             #+#    #+#             */
/*   Updated: 2023/06/29 16:40:46 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_print_flashlight(t_args *args, t_img *img)
{
	if (args->flash_timer <= 0)
		args->expanded = 0;
	if (args->flash_timer > 0)
		ft_print_square(img, SCREEN_WIDTH - 165, 20);
	if (args->flash_timer > 200)
		ft_print_square(img, SCREEN_WIDTH - 140, 20);
	if (args->flash_timer > 400)
		ft_print_square(img, SCREEN_WIDTH - 115, 20);
	if (args->flash_timer > 600)
		ft_print_square(img, SCREEN_WIDTH - 90, 20);
	if (args->flash_timer > 800)
		ft_print_square(img, SCREEN_WIDTH - 65, 20);
	if (args->flash_timer > 990)
		ft_print_square(img, SCREEN_WIDTH - 40, 20);
	return (0);
}

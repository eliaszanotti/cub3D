/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:43:07 by ezanotti          #+#    #+#             */
/*   Updated: 2023/03/10 15:53:34 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_error_range_1(int error_code)
{
	if (error_code == 2)
		printf("Wrong amount of arguments "\
			"(only one is expected in .cub format)\n");
	return (1);
}

int	ft_error(int error_code)
{
	if (error_code)
		printf("\e[1;31m[ERROR:%d]\e[0m ", error_code);
	if (error_code < 10)
		return (ft_error_range_1(error_code));
	else if (error_code == 99)
		printf("Malloc cannot be created\n");
	else
		printf("Undefined\n");
	return (1);
}

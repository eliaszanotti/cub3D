/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:10:33 by ezanotti          #+#    #+#             */
/*   Updated: 2023/03/10 18:01:19 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_args	args;

	if (argc != 2)
		return (ft_error(2));
	if (ft_reset_struct(&args))
		return (1);
	if (ft_parsing(&args, argv[1]))
		return (1);

	(void)argv;

	return (0);
}

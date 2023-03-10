/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:10:33 by ezanotti          #+#    #+#             */
/*   Updated: 2023/03/10 16:51:09 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"



int	ft_parsing(t_args *args, char *cub_file)
{
	int	fd;

	if (!*cub_file)
		return (ft_error(3));
	if (!ft_is_extension_correct(cub_file, ".cub"))
		return (ft_error(4));
	fd = open(cub_file, O_RDONLY);
	if (fd < 0)
		return (ft_error(5));



	args->cub_file = cub_file;
	return (0);
}

int	main(int argc, char **argv)
{
	t_args	args;

	if (argc != 2)
		return (ft_error(2));
	if (ft_parsing(&args, argv[1]))
		return (1);

	(void)argv;

	return (0);
}

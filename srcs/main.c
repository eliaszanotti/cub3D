/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:10:33 by ezanotti          #+#    #+#             */
/*   Updated: 2023/03/28 17:17:22 by elias            ###   ########.fr       */
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

	int i = -1;
	int j;
	while (args.map[++i])
	{
		j = -1;
		while (args.map[i][++j])
			printf("%c", args.map[i][j]);
		printf("\n");
	}

	if (ft_create_window(&args))
		return (1);
	ft_free_struct(&args);
	return (0);
}

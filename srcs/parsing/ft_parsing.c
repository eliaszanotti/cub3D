/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:57:06 by ezanotti          #+#    #+#             */
/*   Updated: 2023/03/10 17:57:15 by ezanotti         ###   ########.fr       */
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
	if (ft_parse_infos(args, fd))
		return (1);
	return (0);
}

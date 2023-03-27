/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:12:47 by elias             #+#    #+#             */
/*   Updated: 2023/03/23 18:18:37 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_ilst	*ft_get_ilst(char *line)
{
	t_ilst	*ilst;
	t_ilst	*new;
	int		i;

	ilst = NULL;
	i = -1;
	while (line[++i] != '\n')
	{
		new = ft_ilstnew(line[i]);
		if (!new)
			return (NULL);
		ft_ilstadd_back(&ilst, new);
	}
	return (ilst);
}

int	ft_parse_map(t_args *args, int fd)
{	
	char	*line;
	t_list	*list;
	t_list	*new;
	t_ilst	*ilst;

	list = args->map_list;
	line = get_next_line(fd);
	while (line)
	{
		ilst = ft_get_ilst(line);
		if (!ilst)
			return (ft_error(99));
		new = ft_lstnew(ilst);
		if (!new)
			return (ft_error(99));
		ft_lstadd_back(&list, new);
		free(line);
		line = get_next_line(fd);
	}
	args->map_list = list;
	return (0);
}

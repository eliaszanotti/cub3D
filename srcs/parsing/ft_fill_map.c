/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:56:05 by elias             #+#    #+#             */
/*   Updated: 2023/06/27 16:00:50 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_finish_line(t_ilst **ilst, int size)
{
	t_ilst	*new;
	t_ilst	*current;
	int		i;

	current = *ilst;
	i = ft_ilstsize(current);
	while (i++ < size)
	{
		new = ft_ilstnew('2');
		if (!new)
			return (1);
		ft_ilstadd_back(ilst, new);
	}
	return (0);
}

int	ft_fill_map(t_args *args)
{
	t_list	*list;
	int		size;
	int		current;

	list = args->map_list;
	size = 0;
	while (list)
	{
		current = ft_ilstsize(list->content);
		if (current > size)
			size = current;
		list = list->next;
	}
	list = args->map_list;
	while (list)
	{
		if (ft_finish_line((t_ilst **)&list->content, size))
			return (1);
		list = list->next;
	}
	return (0);
}

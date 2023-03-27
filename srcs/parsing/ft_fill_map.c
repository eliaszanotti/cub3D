/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:56:05 by elias             #+#    #+#             */
/*   Updated: 2023/03/27 14:17:40 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_replace_void(t_ilst **ilst)
{
	t_ilst	*current;
	t_ilst	*first;
	int		i;

	i = 0;
	first = *ilst;
	current = *ilst;
	while (current)
	{
		if (current->content == ' ')
			current->content = '1';
		current = current->next;
		i++;
	}
	*ilst = first;
	return (0);

}

static int	ft_finish_line(t_ilst **ilst, int size)
{
	t_ilst	*new;
	t_ilst	*current;
	int		i;
	
	current = *ilst;
	i = ft_ilstsize(current);
	while (i++ < size)
	{
		new = ft_ilstnew('1');
		if (!new)
			return (1);
		ft_ilstadd_back(ilst, new);
	}
	return (0);
}

int ft_fill_map(t_args *args)
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
		if (ft_replace_void((t_ilst **)&list->content))
			return (1);
		if (ft_finish_line((t_ilst **)&list->content, size))
			return (1);
		list = list->next;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:27:59 by elias             #+#    #+#             */
/*   Updated: 2023/03/27 12:09:34 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_is_valid_char(char c)
{
	char	*charset;

	charset = " 01NSEW";
	while (*charset)
		if (*charset++ == c)
			return (1);
	return (0);
}

int	ft_is_valid_map(t_args *args)
{
	t_list	*list;
	t_ilst	*current;

	list = args->map_list;
	while (list)
	{
		current = list->content;
		while (current)
		{
			if (!ft_is_valid_char((char)current->content))
				return (0);
			current = current->next;
		}
		list = list->next;
	}
	return (1);
}

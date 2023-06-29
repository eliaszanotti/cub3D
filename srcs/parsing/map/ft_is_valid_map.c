/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:27:59 by elias             #+#    #+#             */
/*   Updated: 2023/06/29 14:40:50 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_is_valid_char(char c)
{
	char	*charset;

	charset = " 012356NSEW";
	while (*charset)
		if (*charset++ == c)
			return (1);
	return (0);
}

static int	ft_get_alpha(t_ilst *current, int alpha)
{
	while (current)
	{
		if (!ft_is_valid_char((char)current->content))
			return (-1);
		if (ft_isalpha((char)current->content))
			alpha++;
		current = current->next;
	}
	return (alpha);
}

int	ft_is_valid_map(t_args *args)
{
	t_list	*list;
	int		alpha;

	alpha = 0;
	list = args->map_list;
	while (list)
	{
		alpha = ft_get_alpha(list->content, alpha);
		if (alpha == -1)
			return (0);
		list = list->next;
	}
	if (alpha > 1 || alpha == 0)
		return (0);
	return (1);
}

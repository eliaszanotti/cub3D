/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:27:59 by elias             #+#    #+#             */
/*   Updated: 2023/04/25 15:05:41 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_is_valid_char(char c)
{
	char	*charset;

	charset = " 013NSEW";
	while (*charset)
		if (*charset++ == c)
			return (1);
	return (0);
}

int	ft_is_valid_map(t_args *args)
{
	t_list	*list;
	t_ilst	*current;
	int		alpha;

	alpha = 0;
	list = args->map_list;
	while (list)
	{
		current = list->content;
		while (current)
		{
			if (!ft_is_valid_char((char)current->content))
				return (0);
			if (ft_isalpha((char)current->content))
				alpha++;
			current = current->next;
		}
		list = list->next;
	}
	if (alpha > 1 || alpha == 0)
		return (0);
	return (1);
}

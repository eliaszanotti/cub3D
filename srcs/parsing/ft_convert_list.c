/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:18:30 by elias             #+#    #+#             */
/*   Updated: 2023/04/05 13:23:39 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	*ft_get_char_content(t_ilst *ilst)
{
	char	*content;
	int		size;

	size = ft_ilstsize(ilst);
	content = malloc(sizeof(char) * (size + 1));
	if (!content)
		return (NULL);
	size = 0;
	while (ilst)
	{
		content[size] = ilst->content;
		if (!content[size++])
			return (NULL);
		ilst = ilst->next;
	}
	content[size] = 0;
	return (content);
}

int	ft_convert_list(t_args *args)
{
	t_list	*list;
	int		size;

	list = args->map_list;
	size = ft_lstsize(list);
	printf("size : %d\n", size);
	args->map = malloc(sizeof(char *) * (size + 1));
	if (!args->map)
		return (ft_error(99));
	size = 0;
	while (list)
	{
		args->map[size] = ft_get_char_content(list->content);
		if (!args->map[size++])
			return (ft_free_str(args->map), ft_error(99));
		list = list->next;
	}
	args->map[size] = NULL;
	return (ft_free_list(args->map_list), 0);
}

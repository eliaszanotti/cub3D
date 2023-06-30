/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:13:42 by elias             #+#    #+#             */
/*   Updated: 2023/06/30 12:16:43 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_free_ilst(t_ilst *ilst)
{
	t_ilst	*tmp;

	while (ilst)
	{
		tmp = ilst->next;
		free(ilst);
		ilst = tmp;
	}
}

void	ft_free_list(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		ft_free_ilst(list->content);
		tmp = list->next;
		free(list);
		list = tmp;
	}
}

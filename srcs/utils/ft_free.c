/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:55:41 by elias             #+#    #+#             */
/*   Updated: 2023/03/28 11:44:04 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	ft_free_ilst(t_ilst *ilst)
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

void	ft_free_struct(t_args *args)
{
	free(args->north);
	free(args->south);
	free(args->west);
	free(args->east);
	free(args->floor);
	free(args->ceiling);
}

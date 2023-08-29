/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:12:47 by elias             #+#    #+#             */
/*   Updated: 2023/06/20 15:38:56 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	*ft_skip_empty_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line && !ft_strcmp(line, "\n"))
	{
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

static t_ilst	*ft_get_ilst(char *line)
{
	t_ilst	*ilst;
	t_ilst	*new;
	int		i;

	ilst = NULL;
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == ' ')
			new = ft_ilstnew('2');
		else
			new = ft_ilstnew(line[i]);
		if (!new)
			return (NULL);
		ft_ilstadd_back(&ilst, new);
		i++;
	}
	return (ilst);
}

static int	ft_finish_gnl(int fd, char *line)
{
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (0);
}

static int	ft_add_to_list(t_list **list, char *line)
{
	t_ilst	*ilst;
	t_list	*new;

	ilst = ft_get_ilst(line);
	if (!ilst)
		return (ft_error(99));
	new = ft_lstnew(ilst);
	if (!new)
		return (ft_error(99));
	ft_lstadd_back(list, new);
	return (0);
}

int	ft_get_map(t_args *args, int fd)
{
	char	*line;
	t_list	*list;

	list = NULL;
	line = ft_skip_empty_line(fd);
	if (!line)
		return (ft_error(6));
	while (line && ft_strcmp(line, "\n"))
	{
		if (ft_add_to_list(&list, line))
			return (1);
		free(line);
		line = get_next_line(fd);
	}
	ft_finish_gnl(fd, line);
	args->map_list = list;
	return (0);
}

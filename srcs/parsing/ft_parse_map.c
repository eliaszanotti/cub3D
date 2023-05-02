/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:12:47 by elias             #+#    #+#             */
/*   Updated: 2023/05/02 16:56:41 by elias            ###   ########.fr       */
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

int	ft_parse_map(t_args *args, int fd)
{	
	char	*line;
	t_list	*list;
	t_list	*new;
	t_ilst	*ilst;

	list = args->map_list;
	line = ft_skip_empty_line(fd);
	if (!line)
		return (ft_error(99));
	while (line && ft_strcmp(line, "\n"))
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
	ft_finish_gnl(fd, line);
	args->map_list = list;
	return (0);
}

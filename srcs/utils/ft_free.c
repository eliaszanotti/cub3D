/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: thibaultgiraudon <thibaultgiraudon@stud	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/03/27 17:55:41 by elias			 #+#	#+#			 */
/*   Updated: 2023/04/04 13:54:51 by elias            ###   ########.fr       */
/*																			*/
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

void	ft_free_mlx(t_args *args)
{
	mlx_destroy_window(args->mlx->mlx, args->mlx->win);
	free(args->mlx->mlx);
	free(args->mlx);
	free(args->ray);
}

void	ft_free_struct(t_args *args)
{
	free(args->north_path);
	free(args->south_path);
	free(args->west_path);
	free(args->east_path);
	free(args->floor);
	free(args->ceiling);
}

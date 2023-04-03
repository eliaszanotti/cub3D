/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_get_start.c									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: thibaultgiraudon <thibaultgiraudon@stud	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/03/30 11:04:19 by tgiraudo		  #+#	#+#			 */
/*   Updated: 2023/03/31 19:04:13 by thibaultgir	  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "cub3D.h"

void	ft_get_dir(t_args *args, char c)
{
	if (c == 'N')
	{
		args->ray->dir_x = -1;
		args->ray->dir_y = 0;
		args->ray->plane_x = 0;
		args->ray->plane_y = 0.66;
	}
	if (c == 'S')
	{
		args->ray->dir_x = 1;
		args->ray->dir_y = 0;
		args->ray->plane_x = 0;
		args->ray->plane_y = -0.66;
	}
	if (c == 'E')
	{
		args->ray->dir_x = 0;
		args->ray->dir_y = 1;
		args->ray->plane_x = 0.66;
		args->ray->plane_y = 0;
	}
	if (c == 'W')
	{
		args->ray->dir_x = 0;
		args->ray->dir_y = -1;
		args->ray->plane_x = -0.66;
		args->ray->plane_y = 0;
	}
}

int	ft_get_start(t_args *args)
{
	int	i;
	int	j;

	i = -1;
	args->ray = malloc(sizeof(t_ray));
	while (args->map[++i])
	{
		j = -1;
		while (args->map[i][++j])
		{
			if (ft_isalpha(args->map[i][j]))
			{
				ft_get_dir(args, args->map[i][j]);
				args->ray->pos_x = i + 0.5;
				args->ray->pos_y = j + 0.5;
			}
		}
	}
	return (0);
}

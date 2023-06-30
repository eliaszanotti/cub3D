/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: thibaultgiraudon <thibaultgiraudon@stud	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/03/27 17:55:41 by elias			 #+#	#+#			 */
/*   Updated: 2023/05/02 16:32:55 by elias            ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "cub3D.h"

void	ft_free_struct(t_args *args)
{
	if (args->north_path)
		free(args->north_path);
	if (args->south_path)
		free(args->south_path);
	if (args->west_path)
		free(args->west_path);
	if (args->east_path)
		free(args->east_path);
	if (args->floor)
		free(args->floor);
	if (args->ceiling)
		free(args->ceiling);
}

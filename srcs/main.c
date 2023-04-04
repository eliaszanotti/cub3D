/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: tgiraudo <tgiraudo@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/03/10 14:10:33 by ezanotti		  #+#	#+#			 */
/*   Updated: 2023/04/04 13:22:07 by elias            ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "cub3D.h"

void	ft_log(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			printf("%c", map[i][j]);
		printf("\n");
	}
}

int	main(int argc, char **argv)
{
	t_args	args;

	if (argc != 2)
		return (ft_error(2));
	if (ft_reset_struct(&args))
		return (1);
	if (ft_parsing(&args, argv[1]))
		return (1);
	if (ft_init_window(&args))
		return (ft_free_str(args.map), ft_free_struct(&args), 1);
	if (ft_raycasting(&args))
		return (1);
	ft_free_struct(&args);
	return (0);
}

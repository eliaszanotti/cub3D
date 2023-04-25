/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: tgiraudo <tgiraudo@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/03/10 14:10:33 by ezanotti		  #+#	#+#			 */
/*   Updated: 2023/04/11 16:26:07 by ezanotti         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "cub3D.h"

void	ft_log(t_args *args)
{
	int	i;
	int	j;

	i = 0;
	while (args->map[i])
	{
		j = -1;
		while (args->map[i][++j])
			printf("%c", args->map[i][j]);
		printf("\n");
		i++;
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
	return (0);
}

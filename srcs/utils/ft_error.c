/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ezanotti <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/03/10 15:43:07 by ezanotti		  #+#	#+#			 */
/*   Updated: 2023/04/03 12:41:43 by elias            ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_error_range(int error_code)
{
	if (error_code == 2)
		printf("Wrong amount of arguments "\
			"(only one is expected in .cub format)\n");
	if (error_code == 3)
		printf("File not found\n");
	if (error_code == 4)
		printf("Incorrect file extension (.cub expected)\n");
	if (error_code == 5)
		printf("Can't open file\n");
	if (error_code == 6)
		printf("Invalid map\n");
	if (error_code == 7)
		printf("Invalid map (map not surrounded by walls)\n");
	if (error_code == 8)
		printf("Invalid color format (R,G,B)\n");
	if (error_code == 9)
		printf("Invalid texture path\n");
	if (error_code == 10)
		printf("Invalid map (wrong character)\n");
	return (1);
}

int	ft_error(int error_code)
{
	if (error_code)
		printf("\e[1;31m[ERROR:%d]\e[0m ", error_code);
	if (error_code < 99)
		return (ft_error_range(error_code));
	else if (error_code == 99)
		printf("Malloc cannot be created\n");
	else
		printf("Undefined\n");
	return (1);
}

/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_is_extension_correct.c						  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ezanotti <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/03/10 16:36:35 by ezanotti		  #+#	#+#			 */
/*   Updated: 2023/03/10 16:48:00 by ezanotti		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "cub3D.h"

int	ft_is_extension_correct(char *file, char *extension)
{
	int	len_file;
	int	len_extension;
	int	i;

	len_file = ft_strlen(file);
	len_extension = ft_strlen(extension);
	if (len_file < len_extension + 1)
		return (0);
	i = 0;
	while (*file && i++ < len_file - len_extension)
		file++;
	if (ft_strcmp(file, extension))
		return (0);
	return (1);
}

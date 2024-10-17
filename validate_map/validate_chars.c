/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:41:53 by rdavurov          #+#    #+#             */
/*   Updated: 2024/10/17 17:08:08 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	validate_chars(char **map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P' || map[i][j] == 'E')
				k++;
			if ((map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C'
					&& map[i][j] != 'E' && map[i][j] != 'P' && map[i][j] != 'M')
				|| k > 2)
			{
				write(1, "Error\nInvalid map\n", 18);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

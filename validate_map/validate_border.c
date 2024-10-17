/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_border.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:43:11 by rdavurov          #+#    #+#             */
/*   Updated: 2024/10/17 17:07:28 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	validate_border(char **map)
{
	int		i;
	int		j;
	size_t	width;
	size_t	height;

	width = map_width(map) - 1;
	height = map_height(map) - 1;
	i = -1;
	while (++i, map[i])
	{
		j = -1;
		while (++j, map[i][j])
		{
			if (i == 0 || i == height || j == 0 || j == width)
			{
				if (map[i][j] != '1')
				{
					write(1, "Invalid map!\n", 13);
					exit(1);
				}
			}
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:44:22 by rdavurov          #+#    #+#             */
/*   Updated: 2024/09/29 18:35:11 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	 array_len(char **array)
{
	int i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

static char     **map_copy(char **map)
{
	char **copy;
	int i;
	int j;

	i = 0;
	copy = (char **)malloc(sizeof(char *) * (array_len(map) + 1));
	while (map[i])
	{
		j = 0;
		copy[i] = (char *)malloc(sizeof(char) * (ft_strlen(*map) + 1));
		while (map[i][j])
		{
			copy[i][j] = map[i][j];
			j++;
		}
		copy[i][j] = '\0';
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void     flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'r')
		return ;
    map[y][x] = 'r';
    flood_fill(map, x, y - 1);
    flood_fill(map, x - 1, y);
    flood_fill(map, x, y + 1);
    flood_fill(map, x + 1, y);
}

void	find_exit(char **map)
{
	int i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'C')
			{
				write(1, "Error!", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	find_player(char **map, int *x, int *y)
{
	*x = 1;
	*y = 1;

	while (map[*y])
	{
		*x = 1;
		while (map[*y][*x])
		{
			if (map[*y][*x] == 'P')
				break;
			(*x)++;
		}
		if (map[*y][*x] == 'P')
			break;
		(*y)++;
	}
}

void validate_path(char **map)
{
	char **copy;
	int	x;
	int y;

    copy = map_copy(map);
	find_player(map, &x, &y);
	flood_fill(copy, x, y);
	find_exit(copy);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:08:36 by rdavurov          #+#    #+#             */
/*   Updated: 2024/10/09 19:03:40 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_width(char **map)
{
	int	i;

	i = 5;
	while (map[2][i])
		i++;
	return (i);
}

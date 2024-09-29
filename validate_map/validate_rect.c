/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_rect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:41:56 by rdavurov          #+#    #+#             */
/*   Updated: 2024/09/29 18:35:19 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void validate_rect(char **map)
{
    int i;

    i = 1;
    while (map[i])
    {
        if (ft_strlen(map[i]) != ft_strlen(map[i - 1])) {
            write(1, "Error\nInvalid map\n", 18);
            exit(1);
        }
        i++;
    }
}

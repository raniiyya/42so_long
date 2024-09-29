/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_border.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:43:11 by rdavurov          #+#    #+#             */
/*   Updated: 2024/09/29 18:34:53 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void validate_border(char **map)
{
    int i;
    int j;

    j = 0;
    while (map[0][j])
    {
        if (map[0][j] != '1') //checking the 1st line
        {
            write(1, "Error\nInvalid map\n", 18);
            exit(1);
        }
        j++;
    }
    i = 0;
    j = 0;
    while (map[i]) //going to the last line
        i++;
    while (map[i - 1][j])
    {
        if (map[i - 1][j] != '1') //cheching the last line
        {
            write(1, "Error\nInvalid map\n", 18);
            exit(1);
        }
        j++;
    }
    i = 0;
    j = 0;
    while (map[i][j]) //going to the last column i guess
        j++;
    if (map[i][0] != '1' && map[i][j] != '1') //checking the 1st and last column
    {
        write(1, "Error\nInvalid map\n", 18);
        exit(1);
    }
}

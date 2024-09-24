/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:20:20 by rdavurov          #+#    #+#             */
/*   Updated: 2024/09/24 15:20:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void parse_map(char **map, char *file)
{
    char *str;
    char *line;
    int fd = open(file, O_RDONLY);

    str = ft_strdup("");
    line = get_next_line(fd);
    while (line)
    {
        str = ft_strjoin(str, line);
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    map = ft_split(str, '\n');
}

// split("raniia\njest\npiekna\nbaaardzo", '\n') -> ["raniia", "jest", "piekna", "baaardzo"]
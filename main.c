/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:37:34 by rdavurov          #+#    #+#             */
/*   Updated: 2024/09/29 18:35:47 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_game  game;

    if (!argv[1])
    {
        write(1, "No map!!!", 9);
        exit(1);
    }
    game.map = parse_map(game.map, argv[1]);
    validate_map(game.map);
    init_game(&game);
    return (0);
}
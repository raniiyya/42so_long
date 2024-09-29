/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:45:31 by rdavurov          #+#    #+#             */
/*   Updated: 2024/09/29 18:37:09 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    init_game(t_game *game)
{
    game->mlx = mlx_init();
    game->window = mlx_new_window(game->mlx, 900, 600, "so_long");
    mlx_loop(game->mlx);
    
}
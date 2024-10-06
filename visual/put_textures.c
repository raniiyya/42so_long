/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:20:19 by rdavurov          #+#    #+#             */
/*   Updated: 2024/10/06 18:57:18 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static  void    put_texture(t_game game, void *txt, short x, short y)
{
    mlx_put_image_to_window(game.mlx, game.win, txt, x, y);
}

static  void    fill_player_textures(t_game game, char key, short x, short y)
{
    if (key == 'w')
        put_texture(game, game.textures.pu, x, y);
    if (key == 's')
        put_texture(game, game.textures.pd, x, y);
    if (key == 'a')
        put_texture(game, game.textures.pl, x, y);
    if (key == 'd')
        put_texture(game, game.textures.pr, x, y);
}

void    put_textures(t_game game, char key)
{
    short   i;
    short   j;

    i = -1;
    while (++i, game.map[i])
    {
        j = -1;
        while (++j, game.map[i][j])
        {
            if (game.map[i][j] == '0')
                put_texture(game, game.textures.b, j * 50, i * 50);
            if (game.map[i][j] == '1')
                put_texture(game, game.textures.w, j * 50, i * 50);
            if (game.map[i][j] == 'C')
                put_texture(game, game.textures.c, j * 50, i * 50);
            if (game.map[i][j] == 'P')
                put_texture(game, key, j * 50, i * 50);
        }
    }
}
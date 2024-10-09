/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:29:58 by rdavurov          #+#    #+#             */
/*   Updated: 2024/10/09 19:01:03 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_up(t_game *game)
{
	if (game->map[game->player_y - 1][game->player_x] == '1')
		return ;
	game->map[game->player_y][game->player_x] = '0';
	game->player_y -= 1;
	game->map[game->player_y][game->player_x] = 'P';
	put_textures(game, 'w');
}

void	player_down(t_game *game)
{
	if (game->map[game->player_y + 1][game->player_x] == '1')
		return ;
	game->map[game->player_y][game->player_x] = '0';
	game->player_y += 1;
	game->map[game->player_y][game->player_x] = 'P';
	put_textures(game, 's');
}

void	player_left(t_game *game)
{
	if (game->map[game->player_y][game->player_x - 1] == '1')
		return ;
	game->map[game->player_y][game->player_x] = '0';
	game->player_x -= 1;
	game->map[game->player_y][game->player_x] = 'P';
	put_textures(game, 'a');
}

void	player_right(t_game *game)
{
	if (game->map[game->player_y][game->player_x + 1] == '1')
		return ;
	game->map[game->player_y][game->player_x] = '0';
	game->player_x += 1;
	game->map[game->player_y][game->player_x] = 'P';
	put_textures(game, 'd');
}

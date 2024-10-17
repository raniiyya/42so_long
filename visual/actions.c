/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:29:58 by rdavurov          #+#    #+#             */
/*   Updated: 2024/10/17 21:04:08 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static bool	check_money(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

void	player_up(t_game *game)
{
	if (game->map[game->player_y - 1][game->player_x] == '1')
		return ;
	if (game->map[game->player_y - 1][game->player_x] == 'E'
		&& !check_money(game) || game->map[game->player_y
		- 1][game->player_x] == 'M')
		close_game(game);
	if (game->player_y == game->exit_y && game->player_x == game->exit_x)
		game->map[game->player_y][game->player_x] = 'E';
	else
		game->map[game->player_y][game->player_x] = '0';
	game->player_y -= 1;
	game->map[game->player_y][game->player_x] = 'P';
	put_textures(game, 'w');
	game->moves++; // ADDED
}

void	player_down(t_game *game)
{
	if (game->map[game->player_y + 1][game->player_x] == '1')
		return ;
	if (game->map[game->player_y + 1][game->player_x] == 'E'
		&& !check_money(game) || game->map[game->player_y
		+ 1][game->player_x] == 'M')
		close_game(game);
	if (game->player_y == game->exit_y && game->player_x == game->exit_x)
		game->map[game->player_y][game->player_x] = 'E';
	else
		game->map[game->player_y][game->player_x] = '0';
	game->player_y += 1;
	game->map[game->player_y][game->player_x] = 'P';
	put_textures(game, 's');
	game->moves++; // ADDED
}

void	player_left(t_game *game)
{
	if (game->map[game->player_y][game->player_x - 1] == '1')
		return ;
	if (game->map[game->player_y][game->player_x - 1] == 'E'
		&& !check_money(game) || game->map[game->player_y][game->player_x
		- 1] == 'M')
		close_game(game);
	if (game->player_y == game->exit_y && game->player_x == game->exit_x)
		game->map[game->player_y][game->player_x] = 'E';
	else
		game->map[game->player_y][game->player_x] = '0';
	game->player_x -= 1;
	game->map[game->player_y][game->player_x] = 'P';
	put_textures(game, 'a');
	game->moves++; // ADDED
}

void	player_right(t_game *game)
{
	if (game->map[game->player_y][game->player_x + 1] == '1')
		return ;
	if (game->map[game->player_y][game->player_x + 1] == 'E'
		&& !check_money(game) || game->map[game->player_y][game->player_x
		+ 1] == 'M')
		close_game(game);
	if (game->player_y == game->exit_y && game->player_x == game->exit_x)
		game->map[game->player_y][game->player_x] = 'E';
	else
		game->map[game->player_y][game->player_x] = '0';
	game->player_x += 1;
	game->map[game->player_y][game->player_x] = 'P';
	put_textures(game, 'd');
	game->moves++; // ADDED
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:45:31 by rdavurov          #+#    #+#             */
/*   Updated: 2024/10/06 18:32:39 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	fill_textures(t_game *game)
{
	int	height;

	height = 50;
	game->textures.b = mlx_xpm_file_to_image(game->mlx,
			"../textures/background.xpm", &height, &height);
	game->textures.c = mlx_xpm_file_to_image(game->mlx, "../textures/money.xpm",
			&height, &height);
	game->textures.e = mlx_xpm_file_to_image(game->mlx, "../textures/house.xpm",
			&height, &height);
	game->textures.w = mlx_xpm_file_to_image(game->mlx, "../textures/wall.xpm",
			&height, &height);
    game->textures.pd = mlx_xpm_file_to_image(game->mlx, "../textures/krabs.xpm",
            &height, &height);
    game->textures.pl = mlx_xpm_file_to_image(game->mlx, "../textures/pleft.xpm",
            &height, &height);
    game->textures.pr = mlx_xpm_file_to_image(game->mlx, "../textures/pright.xpm",
            &height, &height);
    game->textures.pu = mlx_xpm_file_to_image(game->mlx, "../textures/pback.xpm",
            &height, &height);
    game->textures.m = mlx_xpm_file_to_image(game->mlx, "../textures/monster.xpm",
            &height, &height);
}

void	render_map(t_game *game)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	printf("%c", game->map[i][j]);
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			printf("%c", game->map[i][j]);
			j++;
		}
			i++;
	}
}

int	close_game(t_game *game)
{
	(void)game;
	exit(0);
	return (42);
}
int	handle_key_events(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_game(game);
	return (42);
}

void init_game(t_game *game)
{
    game->mlx = mlx_init();
    game->window = mlx_new_window(game->mlx, 900, 600, "so_long");


    fill_textures(game); // Ensure this is defined and working correctly
    render_map(game);    // Ensure this renders your map correctly

    mlx_hook(game->window, 17, 0, close_game, game);           // Handle window close event
    mlx_key_hook(game->window, handle_key_events, game);       // Handle key press events
    mlx_loop(game->mlx);                                       // Start the MLX loop
}
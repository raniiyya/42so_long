/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:45:31 by rdavurov          #+#    #+#             */
/*   Updated: 2024/10/17 21:03:45 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	fill_textures(t_game *game)
{
	int	height;

	height = 50;
	game->textures.b = mlx_xpm_file_to_image(game->mlx,
			"./textures/background.xpm", &height, &height);
	game->textures.c = mlx_xpm_file_to_image(game->mlx, "./textures/money.xpm",
			&height, &height);
	game->textures.e = mlx_xpm_file_to_image(game->mlx, "./textures/house.xpm",
			&height, &height);
	game->textures.w = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm",
			&height, &height);
	game->textures.pd = mlx_xpm_file_to_image(game->mlx, "./textures/krabs.xpm",
			&height, &height);
	game->textures.pl = mlx_xpm_file_to_image(game->mlx, "./textures/pleft.xpm",
			&height, &height);
	game->textures.pr = mlx_xpm_file_to_image(game->mlx,
			"./textures/pright.xpm", &height, &height);
	game->textures.pu = mlx_xpm_file_to_image(game->mlx, "./textures/pback.xpm",
			&height, &height);
	game->textures.m = mlx_xpm_file_to_image(game->mlx,
			"./textures/monster.xpm", &height, &height);
}

void free_textures(t_game *game)
{
	mlx_destroy_image(game->mlx, game->textures.b);
	mlx_destroy_image(game->mlx, game->textures.c);
	mlx_destroy_image(game->mlx, game->textures.e);
	mlx_destroy_image(game->mlx, game->textures.w);
	mlx_destroy_image(game->mlx, game->textures.pd);
	mlx_destroy_image(game->mlx, game->textures.pl);
	mlx_destroy_image(game->mlx, game->textures.pu);
	mlx_destroy_image(game->mlx, game->textures.pr);
	mlx_destroy_image(game->mlx, game->textures.m);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

int	close_game(t_game *game)
{
	(void)game;
	free_textures(game);
	free_map(game);
	mlx_destroy_display(game->mlx);
	mlx_destroy_window(game->mlx, game->window);
	free(game->mlx);
	exit(0);
	return (42);
}

int	handle_key_events(int keycode, t_game *game)
{
	char	*tmp; // ADDED

	if (keycode == 119)
		player_up(game);
	if (keycode == 115)
		player_down(game);
	if (keycode == 100)
		player_right(game);
	if (keycode == 97)
		player_left(game);
	if (keycode == 65307)
		close_game(game);
	tmp = ft_itoa(game->moves); // ADDED
	ft_putstr_fd(tmp, 1); // ADDED
	ft_putstr_fd("\n", 1); // ADDED
	free(tmp); // ADDED
	return (42);
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, map_width(game->map) * 50,
			map_height(game->map) * 50, "so_long");
	game->moves = 0; // ADDED
	fill_textures(game);
	put_textures(game, 'w');
	mlx_hook(game->window, 17, 0, close_game, game);
	mlx_hook(game->window, 2, 1L << 0, handle_key_events, game);
	mlx_loop(game->mlx);
}

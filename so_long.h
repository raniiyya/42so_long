/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:30:02 by rdavurov          #+#    #+#             */
/*   Updated: 2024/10/17 17:13:47 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <stdbool.h>
# include <fcntl.h>

typedef struct s_txt
{
	void	*b;
	void	*w;
	void	*c;
	void	*pu;
	void	*pd;
	void	*pl;
	void	*pr;
	void	*m;
	void	*e;
}			t_txt;

typedef struct s_game
{
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	char	**map;
	void	*mlx;
	void	*win;
	void	*window;
	t_txt	textures;
}			t_game;

char		**parse_map(char **map, char *file);
void		validate_map(t_game *game);
void		validate_chars(char **map);
void		validate_rect(char **map);
void		validate_path(t_game *game);
void		validate_border(char **map);
void		init_game(t_game *game);
void		put_textures(t_game *game, char key);
void		player_up(t_game *game);
void		player_down(t_game *game);
void		player_left(t_game *game);
void		player_right(t_game *game);
void		find_e(t_game *game);
int			map_height(char **map);
int			map_width(char **map);
int			close_game(t_game *game);

#endif
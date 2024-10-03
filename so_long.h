/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:30:02 by rdavurov          #+#    #+#             */
/*   Updated: 2024/10/03 09:59:43 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
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
	char	**map;
	void	*mlx;
	void	*window;
	t_txt	textures;
}			t_game;

char		**parse_map(char **map, char *file);
void		validate_map(char **map);
void		validate_chars(char **map);
void		validate_rect(char **map);
void		validate_path(char **map);
void		validate_border(char **map);
void		init_game(t_game *game);

#endif
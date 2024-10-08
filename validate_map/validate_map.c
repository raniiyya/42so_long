/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:43:46 by rdavurov          #+#    #+#             */
/*   Updated: 2024/10/09 19:07:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void validate_map(t_game *game)
{
    validate_chars(game->map);
    validate_rect(game->map);
    validate_border(game->map);
    validate_path(game);
}

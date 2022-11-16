/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:19:08 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/16 15:19:30 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

player_t	*create_player(mlx_t *mlx, char **map)
{
	player_t	*player;
	int			*pos;

	pos = ft_find_char_in_array(map, 'P');
	player = (player_t *)malloc(sizeof(player_t));
	player->texture = mlx_load_png(PLAYER);
	player->img = mlx_texture_to_image(mlx, player->texture);
	player->x = pos[0];
	player->y = pos[1];
	player->mlx = mlx;
	player->map = map;
	mlx_image_to_window(player->mlx, player->img, pos[0] * SIZE, pos[1] * SIZE);
	free(pos);
	return (player);
}

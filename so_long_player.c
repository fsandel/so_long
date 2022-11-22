/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:19:08 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/22 17:31:30 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player	*create_player(mlx_t *mlx, char **map)
{
	t_player	*player;
	int			*pos;

	pos = ft_find_char_in_array(map, 'P');
	player = (t_player *)malloc(sizeof(t_player));
	player->texture = mlx_load_png(DOWN);
	player->img = mlx_texture_to_image(mlx, player->texture);
	player->x = pos[0];
	player->y = pos[1];
	player->mlx = mlx;
	player->map = map;
	player->dir = 's';
	player->coin_switch = 0;
	player->coin = ft_array_count_chr(player->map, 'C');
	player->max_coins = ft_array_count_chr(player->map, 'C');
	mlx_image_to_window(player->mlx, player->img, pos[0] * SIZE, pos[1] * SIZE);
	free(pos);
	return (player);
}

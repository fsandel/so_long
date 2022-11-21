/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:24:47 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/21 09:40:26 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	gameloop(char *level)
{
	char			**map;
	mlx_t			*mlx;
	t_player		*player;

	map = map_load(level);
	mlx = mlx_init(ft_strlen(map[0]) * SIZE,
			ft_array_height(map) * SIZE, level, true);
	setup_floor(mlx, map);
	player = create_player(mlx, map);
	player->enemy = setup_enemy(player);
	setup_numbers(player);
	mlx_loop_hook(mlx, &movement_hook, player);
	mlx_loop_hook(mlx, &move_enemy, player);
	mlx_loop_hook(mlx, &pickup, player);
	mlx_loop_hook(mlx, &spike_hook, player);
	mlx_close_hook(mlx, &ft_error_void, "X");
	mlx_loop_hook(mlx, &won_game, player);
	mlx_loop(mlx);
	return ;
}

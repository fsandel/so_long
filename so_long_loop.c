/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:24:47 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/24 20:05:39 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void	gameloop(char *level)
{
	char			**map;
	mlx_t			*mlx;
	t_player		*player;

	map = map_load(level);
	mlx = create_window(map, level);
	setup_floor(mlx, map);
	player = create_player(mlx, map);
	player->enemy = setup_enemy(player);
	player->numbers = setup_numbers(player);
	add_loops(mlx, player);
	mlx_loop(mlx);
	return ;
}

mlx_t	*create_window(char **map, char *level)
{
	mlx_t	*mlx;
	int32_t	width;
	int32_t	height;

	width = ft_strlen(map[0]) * SIZE;
	height = ft_array_height(map) * SIZE;
	mlx = mlx_init(width, height, level, true);
	mlx_set_window_limit(mlx, width, height, width, height);
	return (mlx);
}

void	add_loops(mlx_t *mlx, t_player *player)
{
	mlx_loop_hook(mlx, &movement_hook, player);
	mlx_loop_hook(mlx, &move_enemy, player);
	mlx_loop_hook(mlx, &pickup, player);
	mlx_loop_hook(mlx, &spike_hook, player);
	mlx_close_hook(mlx, &ft_error_void, "X");
	mlx_loop_hook(mlx, &won_game, player);
	mlx_loop_hook(mlx, &coin_counter, player);
}

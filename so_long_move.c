/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:12:34 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/16 18:46:51 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	collision(char **map, player_t *player, char d)
{
	int	x;
	int	y;

	x = player->img->instances->x + SIZE / 2;
	y = player->img->instances->y + SIZE / 2;
	if (d == 'd')
		if (map[y / SIZE][(x + SPEED) / SIZE] == '1')
			return (1);
	if (d == 'a')
		if (map[y / SIZE][(x - SPEED) / SIZE] == '1')
			return (1);
	if (d == 'w')
		if (map[(y - SPEED) / SIZE][x / SIZE] == '1')
			return (1);
	if (d == 's')
		if (map[(y + SPEED) / SIZE][x / SIZE] == '1')
			return (1);
	return (0);
}

void	movement_hook(void *param)
{
	player_t	*player;

	player = (player_t *)param;
	if (mlx_is_key_down(player->mlx, MLX_KEY_D)
		&& !collision(player->map, player, 'd'))
		movement(player, 'd');
	if (mlx_is_key_down(player->mlx, MLX_KEY_A)
		&& !collision(player->map, player, 'a'))
		movement(player, 'a');
	if (mlx_is_key_down(player->mlx, MLX_KEY_W)
		&& !collision(player->map, player, 'w'))
		movement(player, 'w');
	if (mlx_is_key_down(player->mlx, MLX_KEY_S)
		&& !collision(player->map, player, 's'))
		movement(player, 's');
	if (mlx_is_key_down(player->mlx, MLX_KEY_ESCAPE))
		return (ft_error('e'));
}

void	movement(player_t *player, char c)
{
	if (c == 'd')
		player->img ->instances->x += SPEED;
	if (c == 'a')
		player->img ->instances->x -= SPEED;
	if (c == 'w')
		player->img ->instances->y -= SPEED;
	if (c == 's')
		player->img ->instances->y += SPEED;
	player->dis += SPEED;
	player->dis_m = player->dis / SIZE;
	player->x = (player->img->instances->x + SIZE / 2) / SIZE;
	player->y = (player->img->instances->y + SIZE / 2) / SIZE;
	player->field = player->map[player->y][player->x];
	step_counter(player);
}

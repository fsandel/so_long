/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_enemy_movement.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:20:25 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/21 09:48:32 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enemy(void *param)
{
	t_player	*player;
	t_enemy	*enemy;

	player = (t_player *)param;
	enemy = player->enemy;
	while (enemy)
	{
		enemy_collision(player, enemy);
		if (distance(player, enemy) < SIZE * 10 / RANGE)
			game_lost(player);
		if (enemy->move == 1)
			enemy->img->instances->x += ESPEED * enemy->turn;
		if (enemy->move == 2)
			enemy->img->instances->y += ESPEED * enemy->turn;
		enemy = enemy->next;
	}
}

void	enemy_collision(t_player *player, t_enemy *enemy)
{
	int		x;
	int		y;

	x = enemy->img->instances->x;
	y = enemy->img->instances->y;
	if (enemy->move == 1)
		if (player->map[y / SIZE][(x + ESPEED * enemy->turn
				+ SIZE * (2 + enemy->turn) / 4) / SIZE] == '1')
			enemy->turn *= (-1);
	if (enemy->move == 2)
		if (player->map[(y + ESPEED * enemy->turn + SIZE
				* (2 + enemy->turn) / 4) / SIZE][x / SIZE] == '1')
			enemy->turn *= (-1);
}

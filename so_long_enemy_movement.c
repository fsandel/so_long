/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_enemy_movement.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:20:25 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/22 15:41:43 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enemy(void *param)
{
	t_player	*player;
	t_enemy		*enemy;

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
	int		c1;
	int		c2;

	x = enemy->img->instances->x;
	y = enemy->img->instances->y;
	c1 = player->map[y / SIZE][(x + ESPEED * enemy->turn + SIZE
			* (2 + enemy->turn) / 4) / SIZE];
	c2 = player->map[(y + ESPEED * enemy->turn + SIZE
			* (2 + enemy->turn) / 4) / SIZE][x / SIZE];
	if (enemy->move == 1)
		if (ft_strchr("1SPE", c1))
			enemy_change_sprite(enemy);
	if (enemy->move == 2)
		if (ft_strchr("1SPE", c2))
			enemy_change_sprite(enemy);
}

void	enemy_change_sprite(t_enemy *enemy)
{
	enemy->turn *= (-1);
	mlx_delete_texture(enemy->tex);
	enemy->tex = mlx_load_png(choose_enemy_tex(enemy->move, enemy->turn));
	mlx_draw_texture(enemy->img, enemy->tex, 0, 0);
	return ;
}

char	*choose_enemy_tex(int move, int turn)
{
	if (move == 1 && turn == 1)
		return (ERIGHT);
	if (move == 1 && turn == -1)
		return (ELEFT);
	if (move == 2 && turn == 1)
		return (EDOWN);
	if (move == 2 && turn == -1)
		return (EUP);
	return (EDOWN);
}

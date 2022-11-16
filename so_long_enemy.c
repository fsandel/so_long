/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:37:01 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/16 20:55:09 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	spike_hook(void *param)
{
	player_t	*player;

	player = (player_t *)param;
	if (player->field == 'S')
		mlx_close_window(player->mlx);
}

void	enemy_add_back(enemy_t **head, enemy_t *new)
{
	if (!new)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	last_enemy(*head)->next = new;
}

enemy_t	*last_enemy(enemy_t *enemy)
{
	if (!enemy)
		return (NULL);
	while (enemy->next)
		enemy = enemy->next;
	return (enemy);
}

enemy_t	*new_enemy(int x, int y, player_t *player, int move)
{
	enemy_t	*enemy;

	enemy = (enemy_t *)malloc(sizeof(enemy_t));
	enemy->next = NULL;
	enemy->x = x;
	enemy->y = y;
	enemy->img = mlx_new_image(player->mlx, 32, 32);
	enemy->dis = RANGE * SIZE;
	enemy->move = move;
	enemy->turn = 1;
	if (move == 1)
		enemy->tex = mlx_load_png(HORI);
	else if (move == 2)
		enemy->tex = mlx_load_png(VERT);
	else if (move == 0)
		enemy->tex = mlx_load_png(SPIKE);
	else
		enemy->tex = mlx_load_png(MISS);
	return (enemy);
}

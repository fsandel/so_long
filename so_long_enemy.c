/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:37:01 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/17 17:20:24 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	spike_hook(void *param)
{
	player_t	*player;

	player = (player_t *)param;
	if (player->field == 'S')
		game_lost(player);
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

enemy_t	*setup_enemy(player_t *player)
{
	int		i;
	int		j;
	enemy_t	*enemy;

	enemy = NULL;
	j = 0;
	while (player->map[j])
	{
		i = 0;
		while (player->map[j][i])
		{
			if (player->map[j][i] == 'H')
				enemy_add_back(&enemy,
					new_enemy(i * SIZE, j * SIZE, player, 1));
			if (player->map[j][i] == 'V')
				enemy_add_back(&enemy,
					new_enemy(i * SIZE, j * SIZE, player, 2));
			i++;
		}
		j++;
	}
	enemy_on_map(player, enemy);
	return (enemy);
}

long	distance(player_t *player, enemy_t *enemy)
{
	long	output;
	long	ex;
	long	ey;
	long	px;
	long	py;

	ex = enemy->img->instances->x;
	ey = enemy->img->instances->y;
	px = player->img->instances->x;
	py = player->img->instances->y;
	output = dis(ex, ey, px, py);
	return (output);
}


void	enemy_on_map(player_t *player, enemy_t *enemy)
{
	while (enemy)
	{
		mlx_image_to_window(player->mlx, enemy->img, enemy->x, enemy->y);
		mlx_set_instance_depth(enemy->img->instances, 2);
		mlx_draw_texture(enemy->img, enemy->tex, 0, 0);
		enemy = enemy->next;
	}
}

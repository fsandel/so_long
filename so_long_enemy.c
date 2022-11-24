/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:37:01 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/22 19:20:46 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	spike_hook(void *param)
{
	t_player	*player;

	player = (t_player *)param;
	if (player->field == 'S')
		game_lost(player);
}

t_enemy	*new_enemy(int x, int y, t_player *player, int move)
{
	t_enemy	*enemy;

	enemy = (t_enemy *)malloc(sizeof(t_enemy));
	enemy->next = NULL;
	enemy->x = x;
	enemy->y = y;
	enemy->img = mlx_new_image(player->mlx, 32, 32);
	enemy->dis = RANGE * SIZE;
	enemy->move = move;
	enemy->turn = 1;
	if (move == 1)
		enemy->tex = mlx_load_png(ERIGHT);
	else if (move == 2)
		enemy->tex = mlx_load_png(EDOWN);
	else if (move == 0)
		enemy->tex = mlx_load_png(EDOWN);
	else
		enemy->tex = mlx_load_png(MISS);
	return (enemy);
}

t_enemy	*setup_enemy(t_player *player)
{
	int		i;
	int		j;
	t_enemy	*ene;

	ene = NULL;
	j = 0;
	while (player->map[j])
	{
		i = 0;
		while (player->map[j][i])
		{
			if (player->map[j][i] == 'H')
				enemy_add_back(&ene, new_enemy(i * SIZE, j * SIZE, player, 1));
			if (player->map[j][i] == 'V')
				enemy_add_back(&ene, new_enemy(i * SIZE, j * SIZE, player, 2));
			if (player->map[j][i] == 's')
				enemy_add_back(&ene, new_enemy(i * SIZE, j * SIZE, player, 0));
			i++;
		}
		j++;
	}
	enemy_on_map(player, ene);
	return (ene);
}

long	distance(t_player *player, t_enemy *enemy)
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

void	enemy_on_map(t_player *player, t_enemy *enemy)
{
	int	depth;

	depth = 3;
	while (enemy)
	{
		mlx_image_to_window(player->mlx, enemy->img, enemy->x, enemy->y);
		mlx_set_instance_depth(enemy->img->instances, depth++);
		mlx_draw_texture(enemy->img, enemy->tex, 0, 0);
		enemy = enemy->next;
	}
}

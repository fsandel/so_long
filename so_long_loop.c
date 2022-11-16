/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:24:47 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/16 21:02:45 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <math.h>

enemy_t	*setup_enemy(player_t *player);
void	enemy_on_map(player_t *player, enemy_t *enemy);
void	move_enemy(void *param);
void	enemy_collision(player_t *player, enemy_t *enemy);

void	gameloop(char *level)
{
	char			**map;
	mlx_t			*mlx;
	player_t		*player;

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

enemy_t	*setup_enemy(player_t *player)
{
	int	i;
	int	j;
	enemy_t	*enemy;

	enemy = NULL;
	j = 0;
	while (player->map[j])
	{
		i = 0;
		while(player->map[j][i])
		{
			if (player->map[j][i] == 'H')
				enemy_add_back(&enemy, new_enemy(i * SIZE, j * SIZE, player, 1));
			if (player->map[j][i] == 'V')
				enemy_add_back(&enemy, new_enemy(i * SIZE, j * SIZE, player, 2));
			i++;
		}
		j++;
	}
	enemy_on_map(player, enemy);
	return (enemy);
}

void	move_enemy(void *param)
{
	player_t	*player;
	enemy_t		*enemy;

	player = (player_t *)param;
	enemy = player->enemy;
	while (enemy)
	{
		enemy_collision(player, enemy);
		if (enemy->dis < SIZE * RANGE)
			mlx_close_window(player->mlx);
		enemy->dis = sqrt(((enemy->y - player->img->instances->y) * (enemy->y - player->img->instances->y)) + ((enemy->y - player->img->instances->y) * (enemy->y - player->img->instances->y)));
		if (enemy->move == 1)
			enemy->img->instances->x+=ESPEED * enemy->turn;
		if (enemy->move == 2)
			enemy->img->instances->y+=ESPEED * enemy->turn;
		enemy = enemy->next;
	}
	
}

void	enemy_collision(player_t *player, enemy_t *enemy)
{
	int	x;
	int	y;
	char	**map;

	map = player->map;
	x = enemy->img->instances->x;
	y = enemy->img->instances->y;
	if (enemy->move == 1)
		if (map[y / SIZE][(x + ESPEED * enemy->turn + SIZE / 2) / SIZE] == '1')
			enemy->turn *= (-1);
	if (enemy->move == 2)
		if (map[(y + ESPEED * enemy->turn + SIZE / 2) / SIZE][x / SIZE] == '1')
			enemy->turn *= (-1);
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

void	won_game(void *param)
{
	int			collectibles;
	player_t	*player;
	mlx_t		*mlx;

	player = (player_t *)param;
	if (player->field == 'E')
	{
		collectibles = ft_array_count_chr(player->map, 'C');
		if (collectibles == 0)
		{
			mlx = player->mlx;
			free(player);
			mlx_close_window(mlx);
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:12:34 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/22 17:15:38 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	collision(char **map, t_player *player, char d)
{
	int	x;
	int	y;
	int	col;

	col = SIZE * 1 / 3;
	x = player->img->instances->x + SIZE / 2;
	y = player->img->instances->y + SIZE / 2;
	if (d == 'd')
		if (map[y / SIZE][(x + SPEED + col) / SIZE] == '1')
			return (1);
	if (d == 'a')
		if (map[y / SIZE][(x - SPEED - col) / SIZE] == '1')
			return (1);
	if (d == 'w')
		if (map[(y - SPEED - col) / SIZE][x / SIZE] == '1')
			return (1);
	if (d == 's')
		if (map[(y + SPEED + col) / SIZE][x / SIZE] == '1')
			return (1);
	return (0);
}

void	movement_hook(void *param)
{
	t_player	*player;
	mlx_t		*mlx;
	char		**map;

	player = (t_player *)param;
	mlx = player->mlx;
	map = player->map;
	player->dir = player_direction(player);
	player_change_sprite(player);
	if (right(mlx) && !left(mlx) && !collision(map, player, 'd'))
		movement(player, 'd');
	if (left(mlx) && !right(mlx) && !collision(map, player, 'a'))
		movement(player, 'a');
	if (up(mlx) && !down(mlx) && !collision(map, player, 'w'))
		movement(player, 'w');
	if (down(mlx) && !up(mlx) && !collision(map, player, 's'))
		movement(player, 's');
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
	{
		free_stuff(player);
		return (ft_error('e'));
	}
}

void	movement(t_player *player, char c)
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

char	player_direction(t_player *player)
{
	mlx_t	*mlx;

	mlx = player->mlx;
	if (upright(mlx))
		return ('e');
	if (upleft(mlx))
		return ('q');
	if (downleft(mlx))
		return ('z');
	if (downright(mlx))
		return ('c');
	if (right(mlx) && !left(mlx))
		return ('d');
	if (left(mlx) && !right(mlx))
		return ('a');
	if (up(mlx) && !down(mlx))
		return ('w');
	if (down(mlx) && !up(mlx))
		return ('s');
	return (player->dir);
}

void	player_change_sprite(t_player *player)
{
	mlx_delete_texture(player->texture);
	if (player->dir == 'w')
			player->texture = mlx_load_png(UP);
	if (player->dir == 'q')
			player->texture = mlx_load_png(UPLEFT);
	if (player->dir == 'a')
			player->texture = mlx_load_png(LEFT);
	if (player->dir == 'z')
			player->texture = mlx_load_png(DOWNLEFT);
	if (player->dir == 's')
			player->texture = mlx_load_png(DOWN);
	if (player->dir == 'c')
			player->texture = mlx_load_png(DOWNRIGHT);
	if (player->dir == 'd')
			player->texture = mlx_load_png(RIGHT);
	if (player->dir == 'e')
			player->texture = mlx_load_png(UPRIGHT);
	mlx_draw_texture(player->img, player->texture, 0, 0);
}

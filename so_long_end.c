/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:46:59 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/22 18:42:11 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	won_game(void *param)
{
	int			collectibles;
	t_player	*player;
	mlx_t		*mlx;

	player = (t_player *)param;
	if (player->field == 'E')
	{
		collectibles = ft_array_count_chr(player->map, 'C');
		if (collectibles == 0)
		{
			mlx = player->mlx;
			free_stuff(player);
			mlx_close_window(mlx);
		}
	}
}

void	game_lost(t_player *player)
{
	int	*spawn;

	if (DIFF == 1)
	{
		mlx_close_window(player->mlx);
		free_stuff(player);
	}
	else
	{
		spawn = ft_find_char_in_array(player->map, 'P');
		player->img->instances->x = spawn[0] * SIZE;
		player->img->instances->y = spawn[1] * SIZE;
		free(spawn);
	}
}

void	free_stuff(t_player *player)
{
	t_enemy	*temp_enemy;

	free(player->map);
	free(player->img);
	free(player->texture);
	while (player->enemy)
	{
		temp_enemy = player->enemy->next;
		free(player->enemy->img);
		free(player->enemy->tex);
		free(player->enemy);
		player->enemy = temp_enemy;
	}
	free(player->numbers->n100->img);
	free(player->numbers->n100->tex);
	free(player->numbers->n10->img);
	free(player->numbers->n10->tex);
	free(player->numbers->n1->img);
	free(player->numbers->n1->tex);
}

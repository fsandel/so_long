/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:46:59 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/21 09:39:40 by fsandel          ###   ########.fr       */
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
			free(player);
			mlx_close_window(mlx);
		}
	}
}

void	game_lost(t_player *player)
{
	int	*spawn;

	if (DIFF == 1)
		mlx_close_window(player->mlx);
	else
	{
		spawn = ft_find_char_in_array(player->map, 'P');
		player->img->instances->x = spawn[0] * SIZE;
		player->img->instances->y = spawn[1] * SIZE;
		free(spawn);
	}
}

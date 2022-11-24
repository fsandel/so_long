/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_coin_counter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:18:47 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/22 19:09:11 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	coin_counter(void *param)
{
	t_player	*player;
	int			coins;

	player = (t_player *)param;
	coins = player->max_coins - player->coin;
	if (coins >= 99)
		return ;
	change_number_texture(player->numbers->c1, coins % 10);
	change_number_texture(player->numbers->c10, (coins / 10) % 10);
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_pickup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:23:32 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/21 09:42:36 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pickup(void *param)
{
	int			x;
	int			y;
	t_player	*player;

	player = (t_player *)param;
	x = player->x;
	y = player->y;
	if (player->field == 'C')
	{
		player->map[player->y][player->x] = '0';
		player->img->instances->z++;
		hide_coin(player->mlx, x, y);
	}
	return ;
}

void	hide_coin(mlx_t *mlx, int x, int y)
{
	mlx_image_t		*floor_img;
	mlx_texture_t	*floor_txt;

	floor_txt = mlx_load_png(FLOOR);
	floor_img = mlx_new_image(mlx, SIZE, SIZE);
	mlx_image_to_window(mlx, floor_img, x * SIZE, y * SIZE);
	mlx_set_instance_depth(floor_img->instances, 2);
	mlx_draw_texture(floor_img, floor_txt, 0, 0);
}

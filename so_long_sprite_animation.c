/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_sprite_animation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:02:35 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/22 16:21:41 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	portal(void *param)
{
	t_player		*player;
	mlx_texture_t	*tex;
	mlx_image_t		*img;
	int				*pos;

	player = (t_player *)param;
	if (player->coin == 0 && player->coin_switch == 0)
	{
		player->coin_switch = 1;
		pos = ft_find_char_in_array(player->map, 'E');
		tex = mlx_load_png(EXIT_ACTIVE);
		img = mlx_new_image(player->mlx, 32, 32);
		mlx_image_to_window(player->mlx, img, pos[0] * SIZE, pos[1] * SIZE);
		mlx_set_instance_depth(img->instances, 4);
		mlx_draw_texture(img, tex, 0, 0);
	}
}

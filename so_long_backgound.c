/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_backgound.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:22:38 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/16 20:37:53 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	setup_floor(mlx_t *mlx, char **map)
{
	int				i;
	int				j;
	mlx_image_t		*img;
	mlx_texture_t	*tex;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			img = mlx_new_image(mlx, SIZE, SIZE);
			tex = mlx_load_png(choose_texture(map[j][i]));
			mlx_image_to_window(mlx, img, i * SIZE, j * SIZE);
			mlx_set_instance_depth(img->instances, 1);
			mlx_draw_texture(img, tex, 0, 0);
			i++;
		}
		j++;
	}
}

char	*choose_texture(char c)
{
	if (c == '0')
		return (FLOOR);
	else if (c == '1')
		return (WALL);
	else if (c == 'P')
		return (SPAWN);
	else if (c == 'E')
		return (EXIT);
	else if (c == 'C')
		return (COIN);
	else if (c == 'S')
		return (SPIKE);
	else if (c == 'H')
		return (FLOOR);
	else if (c == 'V')
		return (FLOOR);
	else
		return (MISS);
	return (NULL);
}

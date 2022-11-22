/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_steps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:17:55 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/22 18:34:20 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*return_texture(int n);

void	step_counter(void *param)
{
	t_player	*player;
	int			dis;

	player = (t_player *)param;
	if (player->dis_m >= 999)
		return ;
	dis = player->dis_m;
	change_number_texture(player->numbers->n1, dis % 10);
	if (player->dis_m % 10 == 0)
		change_number_texture(player->numbers->n10, (dis / 10) % 10);
	if (player->dis_m % 100 == 0)
		change_number_texture(player->numbers->n100, (dis / 100) % 10);
	return ;
}

void	change_number_texture(t_number *number, int n)
{
	mlx_delete_texture(number->tex);
	number->tex = mlx_load_png(return_texture(n));
	mlx_draw_texture(number->img, number->tex, 0, 0);
}

t_numbers	*setup_numbers(t_player *player)
{
	t_numbers		*numbers;
	int				bottom;
	mlx_image_t		*img;
	mlx_texture_t	*tex;

	bottom = (ft_array_height(player->map) - 1) * SIZE;
	numbers = malloc(sizeof(t_numbers));
	numbers->n100 = create_number(player, 1 * SIZE, 0);
	numbers->n10 = create_number(player, 2 * SIZE, 0);
	numbers->n1 = create_number(player, 3 * SIZE, 0);
	numbers->c1 = create_number(player, 1 * SIZE, bottom);
	numbers->c10 = create_number(player, 0 * SIZE, bottom);
	numbers->c1_max = create_number(player, 3 * SIZE, bottom);
	change_number_texture(numbers->c1_max, player->max_coins % 10);
	numbers->c10_max = create_number(player, 2 * SIZE, bottom);
	change_number_texture(numbers->c10_max, (player->max_coins / 10) % 10);
	tex = mlx_load_png("./sprites/slash.png");
	img = mlx_new_image(player->mlx, SIZE, SIZE);
	mlx_image_to_window(player->mlx, img, SIZE * 44 / 32, bottom);
	mlx_set_instance_depth(img->instances, 6);
	mlx_draw_texture(img, tex, 0, 0);
	return (numbers);
}

t_number	*create_number(t_player *player, int x, int y)
{
	t_number	*number;

	number = malloc(sizeof(t_number));
	number->img = mlx_new_image(player->mlx, SIZE, SIZE);
	number->tex = mlx_load_png(NUM0);
	mlx_image_to_window(player->mlx, number->img, x, y);
	mlx_set_instance_depth(number->img->instances, 4);
	mlx_draw_texture(number->img, number->tex, 0, 0);
	return (number);
}

char	*return_texture(int n)
{
	if (n == 1)
		return (NUM1);
	if (n == 2)
		return (NUM2);
	if (n == 3)
		return (NUM3);
	if (n == 4)
		return (NUM4);
	if (n == 5)
		return (NUM5);
	if (n == 6)
		return (NUM6);
	if (n == 7)
		return (NUM7);
	if (n == 8)
		return (NUM8);
	if (n == 9)
		return (NUM9);
	else
		return (NUM0);
}

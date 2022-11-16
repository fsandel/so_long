/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_steps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:17:55 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/16 15:18:15 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*choose_number_image(player_t *player, int n)
{
	if (n == 1)
		return (player->num->n1);
	if (n == 2)
		return (player->num->n2);
	if (n == 3)
		return (player->num->n3);
	if (n == 4)
		return (player->num->n4);
	if (n == 5)
		return (player->num->n5);
	if (n == 6)
		return (player->num->n6);
	if (n == 7)
		return (player->num->n7);
	if (n == 8)
		return (player->num->n8);
	if (n == 9)
		return (player->num->n9);
	else
		return (player->num->n0);
}

void	step_counter(void *param)
{
	mlx_image_t	*img1;
	mlx_image_t	*img2;
	mlx_image_t	*img3;
	player_t	*player;

	player = (player_t *)param;
	if (player->dis_m >= 999)
		return ;
	img1 = choose_number_image(player, player->dis_m % 10);
	img2 = choose_number_image(player, (player->dis_m / 10) % 10);
	img3 = choose_number_image(player, (player->dis_m / 100) % 10);
	mlx_image_to_window(player->mlx, img1, 3 * SIZE, 2);
	mlx_image_to_window(player->mlx, img2, 2 * SIZE, 2);
	mlx_image_to_window(player->mlx, img3, 1 * SIZE, 2);
	return ;
}

void	setup_numbers(player_t *player)
{
	num_t	*num;

	num = malloc(sizeof(num_t));
	num->n0 = mlx_texture_to_image(player->mlx, mlx_load_png(NUM0));
	num->n1 = mlx_texture_to_image(player->mlx, mlx_load_png(NUM1));
	num->n2 = mlx_texture_to_image(player->mlx, mlx_load_png(NUM2));
	num->n3 = mlx_texture_to_image(player->mlx, mlx_load_png(NUM3));
	num->n4 = mlx_texture_to_image(player->mlx, mlx_load_png(NUM4));
	num->n5 = mlx_texture_to_image(player->mlx, mlx_load_png(NUM5));
	num->n6 = mlx_texture_to_image(player->mlx, mlx_load_png(NUM6));
	num->n7 = mlx_texture_to_image(player->mlx, mlx_load_png(NUM7));
	num->n8 = mlx_texture_to_image(player->mlx, mlx_load_png(NUM8));
	num->n9 = mlx_texture_to_image(player->mlx, mlx_load_png(NUM9));
	player->num = num;
	return ;
}

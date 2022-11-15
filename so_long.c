/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:06:11 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/15 18:54:01 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void		movement_hook(void *param);
void		setup_floor(mlx_t *mlx, char **map);
mlx_image_t	*player_func(mlx_t *mlx, int depth);
player_t	*create_player(mlx_t *mlx, char **map);
int			wall(char **map, player_t *player, char d);
void		hide_coin(mlx_t *mlx, int x, int y);
void		pickup(void *param);
void		won_game(void *param);
void		step_counter(void *param);
void		setup_numbers(player_t *player);
mlx_image_t	*choose_number_image(player_t *player, int n);
char		*choose_texture(char c);
void		check_all(int argc, char *argv[]);
void	movement(player_t *player, char c);

int	main(int argc, char *argv[])
{
	char			**map;
	mlx_t			*mlx;
	mlx_texture_t	*texture;
	player_t		*player;

	check_all(argc, argv);
	map = map_load(argv[1]);
	mlx = mlx_init(ft_strlen(map[0]) * SIZE,
			ft_array_height(map) * SIZE, argv[1], true);
	setup_floor(mlx, map);
	player = create_player(mlx, map);
	setup_numbers(player);
	mlx_loop_hook(mlx, &movement_hook, player);
	mlx_loop_hook(mlx, &pickup, player);
	mlx_loop_hook(mlx, &won_game, player);
	//mlx_loop_hook(mlx, &step_counter, player);
	mlx_loop(mlx);
	mlx_delete_image(mlx, player->img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

void	check_all(int argc, char *argv[])
{
	char	**map;

	check_arg_count(argc);
	map = map_load(argv[1]);
	map_check_rect(map);
	map_check_walls(map);
	map_check_layout(map);
	flood(map);
	free(map);
	ft_printf("This map is playable\n");
}

void	pickup(void *param)
{
	int			x;
	int			y;
	player_t	*player;

	player = (player_t *)param;
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

void	won_game(void *param)
{
	int			collectibles;
	player_t	*player;

	param = (player_t *)param;
	if (player->field == 'E')
	{
		collectibles = ft_array_count_chr(player->map, 'C');
		if (collectibles == 0)
			exit(0);
	}
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

int	wall(char **map, player_t *player, char d)
{
	int	x;
	int	y;
	
	x = player->img->instances->x + SIZE / 2;
	y = player->img->instances->y + SIZE / 2;
	if (d == 'd')
		if (map[y / SIZE][(x + SPEED) / SIZE] == '1')
			return (1);
	if (d == 'a')
		if (map[y / SIZE][(x - SPEED) / SIZE] == '1')
			return (1);
	if (d == 'w')
		if (map[(y - SPEED) / SIZE][x / SIZE] == '1')
			return (1);
	if (d == 's')
		if (map[(y + SPEED) / SIZE][x / SIZE] == '1')
			return (1);
	return (0);
}

void	movement_hook(void *param)
{
	player_t	*player;

	player = (player_t *)param;
	if (mlx_is_key_down(player->mlx, MLX_KEY_D)
		&& !wall(player->map, player, 'd'))
		movement(player, 'd');
	if (mlx_is_key_down(player->mlx, MLX_KEY_A)
		&& !wall(player->map, player, 'a'))
		movement(player, 'a');
	if (mlx_is_key_down(player->mlx, MLX_KEY_W)
		&& !wall(player->map, player, 'w'))
		movement(player, 'w');
	if (mlx_is_key_down(player->mlx, MLX_KEY_S)
		&& !wall(player->map, player, 's'))
		movement(player, 's');
	if (mlx_is_key_down(player->mlx, MLX_KEY_ESCAPE))
		return(ft_error('e'));
	
}

void	movement(player_t *player, char c)
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

player_t	*create_player(mlx_t *mlx, char **map)
{
	player_t	*player;
	int			*pos;

	pos = ft_find_char_in_array(map, 'P');
	player = (player_t *)malloc(sizeof(player_t));
	player->texture = mlx_load_png(PLAYER);
	player->img = mlx_texture_to_image(mlx, player->texture);
	player->x = pos[0];
	player->y = pos[1];
	player->mlx = mlx;
	player->map = map;
	mlx_image_to_window(player->mlx, player->img, pos[0] * SIZE, pos[1] * SIZE);
	free(pos);
	return (player);
}

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
	if (c == '1')
		return (WALL);
	if (c == 'P')
		return (SPAWN);
	if (c == 'E')
		return (EXIT);
	if (c == 'C')
		return (COIN);
	return (NULL);
}

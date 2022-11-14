/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:06:11 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/14 15:50:11 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void		hook(mlx_key_data_t keydata, void *param);
state_t		setup_floor(state_t *state);
void		movement(mlx_t *mlx, mlx_image_t *img, int speed);
mlx_image_t	*player_func(mlx_t *mlx, int depth);
state_t		*setup_textures(state_t *state);
state_t	*tex_to_img(state_t *state);
mlx_image_t	*choose_images(char c, state_t *state);
player_t	*create_player(mlx_t *mlx, char **map);
int		wall(char **map, player_t *player, char d);









int	main(int argc, char *argv[])
{
	char **map;
	argc = 0;
	// check_arg_count(argc);
	// map = map_load(argv[1]);
	// map_check_rect(map);
	// map_check_walls(map);
	// map_check_layout(map);
	// flood(map);
	map = map_load(argv[1]);
	// ft_putarray_fd(map, 1);
	//return (free(map), 0);

	mlx_t			*mlx;
	state_t			*state;

	state = (state_t *)malloc(sizeof(state_t *));
	
	state->mlx = mlx_init(ft_strlen(map[0]) * SIZE, ft_array_height(map) * SIZE, argv[1], true);
	setup_textures(state);
	setup_floor(state);
	//state->player = create_player(state->mlx, state->map);

	//mlx_key_hook(state->mlx, &hook, state->player);
	mlx_loop(state->mlx);
	//mlx_delete_image(state->mlx, state->player->img);
	mlx_terminate(state->mlx);
	return (EXIT_SUCCESS);
}

int		wall(char **map, player_t *player, char d)
{
	int	x;
	int	y;
	
	x = player->img->instances->x + SIZE / 2;
	y = player->img->instances->y + SIZE / 2;

	if (d == 'd')
			if (map[y / SIZE][(x + SPEED)/SIZE] == '1')
				return (1);
	if (d == 'a')
			if (map[y / SIZE][(x - SPEED)/SIZE] == '1')
				return (1);
	if (d == 'w')
			if (map[(y - SPEED) / SIZE][x / SIZE] == '1')
				return (1);
	if (d == 's')
			if (map[(y + SPEED) / SIZE][x / SIZE] == '1')
				return (1);
	return (0);
}

void	hook(mlx_key_data_t keydata, void *param)
{
	player_t	*player;

	player = (player_t *)param;
	if (mlx_is_key_down(player->mlx, MLX_KEY_D) && !wall(player->map, player, 'd'))
		player->img ->instances->x += SPEED;
	if (mlx_is_key_down(player->mlx, MLX_KEY_A) && !wall(player->map, player, 'a'))
		player->img ->instances->x -= SPEED;
	if (mlx_is_key_down(player->mlx, MLX_KEY_W) && !wall(player->map, player, 'w'))
		player->img ->instances->y -= SPEED;
	if (mlx_is_key_down(player->mlx, MLX_KEY_S) && !wall(player->map, player, 's'))
		player->img ->instances->y += SPEED;
	if (mlx_is_key_down(player->mlx, MLX_KEY_ESCAPE))
		return(ft_error('e'));
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
	mlx_image_to_window(player->mlx, player->img, pos[0]*SIZE, pos[1]*SIZE);
	free(pos);
	return (player);
}

state_t	*setup_textures(state_t *state)
{
	state->t_coin = mlx_load_png(COIN);
	state->t_exit = mlx_load_png(EXIT);
	state->t_floor = mlx_load_png(FLOOR);
	state->t_player = mlx_load_png(PLAYER);
	state->t_spawn = mlx_load_png(SPAWN);
	state->t_wall = mlx_load_png(WALL);
	return (state);
}

state_t	*tex_to_img(state_t *state)
{
	state->i_coin = mlx_texture_to_image(state->mlx, state->t_coin);
	state->i_exit = mlx_texture_to_image(state->mlx, state->t_exit);
	state->i_floor = mlx_texture_to_image(state->mlx, state->t_floor);
	state->i_spawn = mlx_texture_to_image(state->mlx, state->t_spawn);
	state->i_wall = mlx_texture_to_image(state->mlx, state->t_wall);
	state->i_player = mlx_texture_to_image(state->mlx, state->t_player);
	return (state);
}


state_t	setup_floor(state_t *state)
{
	int	i;
	int	j;
	mlx_image_t	*img;

	j = 0;
	while (state->map[j])
	{
		i = 0;
		while (state->map[j][i])
		{
			if (state->map[j][i] == 'C')
				mlx_image_to_window(state->mlx, state->i_floor, i * SIZE, j * SIZE);
			img = choose_images(state->map[j][i], state);
			mlx_image_to_window(state->mlx, img, i * SIZE, j * SIZE);
			i++;
		}
		j++;
	}
}

mlx_image_t	*choose_images(char c, state_t *state)
{
	if (c == '0')
		return(state->i_floor);
	if (c == '1')
		return (state->i_wall);	
	if (c == 'P')
		return (state->i_player);
	if (c == 'E')
		return (state->i_exit);
	if (c == 'C')
		return (state->i_coin);
	return (NULL);
}

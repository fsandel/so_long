/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:06:11 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/14 17:35:44 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void		movement_hook(mlx_key_data_t keydata, void *param);
void		setup_floor(mlx_t *mlx, char **map, tex_t *textures);
void		movement(mlx_t *mlx, mlx_image_t *img, int speed);
mlx_image_t	*player_func(mlx_t *mlx, int depth);
tex_t		*setup_textures(void);
img_t		*tex_to_img(mlx_t *mlx, tex_t *textures);
mlx_image_t	*choose_images(char c, img_t *images);
player_t	*create_player(mlx_t *mlx, char **map);
int		wall(char **map, player_t *player, char d);

void	pickup(player_t *player);








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

	tex_t			*textures;
	mlx_texture_t	*texture;
	player_t		*player;

	mlx = mlx_init(ft_strlen(map[0]) * SIZE, ft_array_height(map) * SIZE, argv[1], true);
	textures = setup_textures();
	setup_floor(mlx, map, textures);
	player = create_player(mlx, map);
	mlx_key_hook(mlx, &movement_hook, player);
	mlx_loop_hook(mlx, &pickup, player);
	mlx_loop(mlx);
	mlx_delete_image(mlx, player->img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

void	pickup(player_t *player)
{
	int	x = player->x;
	int	y = player->y;

	if (player->field == 'C')
	{
		player->map[player->y][player->x] = '0';
		player->collect++;
	}
	printf("%c\n", player->field);

	//printf("%d %d \n", player->x ,player->y);
	return ;
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

void	movement_hook(mlx_key_data_t keydata, void *param)
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
	player->x = (player->img->instances->x + SIZE / 2) / SIZE ;
	player->y = (player->img->instances->y + SIZE / 2) / SIZE ;
	player->field = player->map[player->y][player->x]; 
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
	player->field = 'P';
	player->collect = 0;
	mlx_image_to_window(player->mlx, player->img, pos[0]*SIZE, pos[1]*SIZE);
	free(pos);
	return (player);
}

tex_t	*setup_textures(void)
{
	tex_t *textures;

	textures = malloc(sizeof(tex_t));
	textures->coin = mlx_load_png(COIN);
	textures->exit = mlx_load_png(EXIT);
	textures->floor = mlx_load_png(FLOOR);
	textures->player = mlx_load_png(PLAYER);
	textures->spawn = mlx_load_png(SPAWN);
	textures->wall = mlx_load_png(WALL);
	return (textures);
}

img_t	*tex_to_img(mlx_t *mlx, tex_t *textures)
{
	img_t	*images;

	images = malloc(sizeof(img_t));
	images->coin = mlx_texture_to_image(mlx, textures->coin);
	images->exit = mlx_texture_to_image(mlx, textures->exit);
	images->floor = mlx_texture_to_image(mlx, textures->floor);
	images->spawn = mlx_texture_to_image(mlx, textures->spawn);
	images->wall = mlx_texture_to_image(mlx, textures->wall);
	images->player = mlx_texture_to_image(mlx, textures->player);
	return (images);
}


void	setup_floor(mlx_t *mlx, char **map, tex_t *textures)
{
	int	i;
	int	j;
	img_t	*images;
	mlx_image_t	*img;
	
	images = tex_to_img(mlx, textures);
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'C')
				mlx_image_to_window(mlx, images->floor, i * SIZE, j * SIZE);
			img = choose_images(map[j][i], images);
			mlx_image_to_window(mlx, img, i * SIZE, j * SIZE);
			i++;
		}
		j++;
	}
}

mlx_image_t	*choose_images(char c, img_t *images)
{
	if (c == '0')
		return(images->floor);
	if (c == '1')
		return (images->wall);	
	if (c == 'P')
		return (images->spawn);
	if (c == 'E')
		return (images->exit);
	if (c == 'C')
		return (images->coin);
	return (NULL);
}

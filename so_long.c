/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:06:11 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/11 15:45:26 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void		hook(mlx_key_data_t keydata, void *param);
int			setup_floor(mlx_t *mlx, char **map, tex_t *textures);
void		movement(mlx_t *mlx, mlx_image_t *img, int speed);
mlx_image_t	*player_func(mlx_t *mlx, int depth);
tex_t		*setup_textures(void);
img_t		*tex_to_img(mlx_t *mlx, tex_t *textures);
void		choose_images(char c, int x, int y, mlx_t *mlx, img_t *images);







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

	mlx_t		*mlx;
	int			depth;
	tex_t		*textures;
	img_t		*images;

	//images = NULL;
	//mlx_texture_t	*texture;


	mlx = mlx_init(ft_strlen(map[0]) * SIZE, ft_array_height(map) * SIZE, argv[1], true);

	//textures = setup_textures();
	//depth = setup_floor(mlx, map, textures);
	images->player= player_func(mlx, 1);

	mlx_key_hook(mlx, &hook, images->player);
	mlx_loop(mlx);
	//mlx_delete_image(mlx, images->player);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

void	hook(mlx_key_data_t keydata, void *param)
{
	mlx_image_t	*img;

	img = param;
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		img ->instances[0].x += 5;
	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		img ->instances[0].x -= 5;
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		img ->instances[0].y -= 5;
	if (keydata.key == MLX_KEY_S && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		img ->instances[0].y += 5;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		return(ft_error('e'));

}

mlx_image_t	*player_func(mlx_t *mlx, int depth)
{
	mlx_image_t		*player_img;
	mlx_texture_t	*player_tex;

	player_tex = mlx_load_png(PLAYER);
	player_img = mlx_texture_to_image(mlx, player_tex);
	mlx_image_to_window(mlx, player_img, 30, 30);
	mlx_set_instance_depth(player_img->instances, depth + 1);
	return (player_img);
}

tex_t	*setup_textures(void)
{
	tex_t *textures;

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

	images->coin = mlx_texture_to_image(mlx, textures->coin);
	images->exit = mlx_texture_to_image(mlx, textures->exit);
	images->floor = mlx_texture_to_image(mlx, textures->floor);
	images->spawn = mlx_texture_to_image(mlx, textures->spawn);
	images->wall = mlx_texture_to_image(mlx, textures->wall);
	images->player = mlx_texture_to_image(mlx, textures->player);
	return (images);
}
void	movement(mlx_t *mlx, mlx_image_t *img, int speed)
{
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		img->instances->y += speed;
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		img->instances->y -= speed;
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		img->instances->x += speed;
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		img->instances->x -= speed;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		return(ft_error('e'));
}

int	setup_floor(mlx_t *mlx, char **map, tex_t *textures)
{
	int	i;
	int	j;
	img_t	*images;
	
	images = tex_to_img(mlx, textures);
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			choose_images(map[j][i], SIZE * i, SIZE * j, mlx, images);
			i++;
		}
		j++;
	}
	return (i * j);
}

void	choose_images(char c, int x, int y, mlx_t *mlx, img_t *images)
{
	if (c == '0')
	{
		mlx_image_to_window(mlx, images->floor, x, y);
		mlx_set_instance_depth(images->floor->instances, 0);
		return ;
	}
	if (c == '1')
	{
		mlx_image_to_window(mlx, images->wall, x, y);
		mlx_set_instance_depth(images->wall->instances, 0);
		return ;
	}	
	if (c == 'P')
	{
		mlx_image_to_window(mlx, images->spawn, x, y);
		mlx_set_instance_depth(images->spawn->instances, 0);
		return ;
	}
	if (x == 'E')
	{
		mlx_image_to_window(mlx, images->exit, x, y);
		mlx_set_instance_depth(images->exit->instances, 0);
		return ;
	}
	if (x == 'C')
	{
		mlx_image_to_window(mlx, images->coin, x, y);
		mlx_set_instance_depth(images->coin->instances, 0);
		return ;
	}
}

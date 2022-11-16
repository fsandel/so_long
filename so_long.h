/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:06:48 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/16 20:04:17 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# include "lib/MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include "textures.h"
# include "settings.h"
# include "so_long_structs.h"

# define WIDTH 256
# define HEIGHT 256

char		*ft_strjoin_free(char *first, char *second);
int			ft_array_height(char **array);
int			ft_array_count_chr(char **array, char c);
void		ft_putarray_fd(char **array, int fd);
int			*ft_find_char_in_array(char **array, char c);

char		**map_load(char *path);
void		map_check_rect(char **map);
void		map_check_walls(char **map);
void		map_check_minsize(char **map);
void		map_check_layout(char **map);

void		flood(char **map);
char		**flood_algorithm(char **map, int x, int y);
char		**flood_increase(char **map, int x, int y, char *str);
void		flood_exit(char **map);

void		ft_error_free(char c, char **map);
void		ft_error(char c);
void		ft_error_void(void *param);

void		map_check_name(char *name);
void		check_arg_count(int argc);
void		map_check(char *argv);

void		check_all(int argc, char *argv[]);
void		check_one_level(char *level);

int			collision(char **map, player_t *player, char d);
void		movement_hook(void *param);
void		movement(player_t *player, char c);

mlx_image_t	*choose_number_image(player_t *player, int n);
void		step_counter(void *param);
void		setup_numbers(player_t *player);

player_t	*create_player(mlx_t *mlx, char **map);

void		setup_floor(mlx_t *mlx, char **map);
char		*choose_texture(char c);

void		pickup(void *param);
void		hide_coin(mlx_t *mlx, int x, int y);

void		gameloop(char *level);
void		won_game(void *param);

void		enemy_add_back(enemy_t **head, enemy_t *new);
enemy_t		*last_enemy(enemy_t *enemy);
enemy_t		*new_enemy(int x, int y, player_t *player, int move);
void		spike_hook(void *param);


#endif

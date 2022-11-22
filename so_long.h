/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:06:48 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/22 18:40:48 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# include "lib/MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include "textures.h"
# include "settings.h"
# include "so_long_structs.h"

void		setup_floor(mlx_t *mlx, char **map);
char		*choose_texture(char c);

void		map_check_rect(char **map);
void		map_check_walls(char **map);
void		map_check_minsize(char **map);
void		map_check_layout(char **map);
void		map_check_badchar(char **map, char *str);

void		check_all(int argc, char *argv[]);
void		check_one_level(char *level);
void		map_check_size(char **map);

int			up(mlx_t *mlx);
int			down(mlx_t *mlx);
int			left(mlx_t *mlx);
int			right(mlx_t *mlx);

int			upright(mlx_t *mlx);
int			upleft(mlx_t *mlx);
int			downleft(mlx_t *mlx);
int			downright(mlx_t *mlx);

void		won_game(void *param);
void		game_lost(t_player *player);
void		free_stuff(t_player *player);

void		enemy_add_back(t_enemy **head, t_enemy *new);
t_enemy		*last_enemy(t_enemy *enemy);

void		move_enemy(void *param);
void		enemy_collision(t_player *player, t_enemy *enemy);
void		enemy_change_sprite(t_enemy *enemy);
char		*choose_enemy_tex(int move, int turn);

void		spike_hook(void *param);
t_enemy		*new_enemy(int x, int y, t_player *player, int move);
t_enemy		*setup_enemy(t_player *player);
long		distance(t_player *player, t_enemy *enemy);
void		enemy_on_map(t_player *player, t_enemy *enemy);

void		ft_error_free(char c, char **map);
void		ft_error(char c);
void		ft_error_void(void *param);

void		flood(char **map);
void		flood_algorithm(char **map, int x, int y, char *str);
void		flood_exit(char **map);
void		flood_prep_map(char **map);

void		gameloop(char *level);

void		map_check_name(char *name);
void		check_arg_count(int argc);
char		*create_long_map(int fd);
void		map_check_empty_line(char *long_map);
char		**map_load(char *path);

long		square(long nb);
long		dis(long x1, long y1, long x2, long y2);

int			collision(char **map, t_player *player, char d);
void		movement_hook(void *param);
void		movement(t_player *player, char c);
char		player_direction(t_player *player);
void		player_change_sprite(t_player *player);

void		pickup(void *param);
void		hide_coin(mlx_t *mlx, int x, int y);

t_player	*create_player(mlx_t *mlx, char **map);

mlx_image_t	*choose_number_image(t_player *player, int n);
void		step_counter(void *param);
t_numbers	*setup_numbers(t_player *player);
t_number	*create_number(t_player *player, int x, int y);
void		change_number_texture(t_number *number, int n);
char		*return_texture(int n);

char		*ft_strjoin_free(char *first, char *second);
int			ft_array_height(char **array);
int			ft_array_count_chr(char **array, char c);
void		ft_putarray_fd(char **array, int fd);
int			*ft_find_char_in_array(char **array, char c);
char		*ft_strtrim_free(char *str, char *del);

void		portal(void *param);

void		coin_counter(void *param);

#endif

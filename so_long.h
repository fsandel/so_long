/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:06:48 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/09 20:31:31 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# include "lib/MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"

# define WIDTH 256
# define HEIGHT 256

char	*ft_strjoin_free(char *first, char *second);
int		ft_array_height(char **array);

char	**map_load(char *path);
void	map_check_rect(char **map);
void	map_check_walls(char **map);
void	map_check_minsize(char **map);
void	map_exit(int player, int collect, int exit);
void	map_increase_counter(char **map, int player, int collect, int exit, int toggle);
void	map_check_layout(char **map, int toggle);
void	map_exit_setup(int player, int collect, int exit);
void	map_exit_unreachable(int player, int collect, int exit);


char	**flood(char **map);
int		player_x(char **map);
int		player_y(char **map);
char	**flood_algorithm(char **map, int x, int y);
char	**flood_increase(char **map, int x, int y, char *str);






void	ft_error(char c);



#endif


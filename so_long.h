/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:06:48 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/11 15:22:34 by fsandel          ###   ########.fr       */
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

# define WIDTH 256
# define HEIGHT 256

typedef struct tex
{
	mlx_texture_t	*player;
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*spawn;
	mlx_texture_t	*coin;
	mlx_texture_t	*exit;
}	tex_t;

typedef struct img
{
	mlx_image_t	*player;
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*spawn;
	mlx_image_t	*coin;
	mlx_image_t	*exit;
}	img_t;

char	*ft_strjoin_free(char *first, char *second);
int		ft_array_height(char **array);
int		ft_array_count_chr(char **array, char c);
void	ft_putarray_fd(char **array, int fd);
int		*ft_find_char_in_array(char **array, char c);

char	**map_load(char *path);
void	map_check_rect(char **map);
void	map_check_walls(char **map);
void	map_check_minsize(char **map);
void	map_check_layout(char **map);

void	flood(char **map);
char	**flood_algorithm(char **map, int x, int y);
char	**flood_increase(char **map, int x, int y, char *str);
void	flood_exit(char **map);

void	ft_error_free(char c, char **map);
void	ft_error(char c);

void	map_check_name(char *name);
void	check_arg_count(int argc);
void	map_check(char *argv);

#endif

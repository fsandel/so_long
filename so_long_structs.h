/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:47:08 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/21 16:27:03 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_STRUCTS_H
# define SO_LONG_STRUCTS_H

# include "so_long.h"

/*
*move 2 = vertikal
*move 1 = horizontal
*move 0 = standing
*/
typedef struct enemy
{
	int				x;
	int				y;
	struct enemy	*next;
	mlx_image_t		*img;
	mlx_texture_t	*tex;
	int				dis;
	int				move;
	int				turn;
}	t_enemy;

typedef struct number
{
	mlx_image_t		*img;
	mlx_texture_t	*tex;
}	t_number;

typedef struct numbers
{
	t_number	*n1;
	t_number	*n10;
	t_number	*n100;
}	t_numbers;

typedef struct player
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_texture_t	*texture;
	int				x;
	int				y;
	char			**map;
	char			field;
	int				collect;
	int				dis;
	int				dis_m;
	t_enemy			*enemy;
	t_numbers		*numbers;
}	t_player;

#endif

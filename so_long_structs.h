/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:47:08 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/21 09:55:00 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_STRUCTS_H
# define SO_LONG_STRUCTS_H

# include "so_long.h"

typedef struct num
{
	mlx_image_t	*n0;
	mlx_image_t	*n1;
	mlx_image_t	*n2;
	mlx_image_t	*n3;
	mlx_image_t	*n4;
	mlx_image_t	*n5;
	mlx_image_t	*n6;
	mlx_image_t	*n7;
	mlx_image_t	*n8;
	mlx_image_t	*n9;
}	t_num;

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
	t_num			*num;
	t_enemy			*enemy;
}	t_player;

#endif

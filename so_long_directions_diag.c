/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_directions_diag.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:02:20 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/22 10:06:54 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	upright(mlx_t *mlx)
{
	if (up(mlx) && right(mlx) && !down(mlx) && !left(mlx))
		return (1);
	else
		return (0);
}

int	upleft(mlx_t *mlx)
{
	if (up(mlx) && !right(mlx) && !down(mlx) && left(mlx))
		return (1);
	else
		return (0);
}

int	downleft(mlx_t *mlx)
{
	if (!up(mlx) && !right(mlx) && down(mlx) && left(mlx))
		return (1);
	else
		return (0);
}

int	downright(mlx_t *mlx)
{
	if (!up(mlx) && right(mlx) && down(mlx) && !left(mlx))
		return (1);
	else
		return (0);
}

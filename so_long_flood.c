/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_flood.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:19:43 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/17 22:09:58 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood(char **map)
{
	int	*p;

	flood_prep_map(map);
	p = ft_find_char_in_array(map, 'P');
	flood_algorithm(map, p[1], p[0], "HVEC0P");
	free(p);
	flood_exit(map);
}

void	flood_algorithm(char **map, int x, int y, char *str)
{
	if (ft_strchr(str, map[x + 1][y]))
	{
		map[x + 1][y] = '1';
		flood_algorithm(map, x + 1, y, str);
	}
	if (ft_strchr(str, map[x - 1][y]))
	{
		map[x - 1][y] = '1';
		flood_algorithm(map, x - 1, y, str);
	}
	if (ft_strchr(str, map[x][y + 1]))
	{
		map[x][y + 1] = '1';
		flood_algorithm(map, x, y + 1, str);
	}
	if (ft_strchr(str, map[x][y - 1]))
	{
		map[x][y - 1] = '1';
		flood_algorithm(map, x, y - 1, str);
	}
}

void	flood_exit(char **map)
{
	int	exit;
	int	collect;

	exit = ft_array_count_chr(map, 'E');
	collect = ft_array_count_chr(map, 'C');
	if (exit == 1)
		return (ft_error_free('u', map));
	if (collect > 0)
		return (ft_error_free('U', map));
}

void	flood_prep_map(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'S')
				map[j][i] = '1';
			i++;
		}
		j++;
	}
}

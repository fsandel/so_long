/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_flood.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:19:43 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/16 18:44:16 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood(char **map)
{
	int	p_x;
	int	p_y;
	int	*p;

	p = ft_find_char_in_array(map, 'P');
	p_x = p[0];
	p_y = p[1];
	free(p);
	map = flood_algorithm(map, p_x, p_y);
	flood_exit(map);
}

char	**flood_algorithm(char **map, int x, int y)
{
	flood_increase(map, x, y, "CE");
	if (map[x][y - 1] == '0')
	{
		map[x][y - 1] = '1';
		flood_algorithm(map, x, y - 1);
	}
	if (map[x][y + 1] == '0')
	{
		map[x][y + 1] = '1';
		flood_algorithm(map, x, y + 1);
	}
	if (map[x - 1][y] == '0')
	{
		map[x - 1][y] = '1';
		flood_algorithm(map, x - 1, y);
	}
	if (map[x + 1][y] == '0')
	{
		map[x + 1][y] = '1';
		flood_algorithm(map, x + 1, y);
	}
	return (map);
}

char	**flood_increase(char **map, int x, int y, char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (map[x + 1][y] == str[i])
			map[x + 1][y]++;
		if (map[x - 1][y] == str[i])
			map[x - 1][y]++;
		if (map[x][y + 1] == str[i])
			map[x][y + 1]++;
		if (map[x][y - 1] == str[i])
			map[x][y - 1]++;
		i++;
	}
	return (map);
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

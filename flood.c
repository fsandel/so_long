/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:19:43 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/09 21:59:27 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**flood(char **map)
{
	int	p_x;
	int	p_y;

	p_x = player_x(map);
	p_y = player_y(map);
	map = flood_algorithm(map, p_x, p_y);
	map_check_layout(map, 1);
	return (map);
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

int	player_x(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'P')
				return (i);
			i++;
		}
		j++;
	}
	return (ft_error('?'), 0);
}

int	player_y(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'P')
				return (j);
			i++;
		}
		j++;
	}
	return (ft_error('?'), 0);
}

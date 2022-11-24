/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:23:26 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/24 14:39:31 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_check_rect(char **map)
{
	int	i;
	int	len_compare;
	int	len;

	len_compare = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		len = ft_strlen(map[i++]);
		if (len != len_compare)
			return (ft_error_free('r', map));
	}
}

void	map_check_walls(char **map)
{
	int	i;
	int	j;
	int	height;
	int	weidth;

	weidth = ft_strlen(map[0]) - 1;
	height = ft_array_height(map) - 1;
	i = 0;
	j = 0;
	while (map[0][i + 1])
	{
		if ((map[0][i] != '1') || (map[height][i] != '1'))
			return (ft_error_free('w', map));
		i++;
	}
	while (map[j])
	{
		if ((map[j][0] != '1') || (map[j][weidth] != '1'))
			return (ft_error_free('w', map));
		j++;
	}
}

void	map_check_minsize(char **map)
{
	if (!map)
		return (ft_error_free('s', map));
	if (ft_array_height(map) <= 3)
		return (ft_error_free('s', map));
	if (ft_strlen(map[0]) <= 3)
		return (ft_error_free('s', map));
}

void	map_check_layout(char **map)
{
	int	player;
	int	collect;
	int	exit;

	player = ft_array_count_chr(map, 'P');
	collect = ft_array_count_chr(map, 'C');
	exit = ft_array_count_chr(map, 'E');
	if (player != 1)
		return (ft_error_free('p', map));
	if (exit != 1)
		return (ft_error_free('e', map));
	if (collect < 1)
		return (ft_error_free('c', map));
}

void	map_check_badchar(char **map, char *str)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (!ft_strchr(str, map[j][i]))
				ft_error_free('b', map);
			i++;
		}
		j++;
	}
}

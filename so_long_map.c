/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:46:06 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/16 18:43:56 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_load(char *path)
{
	int		fd;
	char	**map;
	char	*long_map;
	char	*temp;
	char	*full_path;

	map_check_name(path);
	full_path = ft_strjoin("./maps/", path);
	fd = open(full_path, O_RDONLY);
	if (fd < 0)
		return (free(full_path), ft_error('N'), NULL);
	free(full_path);
	temp = get_next_line(fd);
	long_map = ft_strdup(temp);
	while (temp)
	{
		free(temp);
		temp = get_next_line(fd);
		if (!temp)
			break ;
		long_map = ft_strjoin_free(long_map, temp);
	}
	map = ft_split(long_map, '\n');
	return (free (long_map), map);
}

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
	if (ft_array_height(map) < 3)
		return (ft_error_free('s', map));
	if (ft_strlen(map[0]) < 3)
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
	if (collect < 0)
		return (ft_error_free('c', map));
}

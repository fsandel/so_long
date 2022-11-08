/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:46:06 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/08 20:08:59 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_load(char *path)
{
	int		fd;
	char	**map;
	char	*long_map;
	char	*temp;

	fd = open(path, O_RDONLY);
	temp = get_next_line(fd);
	long_map = ft_strdup(temp);
	while (temp)
	{
		free(temp);
		temp = get_next_line(fd);
		if (!temp)
			break ;
		long_map = ft_strjoin_free(long_map, "!");
		long_map = ft_strjoin_free(long_map, temp);
	}
	map = ft_split(long_map, '!');
	free (long_map);
	return (map);
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
			return (ft_error('r'));
	}
}

void	map_check_walls(char **map)
{
	int	i;
	int	j;
	int	height;
	int	weidth;

	weidth = ft_strlen(map[0]) - 2;
	height = ft_array_height(map) - 1;
	i = 0;
	j = 0;
	while (map[0][i + 1])
	{
		if ((map[0][i] != '1') || (map[height][i] != '1'))
			return(ft_error('w'));
		i++;
	}
	while (map[j])
	{
		if ((map[j][0] != '1') || (map[j][weidth] != '1'))
			return (ft_error('w'));
		j++;
	}
}

void	map_check_minsize(char **map)
{
	if (!map)
		return (ft_error('s'));
	if (ft_array_height(map) < 3)
		return (ft_error('s'));
	if (ft_strlen(map[0]) < 3)
		return (ft_error('s'));
}

void	map_check_layout(char **map)
{
	int	player;
	int collect;
	int	exit;

	player = 0;
	collect = 0;
	exit = 0;
	map_increase_counter(map, player, collect, exit);
}

void	map_increase_counter(char **map, int player, int collect, int exit)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j + 1] != NULL)
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'P')
				player++;
			else if (map[j][i] == 'C')
				collect++;
			else if (map[j][i] == 'E')
				exit++;
			i++;
		}
		j++;
	}
	map_exit(player, collect, exit);
}

void	map_exit(int player, int collect, int exit)
{
	if (player != 1)
		return (ft_error('p'));
	if (exit != 1)
		return (ft_error('e'));
	if (collect < 0)
		return (ft_error('c'));
}

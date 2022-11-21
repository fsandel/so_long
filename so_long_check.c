/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 09:30:03 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/21 17:45:55 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_all(int argc, char *argv[])
{
	int		level;
	int		i;

	if (BONUS == 0)
	{
		check_arg_count(argc);
		check_one_level(argv[1]);
	}
	else
	{
		level = ft_array_height(argv);
		i = 1;
		while (i < level)
		{
			check_one_level(argv[i]);
			i++;
		}
		ft_printf("All %d maps are playable\n", level - 1);
	}
}

void	check_one_level(char *level)
{
	char	**map;

	map = map_load(level);
	map_check_rect(map);
	map_check_badchar(map, "01PCEHVS");
	map_check_walls(map);
	map_check_layout(map);
	map_check_size(map);
	flood(map);
	free(map);
	ft_printf("%s is playable\n", level);
}

void	map_check_size(char **map)
{
	// if (ft_strlen(map[0]) > 74)
	// 	ft_error('S');
	printf("%d\n", ft_array_height(map));
	if (ft_array_height(map) > 1080 / SIZE)
		ft_error('S');
}

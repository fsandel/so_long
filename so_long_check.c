/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 09:30:03 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/22 15:40:00 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_all(int argc, char *argv[])
{
	char	**map;

	check_arg_count(argc);
	map = map_load(argv[1]);
	map_check_rect(map);
	map_check_badchar(map, "01PCEHVSs");
	map_check_walls(map);
	map_check_layout(map);
	map_check_size(map);
	flood(map);
	free(map);
	ft_printf("%s is playable\n", argv[1]);
}

void	map_check_size(char **map)
{
	if (ft_strlen(map[0]) > 74)
		ft_error('S');
	printf("%d\n", ft_array_height(map));
	if (ft_array_height(map) > 1080 / SIZE)
		ft_error('S');
}

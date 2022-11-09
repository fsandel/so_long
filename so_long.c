/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:06:11 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/09 22:00:07 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	char	**map;
	int		i;

	map = map_load(argv[1]);
	map_check_rect(map);
	map_check_walls(map);
	map_check_layout(map, 0);
	map = flood(map);
	i = 0;
	while (map[i])
	{
		printf("%s", map[i++]);
	}
	argc += 1;
	return (0);
}

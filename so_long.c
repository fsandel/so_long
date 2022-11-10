/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:06:11 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/10 19:08:48 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	char **map;

	check_arg_count(argc);
	map = map_load(argv[1]);
	map_check_rect(map);
	map_check_walls(map);
	map_check_layout(map);
	flood(map);
	map = map_load(argv[1]);
	ft_putarray_fd(map, 1);
	return (free(map), 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:41:50 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/10 19:04:34 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_check_name(char *name)
{
	char	*ptr;

	ptr = ft_strrchr(name, '.');
	if (!ptr)
		return (ft_error('n'));
	if (ft_strncmp(ptr, ".ber", 5))
		return (ft_error('n'));
}

void	check_arg_count(int argc)
{
	if (argc != 2)
		return (ft_error('c'));
}

void	map_check(char *argv)
{
	char **map;

	map = map_load(argv);
	map_check_rect(map);
	map_check_walls(map);
	map_check_layout(map);
	flood(map);
}

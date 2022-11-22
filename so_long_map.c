/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:46:06 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/22 15:36:55 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_load(char *path)
{
	int		fd;
	char	**map;
	char	*long_map;
	char	*full_path;

	map_check_name(path);
	full_path = ft_strjoin("./maps/", path);
	fd = open(full_path, O_RDONLY);
	if (fd < 0)
		return (free(full_path), ft_error('N'), NULL);
	free(full_path);
	long_map = create_long_map(fd);
	map_check_empty_line(long_map);
	map = ft_split(long_map, '\n');
	return (free(long_map), map);
}

char	*create_long_map(int fd)
{
	char	*temp;
	char	*long_map;

	temp = get_next_line(fd);
	if (!temp)
		ft_error('E');
	long_map = ft_strdup(temp);
	while (temp)
	{
		free(temp);
		temp = get_next_line(fd);
		if (!temp)
			break ;
		long_map = ft_strjoin_free(long_map, temp);
	}
	return (long_map);
}

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

void	map_check_empty_line(char *long_map)
{
	if (ft_strnstr(long_map, "\n\n", ft_strlen(long_map)))
		ft_error('l');
	if (long_map[0] == '\n')
		ft_error('l');
	if (ft_strlen(long_map) > 2)
		if (long_map[ft_strlen(long_map) - 2] == '\n')
			ft_error('l');
}

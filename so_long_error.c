/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:30:54 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/10 18:41:24 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_error_exit(char *str);

void	ft_error_free(char c, char **map)
{
	free(map);
	if (c == 'r')
		ft_error_exit("not rectangular");
	else if (c == 'w')
		ft_error_exit("wall missing");
	else if (c == 's')
		ft_error_exit("map to smool");
	else if (c == 'p')
		ft_error_exit("you need exactly one player");
	else if (c == 'e')
		ft_error_exit("you need exactly one exit");
	else if (c == 'c')
		ft_error_exit("you need at least one collectible");
	else if (c == 'u')
		ft_error_exit("unreachable exit");
	else if (c == 'U')
		ft_error_exit("unreachable collectible");
	else
		ft_error_exit("random exit");
}

void	ft_error(char c)
{
	if (c == 'n')
		ft_error_exit("name is wrong");
	if (c == 'N')
		ft_error_exit("no map with this name found");
	if (c == 'c')
		ft_error_exit("wrong amount of arguments");
	else
		ft_error_exit("random exit");
}

static void	ft_error_exit(char *str)
{
	write(2, str, ft_strlen(str));
	exit(0);
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

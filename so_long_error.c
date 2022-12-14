/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:30:54 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/22 19:26:26 by fsandel          ###   ########.fr       */
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
	else if (c == 'b')
		ft_error_exit("there is a bad char");
	else if (c == 'C')
		ft_error_exit("more than MAXCOINS coins");
	else if (c == 'E')
		ft_error_exit("more than MAXENEMIES enemies");
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
		ft_error_exit("wrong amount of arguments, 1 argument");
	if (c == 'e')
		ft_error_exit("You hit the escape key");
	if (c == 'X')
		ft_error_exit("You closed the window");
	if (c == 'l')
		ft_error_exit("There is a empty line in the map");
	if (c == 'S')
		ft_error_exit("map is too big");
	if (c == 'E')
		ft_error_exit("empty map file");
	else
		ft_error_exit("random exit");
}

static void	ft_error_exit(char *str)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(0);
}

void	ft_error_void(void *param)
{
	char	*str;

	str = (char *)param;
	if (str[0] == 'X')
		ft_error_exit("You closed the window");
	else
		ft_error_exit("random exit");
}

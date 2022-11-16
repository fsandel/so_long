/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:06:11 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/16 18:42:54 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	check_all(argc, argv);
	if (BONUS == 0)
		gameloop(argv[1]);
	else
	{
		while (i < argc)
		{
			gameloop(argv[i]);
			i++;
		}
	}
	return (EXIT_SUCCESS);
}

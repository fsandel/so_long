/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:10:01 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/08 18:32:22 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin_free(char *first, char *second)
{
	char	*output;

	if (!first)
	{
		first = ft_calloc(1, 1);
		if (!first)
			return (NULL);
	}
	output = ft_strjoin(first, second);
	free(first);
	return (output);
}

int	ft_array_height(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

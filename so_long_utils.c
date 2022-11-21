/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:10:01 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/21 17:53:53 by fsandel          ###   ########.fr       */
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

int	ft_array_count_chr(char **array, char c)
{
	int	i;
	int	j;
	int	counter;

	j = -1;
	counter = 0;
	while (array[++j])
	{
		i = 0;
		while (array[j][i])
			if (array[j][i++] == c)
				counter ++;
	}
	return (counter);
}

void	ft_putarray_fd(char **array, int fd)
{
	int	j;

	j = 0;
	while (array[j])
	{
		ft_putendl_fd(array[j], fd);
		j++;
	}
}

int	*ft_find_char_in_array(char **array, char c)
{
	int	i;
	int	j;
	int	*output;

	output = (int *)ft_calloc(2 + 1, sizeof(int));
	j = 0;
	while (array[j])
	{
		i = 0;
		while (array[j][i])
		{
			if (array[j][i] == c)
			{
				output[0] = i;
				output[1] = j;
				return (output);
			}
			i++;
		}
		j++;
	}
	return (NULL);
}

char	*ft_strtrim_free(char *str, char *del)
{
	char	*output;

	output = ft_strtrim(str, del);
	free(str);
	return (output);
}

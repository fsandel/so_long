/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:02:11 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/17 14:44:53 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

long	square(long nb)
{
	return (nb * nb);
}

long	dis(long x1, long y1, long x2, long y2)
{
	long	output;
	long	x;
	long	y;
	long	temp;

	x = x1 - x2;
	y = y1 - y2;
	temp = square(x) + square(y);
	output = sqrt(temp);
	return (output);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_enemy_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:16:55 by fsandel           #+#    #+#             */
/*   Updated: 2022/11/21 10:22:01 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_add_back(t_enemy **head, t_enemy *new)
{
	if (!new)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	last_enemy(*head)->next = new;
}

t_enemy	*last_enemy(t_enemy *enemy)
{
	if (!enemy)
		return (NULL);
	while (enemy->next)
		enemy = enemy->next;
	return (enemy);
}

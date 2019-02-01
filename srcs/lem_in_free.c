/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 13:37:55 by pmasson           #+#    #+#             */
/*   Updated: 2019/02/01 13:49:01 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lem_in_free_rooms(t_parse **rooms)
{
	t_parse	*tmp;

	tmp = *rooms;
	if (rooms == NULL || *rooms == NULL)
		return ;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		free(*rooms);
		*rooms = NULL;
		*rooms = tmp;
	}
	return ;
}

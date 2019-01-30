/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_next_room.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 17:28:32 by erli              #+#    #+#             */
/*   Updated: 2019/01/30 11:00:40 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_algo.h"

int				lem_in_next_room(t_lem_in_data *data, int n_room, int *index)
{
	if (*index >= data->n_room)
		return (-1);
	else
	{
		while (*index < data->n_room)
		{
			if (LI_CONNECTED(data, n_room, *index)
				&& !(LI_FLOW_CAPPED(data, n_room, *index)))
			{
				*index += 1;
				return (*index - 1);
			}
			*index += 1;
		}
		return (-1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_reset_reached.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:47:19 by erli              #+#    #+#             */
/*   Updated: 2019/02/09 16:48:02 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lem_in_reset_reached(t_lem_in_data *data)
{
	int i;

	i = 0;
	while (i < data->n_room)
	{
		data->reached[i] = -1;
		i++;
	}
}
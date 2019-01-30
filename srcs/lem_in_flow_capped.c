/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_flow_capped.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 13:20:32 by erli              #+#    #+#             */
/*   Updated: 2019/01/30 18:21:53 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_algo.h"
#include "libft.h"

int		lem_in_flow_capped(t_lem_in_data *data, int room)
{
	int i;
	int	total;

	i = 0;
	total = 0;
	while (i < data->n_room)
	{
		if (LI_FLOW(data, room, i))
			total += (LI_POS_FLOW(data, room, i) ? 1 : 0);
		i++;
	}
	if (total == 1)
		return (1);
	return (0);
}

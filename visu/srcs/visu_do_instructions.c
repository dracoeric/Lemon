/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_do_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:52:21 by erli              #+#    #+#             */
/*   Updated: 2019/02/07 15:43:28 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		visu_do_instructions(t_visu_data *data, char *line)
{
	int i;
	int	ant_id;

	i = 0;
	while (line[i] != '\0')
	{
		if (visu_get_ant_id(data, line, &ant_id, &i) < 0
			|| visu_manage_ants(data, line, ant_id, &i) < 0)
			return (-1);
		if (line[i] == ' ')
			i++;
	}
	visu_draw_anthill(data);
	return (1);
}

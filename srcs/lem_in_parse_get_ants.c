/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_parse_get_ants.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:08:00 by pmasson           #+#    #+#             */
/*   Updated: 2019/02/01 14:08:45 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int             lem_in_parse_get_ants(char *line, t_lem_in_data *data)
{
	int i;

	i = 1;
	if (line[0] != '+' && ft_isdigit(line[0]) == 0)
		return (ft_msg_int(2, "Abort, wrong input (nb ants)", -1));
	while (line[i] != '\0' && ft_isdigit(line[i]) == 1)
		i++;
	if (line[i] == '\0')
		lem_in_atoi(line, &(data->n_ant));
	else
		return (ft_msg_int(2, "Abort, wrong input (nb ants)", -1));
	if (data->n_ant == 0)
		return (ft_msg_int(2, "Abort, wrong input (nb ants)", -1));
	return (1);
}

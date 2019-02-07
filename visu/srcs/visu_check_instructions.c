/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_check_instructions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:01:12 by erli              #+#    #+#             */
/*   Updated: 2019/02/07 16:11:27 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static	int	visu_check_real_room(t_visu_data *data, char *line, int i, int len)
{
	char	name[len + 1];

	ft_strncpy(name, line + i, len);
	name[len] = '\0';
	if (visu_rec_search(data->anthill, name, 0, data->n_room - 1) < 0)
		return (-1);
	return (1);
}

int			visu_check_instructions(t_visu_data *data, char *line)
{
	int i;
	int i_start;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i++] != 'L')
			return (ft_msg_int(2, "Wrong instruction\n", -1));
		while (ft_isdigit(line[i]))
			i++;
		if (line[i++] != '-')
			return (ft_msg_int(2, "Wrong instruction\n", -1));
		i_start = i;
		while (line[i] != ' ' || line[i] != '\0')
			i++;
		if (visu_check_real_room(data, line, i_start, i - i_start) < 0)
			return (ft_msg_int(2, "Room doesn't exist.\n", -1));
	}
	return (1);
}

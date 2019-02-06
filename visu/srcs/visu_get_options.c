/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_get_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 11:35:17 by pmasson           #+#    #+#             */
/*   Updated: 2019/02/06 18:49:57 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int	visu_get_options(int argc, char **argv, t_visu_data *data)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] != '-')
			return (ft_msg_int(2, "Abort, wrong option", -1));
		else if (argv[i][1] == 'o' && argv[i][2] == '\0')
			data->options = (data->options | 1);
		else if (argv[i][1] == 's' && argv[i][2] == '\0')
			data->options = (data->options | 1 << 1);
		else if (argv[i][1] == 'g' && argv[i][2] == '\0')
			data->options = (data->options | 1 << 2);
		else if (argv[i][1] == 'p' && argv[i][2] == '\0')
			data->options = (data->options | 1 << 3);
		else
			return (ft_msg_int(2, "Abort, wrong option.\n", -1));
		i++;
	}
	return (1);
}

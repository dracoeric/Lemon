/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintestparse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 13:58:57 by pmasson           #+#    #+#             */
/*   Updated: 2019/02/05 17:06:57 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_lem_in_data *data;

	data = NULL;
	data = lem_in_parse(argc, argv);
	if (data == 0 || lem_in_algo(data) == -1)
		write(1, "Error\n", 6);
	if (data != 0)
		lem_in_free_data(&data);
	return (0);
}

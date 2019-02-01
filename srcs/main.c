/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintestparse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 13:58:57 by pmasson           #+#    #+#             */
/*   Updated: 2019/02/01 18:37:21 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(int argc, char **argv)
{
	t_lem_in_data *data;

	data = NULL;
	data = lem_in_parse(argc, argv);
	lem_in_print_data(data);
//	lem_in_algo(data);
	if (data != NULL)
		lem_in_free_data(&data);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 13:58:57 by pmasson           #+#    #+#             */
/*   Updated: 2019/02/06 19:03:54 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int	main(int argc, char **argv)
{
	t_visu_data *data;

	data = NULL;
	data = visu_parse(argc, argv);
	visu_print_data(data);
	if (data != NULL)
		visu_free_data(&data);
	return (0);
}

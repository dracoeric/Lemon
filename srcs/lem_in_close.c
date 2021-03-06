/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 16:14:38 by erli              #+#    #+#             */
/*   Updated: 2019/02/05 17:12:53 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			lem_in_close(void *arg)
{
	t_lem_in_data *data;

	if (arg == 0)
		return (0);
	data = (t_lem_in_data *)arg;
	lem_in_free_data(&data);
	exit(0);
	return (0);
}

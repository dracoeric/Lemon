/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_print_total_step.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:03:13 by erli              #+#    #+#             */
/*   Updated: 2019/02/04 16:14:56 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		lem_in_print_total_step(t_lem_in_data *data, int steps)
{
	ft_putstr_fd("\n==========Total Steps==========\n", data->fd);
	ft_putstr_fd("Moving ", data->fd);
	ft_putnbr_fd(data->n_ant, data->fd);
	ft_putstr_fd(" ants from room ", data->fd);
	ft_putstr_fd((data->anthill)[data->start], data->fd);
	ft_putstr_fd("\nto room ", data->fd);
	ft_putstr_fd((data->anthill)[data->end], data->fd);
	ft_putstr_fd("\nin ", data->fd);
	ft_putnbr_fd(steps, data->fd);
	ft_putstr_fd(" steps.\n", data->fd);
}

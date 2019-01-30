/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_test_opti.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 15:20:13 by erli              #+#    #+#             */
/*   Updated: 2019/01/30 19:00:33 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in_algo.h"
#include "mlxadd.h"

static	void	lem_in_get_steps(t_lem_in_data *data, char **matrix,
						int *tab, int n_paths)
{
	int	index;
	int	steps;
	int	room;
	int	i;
	int	i_tab;

	index = 0;
	i_tab = 0;
	while (i_tab < n_paths && index < data->n_room)
	{
		while (!(((matrix[start][index] >> 1) & 3) == 3))
			index++;
		room = index;
		steps = 1;
		while (room != data->end)
		{
			i = 0;
			while (!(((matrix[room][i] >> 1) & 3) == 3))
				i++;
			steps++;
			room = i;
		}
		tab[i_tab] = steps;
		i_tab++;
	}
}

static	int		lem_in_eval_steps(t_lem_in_data *data, int *tab, int n_paths)
{
	double	a;
	double	b;
	int		delta;
	int		n_steps;

	a = 1.0;
	b = tab[0] - 1;
	delta = tab[1] - tab[0];
	if (data->n_ant < delta
}

int				lem_in_test_opti(t_lem_in_data *data, int n_paths)
{
	int		steps_old[n_paths - 1];
	int		steps_new[n_paths];
	int		n_steps;

	lem_in_get_steps(data, data->matrix_old, steps_old, n_paths - 1);
	lem_in_get_steps(data, data->matrix, steps_new, n_path);
	n_steps = lem_in_eval_steps(data, steps_old, n_paths - 1);
	if (n_steps < lem_in_eval_steps(data, steps_new, n_paths))
		return (1);
	return (0);
}

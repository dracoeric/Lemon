/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_draw_graph.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 12:48:45 by erli              #+#    #+#             */
/*   Updated: 2019/02/01 13:00:17 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	t_colour	lem_in_colour(int z)
{
	int	mod;

	mod = z % 11;
	if (mod == 0)
		return (mlx_str_to_colour("0x00421e0f"));
	else if (mod == 1)
		return (mlx_str_to_colour("0x0019071a"));
	else if (mod == 2)
		return (mlx_str_to_colour("0x0019071a"));
	else if (mod == 3)
		return (mlx_str_to_colour("0x0019071a"));
	else if (mod == 4)
		return (mlx_str_to_colour("0x0019071a"));
	else if (mod == 5)
		return (mlx_str_to_colour("0x0019071a"));
	else if (mod == 6)
		return (mlx_str_to_colour("0x0019071a"));
	else if (mod == 7)
		return (mlx_str_to_colour("0x0019071a"));
	else if (mod == 8)
		return (mlx_str_to_colour("0x0019071a"));
	else if (mod == 9)
		return (mlx_str_to_colour("0x0019071a"));
	else
		return (mlx_str_to_colour("0x0019071a"));
}

void				lem_in_draw_graph(t_lem_in_data *data, t_mapcoord a,
						t_mapcoord b)
{
	int				dxy[2];
	int				dpxy[2];
	t_pixcoord		pix[2];
	t_mlxwin_ptr	mlxwin[1];

	dpxy[0] = 1;
	dpxy[1] = 1;
	dxy[0] = (WIDTH - 3 * GRAPH_BORDER * dpxy[0]) / data->n_ant;
	dxy[1] = (HEIGHT - 3 * GRAPH_BORDER * dpxy[1]) / data->max_steps;
	while (dxy[0] == 0)
		dxy[0] = (WIDTH - 3 * GRAPH_BORDER * ++(dpxy[0])) / data->n_ant;
	while (dxy[1] == 0)
		dxy[1] = (HEIGHT - 3 * GRAPH_BORDER * ++(dpxy[1])) / data->n_ant;
	mlxwin->mlx_ptr = data->mlx_ptr;
	mlxwin->win_ptr = data->win_ptr;
	pix[0].px = GRAPH_BORDER + a.mx * dxy[0] / dpxy[0];
	pix[0].py = HEIGHT - GRAPH_BORDER - a.my * dxy[1] / dpxy[1];
	pix[0].pz = a.mz;
	pix[1].px = GRAPH_BORDER + b.mx * dxy[0] / dpxy[0];
	pix[1].py = HEIGHT - GRAPH_BORDER - b.my * dxy[1] / dpxy[1];
	pix[1].pz = b.mz;
	mlx_line_put(mlxwin, pix, pix + 1, &lem_in_colour);
}

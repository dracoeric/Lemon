/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_draw_anthill.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 10:43:02 by erli              #+#    #+#             */
/*   Updated: 2019/02/08 12:08:23 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static	void	visu_get_pix(t_room room, t_pixcoord *pix, int colour,
					int delta)
{
	pix->px = (room.x + 1) * delta;
	pix->py = (room.y + 1) * delta;
	pix->pz = colour;
}

static	void	visu_draw_links(t_visu_data *data, int delta)
{
	t_pixcoord	a[1];
	t_pixcoord	b[1];
	int			i;
	int			j;
	int			pheromon;

	i = 0;
	while (i < data->n_room)
	{
		j = i + 1;
		while (j < data->n_room)
		{
			if ((data->matrix[i][j] & 1) == 1)
			{
				pheromon = (data->matrix[i][j] >> 1);
				visu_get_pix(data->anthill[i], a, pheromon, delta);
				visu_get_pix(data->anthill[j], b, pheromon, delta);
				visu_draw_line(data, a, b);
			}
			j++;
		}
		i++;
	}
}

static	void	visu_draw_rooms(t_visu_data *data, int delta)
{
	t_pixcoord	pix[1];
	int			i;
	int			colour;

	i = 0;
	while (i < data->n_room)
	{
		colour = 0;
		if (i == data->start)
			colour = START_COLOUR;
		else if (i == data->end)
			colour = END_COLOUR;
		visu_get_pix(data->anthill[i], pix, colour, delta);
		visu_draw_circle(data, pix);
		i++;
	}
}

static	void	visu_draw_ants(t_visu_data *data, int delta)
{
	t_ant		*bubble;
	t_pixcoord	pix[1];
	int			pheromon;

	if (data->ants == 0)
		return ;
	bubble = data->ants;
	while (bubble != 0)
	{
		pheromon = data->pioneers[bubble->id];
		visu_get_pix(data->anthill[bubble->location], pix, pheromon, delta);
		visu_draw_ant(data, pix);
		bubble = bubble->next;
	}
}

void			visu_draw_anthill(t_visu_data *data)
{
	int	delta;

	visu_remap(data);
	delta = (HEIGHT - (2 * BORDER)) / (data->max_x + 2);
	if (delta < 50)
	{
		visu_free_data(&data);
		exit(ft_msg_int(2, "Can't draw, map too big\n", 0));
	}
	visu_draw_links(data, delta);
	visu_draw_rooms(data, delta);
	visu_draw_ants(data, delta);
}

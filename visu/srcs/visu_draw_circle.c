/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_draw_circle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:09:57 by erli              #+#    #+#             */
/*   Updated: 2019/02/08 13:12:05 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void				visu_draw_circle(t_visu_data *data, t_pixcoord *pix)
{
	int	x;
	int	y;
	int	rad_2;

	rad_2 = ROOM_RAD * ROOM_RAD;
	x = -ROOM_RAD;
	while (x <= ROOM_RAD)
	{
		y = -ROOM_RAD;
		while (y <= ROOM_RAD)
		{
			if ((x * x) + (y * y) <= rad_2)
				visu_pixel_put(data, pix->px, pix->py, pix->pz);
			y++;
		}
		x++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_free_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 13:37:55 by pmasson           #+#    #+#             */
/*   Updated: 2019/02/06 18:49:03 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static	void	visu_free_file(t_file **file)
{
	t_file *tmp;

	tmp = *file;
	if (file == NULL || *file == NULL)
		return ;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		free((*file)->buff);
		(*file)->buff = NULL;
		free(*file);
		*file = NULL;
		*file = tmp;
	}
}

static	void	visu_free_tabint(int **tab)
{
	int	i;

	if (tab == NULL)
		return ;
	if (*tab == NULL)
	{
		free(tab);
		return ;
	}
	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static	void	visu_free_rooms(t_rooms *rooms, int n)
{
	int i;

	if (rooms == 0)
		return ;
	i = 0;
	while (i < n)
	{
		free(rooms[i].name);
		i++;
	}
	free(rooms);
}

void			visu_free_data(t_visu_data **data)
{
	if (data != NULL)
	{
		visu_free_file(data->file);
		visu_free_rooms((*data)->anthill);
		visu_free_tabint((*data)->matrix);
		if ((*data)->win_ptr != 0)
			mlx_destroy_window((*data)->mlx_ptr, (*data)->win_ptr);
		free(*data);
		*data = NULL;
	}
}

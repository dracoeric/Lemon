/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_rec_search.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:44:17 by erli              #+#    #+#             */
/*   Updated: 2019/02/07 15:45:09 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

t_room		*visu_rec_search(t_room *anthill, char *name, int i_start,
				int i_end)
{
	int i_mid;
	int	min;
	int	len;
	int	len_anthill;
	int	cmp;

	len = ft_strlen(name);
	i_mid = (i_start + i_end) / 2;
	len_anthill = ft_strlen(anthill[i_mid].name);
	min = (len_anthill > len ? len : len_anthill);
	cmp = ft_strncmp(name, anthill[i_mid].name, min);
	if (i_end == i_start && cmp == 0 && len == len_anthill)
		return (anthill + i_start);
	else if (i_end == i_start || i_start < 0)
		return (NULL);
	if (cmp < 0 || (cmp == 0 && len < len_anthill))
		return (visu_rec_search(anthill, name, i_start, i_mid - 1));
	else if (cmp > 0 || (cmp == 0 && len > len_anthill))
		return (visu_rec_search(anthill, name, i_mid + 1, i_end));
	else
		return (anthill + i_mid);
}

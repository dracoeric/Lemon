/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:04:12 by pmasson           #+#    #+#             */
/*   Updated: 2019/02/06 17:48:46 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int	visu_atoi(char *str, int *d)
{
	int		i;
	long	a;
	long	coeff;

	i = 0;
	a = 0;
	coeff = 1;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	i--;
	while (i >= 0)
	{
		a = str[i] == '+' ? a : a + coeff * (str[i] - 48);
		coeff = coeff * 10;
		if (a > 2147483648 || (a == 2147483648 && str[0] != '-')\
				|| coeff > 10000000000)
			return (0);
		i--;
	}
	*d = a;
	return (1);
}

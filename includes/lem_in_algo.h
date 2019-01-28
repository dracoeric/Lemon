/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_algo.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 17:30:26 by erli              #+#    #+#             */
/*   Updated: 2019/01/28 18:11:43 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_ALGO_H

# define LEM_IN_ALGO

typedef struct	s_room
{
	char		*name;
	int			id;
	int			x;
	int			y;
	int			*neighboor;
	char		properties;
	int			occupant;
}				t_room;

typedef	struct	s_path
{
	int		path_id;
	int		*path;
	int		mother_id;
}				t_path;

#endif

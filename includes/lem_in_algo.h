/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_algo.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 17:30:26 by erli              #+#    #+#             */
/*   Updated: 2019/01/31 16:34:22 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_ALGO_H
# define LEM_IN_ALGO_H

#include "mlxadd.h"

# define WIDTH 1080
# define HEIGHT 720
# define GRAPH_BORDER 50
# define B_SIZE 16364
# define LI_CONNECTED(data, i, j) ((data->matrix)[i][j] & 1) == 1)
# define LI_FLOW(data, i, j) (((data->matrix)[i][j] >> 1) & 1) == 1)
# define LI_POS_FLOW(data, i, j) (((data->matrix)[i][j] >> 2) & 1) == 1)
# define LI_FLOW_CAPPED(data, i, j) (((data->matrix)[i][j] >> 1) & 3) == 3)

typedef struct	s_room
{
	char		*name;
	int			id;
	int			x;
	int			y;
}				t_room;

typedef struct	s_lem_in_data
{
	int			n_ant;
	int			start;
	int			end;
	int			n_room;
	int			options;
	int			fd;
	char		**anthill;
	char		**matrix;
	char		**matrix_old
	int			*limits;
	char		*buf;

	void		*mlx_ptr;
	void		*win_ptr;
}				t_lem_in_data;


typedef	struct	s_path
{
	int				path_id;
	int				*path;
	int				*occupants;
	int				steps;
	char			state;
	struct s_path	next;
	struct s_path	previous;
}				t_path;

t_path			*lem_in_create_path(t_lem_in_data *data, int room_id,
						int *n_path, t_path *dup);
void			lem_in_path_add(t_path **list, t_path *path);
void			lem_in_rm_path(t_path **list, int path_id);
void			lem_in_del_list(t_path **list);
void			lem_in_trim_path(t_path **list);
int				lem_in_next_room(t_lem_in_data *data, t_path *path, int n_room,
						int *index);
t_path			*lem_in_bfs_path(t_lem_in-data *data);
int				lem_in_manage_node(t_lem_in_data *data, t_path **bubble,
						int	*n_path);
void			lem_in_add_flow(t_lem_in_data *data, int src, int dest);
int				lem_in_algo(t_lem_in_data *data);
void			lem_in_get_steps(t_lem_in_data *data, char **matrix,
					int *tab, int n_path);
void			lem_in_test_opti(t_lem_in_data *data, int n_paths);
void			lem_in_draw_graph(t_lem_in_data *data, t_mapcoord a,
					t_mapcoord b);
void			lem_in_send_ants(t_lem_in_data *data, int max_paths, int mode);
void			lem_in_print(t_lem_in_data *data, int ant_id, int room);
#endif

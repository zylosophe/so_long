/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_utils.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:21:55 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/18 14:01:33 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATHFINDING_UTILS_H
# define PATHFINDING_UTILS_H

typedef struct s_pathfinding_env
{
	t_point		start;
	t_point		finish;
	t_memclass	mc;
}				t_pathfinding_env;

typedef struct s_tochecklist
{
	t_map	cases;
	t_point	last;
	t_point	current;
}	t_tochecklist;

typedef struct s_path_map_case
{
	bool	solid;
	bool	to_check;
	t_point	before;
}			t_path_map_case;

typedef struct s_path_map_case_init_args
{
	t_memclass	*mc;
	bool		solid_bridge;
}				t_path_map_case_init_args;

typedef t_map	t_path_map;

void			path_map_case_init(t_point p, void **el, void *mc);
t_path_map		init_map(t_memclass mc, bool solid_bridge);
t_tochecklist	inittochecklist(t_memclass mc, t_point dim, t_point first);
void			addtocheck(t_tochecklist *tocheck, t_point p);
t_point			nexttocheck(t_tochecklist *tocheck);

#endif

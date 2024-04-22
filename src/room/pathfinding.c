/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:19:19 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/22 12:43:20 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include "pathfinding_utils.h"

static t_direction	pathfinding_finishcase(
		t_point start, t_point direction_p, t_path_map *map)
{
	t_point		after;
	t_point		before;

	before = direction_p;
	while (before.x != start.x || before.y != start.y)
	{
		after = before;
		before = ((t_path_map_case *)*map_at(map, after))->before;
	}
	if (after.x - before.x == 1)
		return (RIGHT);
	if (after.x - before.x == -1)
		return (LEFT);
	if (after.y - before.y == 1)
		return (DOWN);
	return (UP);
}

static t_direction	pathfinding_checkdirections(
		t_tochecklist *tocheck, t_point case_checking,
		t_path_map *map, t_pathfinding_env env)
{
	t_direction		d;
	t_point			direction_p;
	t_path_map_case	*direction_case;

	d = -1;
	while (++d < 4)
	{
		direction_p = case_checking;
		point_addto(&direction_p, point_fromdirection(d));
		direction_case = (t_path_map_case *)*map_at(map, direction_p);
		if (!direction_case->to_check && !direction_case->solid)
		{
			direction_case->to_check = true;
			direction_case->before = case_checking;
			addtocheck(tocheck, direction_p);
		}
		if (direction_p.x == env.finish.x && direction_p.y == env.finish.y)
		{
			direction_case->before = case_checking;
			return (pathfinding_finishcase(env.start, direction_p, map));
		}
	}
	return (NO_DIRECTION);
}

t_direction	pathfinding(t_point start, t_point finish, bool for_firsk)
{
	const t_pathfinding_env	env = {
		.start = start,
		.finish = finish,
		.mc = mem_subclass(error_err, g_env.mc)
	};
	t_path_map				map;
	t_point					case_checking;
	t_tochecklist			tocheck;
	t_direction				r;

	if (start.x == finish.x && start.y == finish.y)
		return (NO_DIRECTION);
	map = init_map(env.mc, for_firsk);
	tocheck = inittochecklist(env.mc, map.dim, start);
	case_checking = start;
	((t_path_map_case *)*map_at(&map, start))->to_check = true;
	while (case_checking.x != -1 || case_checking.y != -1)
	{
		r = pathfinding_checkdirections(&tocheck, case_checking, &map, env);
		if (r != NO_DIRECTION)
			return (r);
		case_checking = nexttocheck(&tocheck);
	}
	mem_freeall(env.mc);
	return (NO_DIRECTION);
}

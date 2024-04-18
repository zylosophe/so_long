/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:35:13 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/18 18:30:25 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include "pathfinding_utils.h"

void	path_map_case_init(t_point p, void **el, void *args_p)
{
	const t_path_map_case_init_args	*args = (t_path_map_case_init_args *)args_p;
	const t_room					room = g_env.room;
	const t_object					*obj = room.objects[p.y * room.width + p.x];
	const t_sprite					*surface
		= &room.surfaces[p.y * room.width + p.x];
	const t_path_map_case			r = {
		to_check: false,
		before: point_init(-1, -1),
		solid: p.x == 0 || p.x == room.width - 1 || p.y == 0
		|| p.y == room.height - 1 || (
			obj && ((args->for_firsk && obj->type.solid_firsk)
				|| (!args->for_firsk && obj->type.solid_snas)))
		|| (args->for_firsk && surface->meta->first_frame == BRIDGE)
	};

	*el = mem_alloc(error_err, args->mc, sizeof(r));
	**(t_path_map_case **)el = r;
}

t_path_map	init_map(t_memclass mc, bool for_firsk)
{
	t_path_map					r;
	t_path_map_case_init_args	args;

	r.dim.x = g_env.room.width;
	r.dim.y = g_env.room.height;
	r = map_init(mc, point_init(g_env.room.width, g_env.room.height));
	args.mc = mc;
	args.for_firsk = for_firsk;
	map_foreach(&r, path_map_case_init, &args);
	return (r);
}

t_tochecklist	inittochecklist(t_memclass mc, t_point dim, t_point first)
{
	t_tochecklist	r;
	int				i;

	r.cases = map_init(mc, dim);
	i = -1;
	while (++i < dim.x * dim.y)
	{
		r.cases.cases[i] = mem_alloc(error_err, mc, sizeof(t_point));
		*((t_point *)r.cases.cases[i]) = point_init(-1, -1);
	}
	r.last = first;
	r.current = first;
	return (r);
}

void	addtocheck(t_tochecklist *tocheck, t_point p)
{
	*(t_point *)*map_at(&tocheck->cases, tocheck->last) = p;
	tocheck->last = p;
}

t_point	nexttocheck(t_tochecklist *tocheck)
{
	tocheck->current = *(t_point *)*map_at(&tocheck->cases, tocheck->current);
	return (tocheck->current);
}

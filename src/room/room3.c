/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:18:38 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/21 16:59:11 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

t_object	*room_getobjectfaced(
				t_room room, t_character *character, t_point pos)
{
	point_addto(&pos, point_fromdirection(character->direction));
	return (room.objects[pos.y * room.width + pos.x]);
}

// if this returns true, then character *must* walk forward.
bool	room_canwalk(t_room room, t_character *character, t_point pos)
{
	t_point		after;
	t_object	*obj;
	bool		r;

	after = pos;
	point_addto(&after, point_fromdirection(character->direction));
	if (after.y <= 0 || after.y >= room.height - 1
		|| after.x <= 0 || after.x >= room.width - 1)
		return (false);
	obj = room_getobjectfaced(room, character, pos);
	r = (!obj || (
				obj->type.walk_through
				&& obj->type.walk_through(obj, character, after)));
	if (r)
		mem_free(obj);
	return (r);
}

t_point	room_find(t_object_init objtype)
{
	t_point		p;
	t_object	*obj;

	p.x = -1;
	while (++p.x < g_env.room.width)
	{
		p.y = -1;
		while (++p.y < g_env.room.height)
		{
			obj = g_env.room.objects[p.y * g_env.room.width + p.x];
			if (obj && obj->type.init == objtype)
				return (p);
		}
	}
	return (point_init(-1, -1));
}

int	room_count(t_object_init objtype)
{
	int	i;
	int	r;

	r = 0;
	i = -1;
	while (++i < g_env.room.width * g_env.room.height)
		if (g_env.room.objects[i]
			&& g_env.room.objects[i]->type.init == objtype)
			r++;
	return (r);
}

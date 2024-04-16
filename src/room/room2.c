/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:14:49 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/17 13:21:32 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static void	moveobject(t_room room, t_point start, t_point move)
{
	t_point	end;

	end = start;
	point_addto(&end, move);
	if (start.x == end.x && start.y == end.y)
		return ;
	room.objects[end.y * room.width + end.x]
		= room.objects[start.y * room.width + start.x];
	room.objects[start.y * room.width + start.x] = NULL;
}

static bool	isinlist(void *addr, t_list list)
{
	t_list_element	*el;

	el = list.first;
	while (el)
	{
		if (el->value == addr)
			return (true);
		el = el->next;
	}
	return (false);
}

void	room_loop(void)
{
	t_point				pos;
	t_object			*object;
	t_point				move;
	const t_memclass	mc = mem_subclass(error_err, g_env.mc);
	t_list				objects_done;

	objects_done = list_createempty(mc);
	pos.x = 0;
	while (pos.x < g_env.room.width)
	{
		pos.y = 0;
		while (pos.y < g_env.room.height)
		{
			object = g_env.room.objects[pos.y * g_env.room.width + pos.x];
			if (object && !isinlist(object, objects_done))
			{
				move = object->type.loop(object, pos);
				moveobject(g_env.room, pos, move);
				list_add(error_err, &objects_done, object);
			}
			pos.y++;
		}
		pos.x++;
	}
	mem_freeall(mc);
}

void	room_free(t_room room)
{
	mem_freeall(room.mc);
}

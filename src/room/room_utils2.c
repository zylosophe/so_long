/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:04:41 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/18 21:09:01 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include "room_utils.h"

static void	checkwall(t_const_string path, t_object *obj)
{
	if (!obj || obj->type.init != wall_init)
		error_str(path, "there must have walls all around the room");
}

void	room_checkwallsallaround(t_const_string path, t_room *room)
{
	int		i;

	i = -1;
	while (++i < room->width)
		checkwall(path, room->objects[i]);
	i = (room->height - 1) * room->width - 1;
	while (++i < room->width * room->height)
		checkwall(path, room->objects[i]);
	i = 0;
	while (i < room->width * room->height)
	{
		checkwall(path, room->objects[i]);
		i += room->width;
	}
	i = room->width - 1;
	while (i < room->width * room->height)
	{
		checkwall(path, room->objects[i]);
		i += room->width;
	}
}

t_point	to_camera_pos(t_point p)
{
	t_point	r;

	r.x = p.x * 50 - g_env.camera.pos.x;
	r.y = p.y * 50 - g_env.camera.pos.y;
	return (r);
}

void	room_drawsurfaceandobjects(void)
{
	t_point			p;
	t_object		*obj;

	camera_sync();
	p.y = -1;
	while (++p.y < g_env.room.height)
	{
		p.x = -1;
		while (++p.x < g_env.room.width)
			sprite_draw(to_camera_pos(p),
				g_env.room.surfaces + p.y * g_env.room.width + p.x);
	}
	p.y = -1;
	while (++p.y < g_env.room.height)
	{
		p.x = -1;
		while (++p.x < g_env.room.width)
		{
			obj = g_env.room.objects[p.y * g_env.room.width + p.x];
			if (obj)
				obj->type.draw(obj, to_camera_pos(p));
			visual_loop(&g_env.room.visuals[p.y * g_env.room.width + p.x],
				to_camera_pos(p));
		}
	}
}

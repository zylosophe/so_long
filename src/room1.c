/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 23:31:22 by mcolonna          #+#    #+#             */
/*   Updated: 2024/03/29 17:32:26 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "room.h"
#include "error.h"
#include "libtf.h"
#include "env.h"
#include "room_utils.h"

static bool	room_fromfile2(
				int fd, t_const_string path, int *i, t_room *room)
{
	t_const_string		line;
	t_roomcase			*roomcase;
	const t_memclass	mc = mem_subclass(err, g_env.mc);

	line = read_line(err_remember, mc, fd);
	if (err_get())
		err_perror(path);
	if (!line)
		return (false);
	while (*line && *line != '\n')
	{
		roomcase = getroomcase(path, *line);
		room->surfaces[*i] = sprite_init(roomcase->surface_spr);
		if (roomcase->object)
		{
			room->objects[*i] = mem_alloc(err, room->mc, sizeof(t_object));
			*(room->objects[*i]) = roomcase->object(room->mc);
		}
		else
			room->objects[*i] = NULL;
		line++;
		(*i)++;
	}
	mem_freeall(mc);
	return (true);
}

t_room	room_fromfile(t_const_string path)
{
	t_room				r;
	int					fd;
	const t_memclass	mc = mem_subclass(err, g_env.mc);
	int					i;

	room_getsize(mc, &r, path);
	r.mc = mem_subclass(err, g_env.mc);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		err_perror(path);
	r.surfaces = mem_alloc(err, r.mc, r.width * r.height * sizeof(t_sprite));
	r.objects = mem_alloc(err, r.mc, r.width * r.height * sizeof(t_object *));
	i = 0;
	while (room_fromfile2(fd, path, &i, &r))
		;
	mem_freeall(mc);
	return (r);
}

void	room_draw(t_room room)
{
	int			x;
	int			y;
	t_object	*obj;

	y = -1;
	while (++y < room.height)
	{
		x = -1;
		while (++x < room.width)
			sprite_draw(x * 50, y * 50, room.surfaces + y * room.width + x);
	}
	y = -1;
	while (++y < room.height)
	{
		x = -1;
		while (++x < room.width)
		{
			obj = room.objects[y * room.width + x];
			if (obj)
				obj->type.draw(obj, x * 50, y * 50);
		}
	}
}

void	room_loop(t_room room)
{
	t_point				pos;
	t_object			*object;
	t_point				move;
	const t_memclass	mc = mem_subclass(err, g_env.mc);
	t_list				objects_done;

	objects_done = list_createempty(mc);
	pos.x = 0;
	while (pos.x < room.width)
	{
		pos.y = 0;
		while (pos.y < room.height)
		{
			object = room.objects[pos.y * room.width + pos.x];
			if (object && !isinlist(object, objects_done))
			{
				move = object->type.loop(object, pos);
				moveobject(room, pos, move);
				list_add(err, &objects_done, object);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:11:29 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/09 15:28:31 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include "room_utils.h"

static void	room_fromfile3(t_room *room)
{
	int	x;
	int	y;

	x = -1;
	while (++x < room->width)
	{
		y = -1;
		while (++y < room->height)
		{
			if (y == 0 || y == room->height - 1)
			{
				room->surfaces[y * room->width + x] = sprite_init(CASE_WALL);
				room->objects[y * room->width + x] = NULL;
			}
			else
				room->surfaces[y * room->width + x] = sprite_init(
						CASE_FLOOR_1 + (x + y) % 2);
		}
	}
}

static bool	room_fromfile2(
				int fd, t_const_string path, int *i, t_room *room)
{
	t_const_string		line;
	t_roomcase			*roomcase;
	const t_memclass	mc = mem_subclass(error_err, g_env.mc);

	line = read_line(err_remember, mc, fd);
	if (err_get())
		error_perror(path);
	if (!line)
		return (false);
	while (*line && *line != '\n')
	{
		roomcase = getroomcase(path, *line);
		if (roomcase->object)
		{
			room->objects[*i] = mem_alloc(error_err, room->mc,
					sizeof(t_object));
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

static t_room	room_fromfile(t_const_string path)
{
	t_room				r;
	int					fd;
	const t_memclass	mc = mem_subclass(error_err, g_env.mc);
	int					i;

	room_getsize(mc, &r, path);
	r.mc = mem_subclass(error_err, g_env.mc);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_perror(path);
	r.surfaces = mem_alloc(error_err, r.mc, r.width * r.height
			* sizeof(t_sprite));
	r.objects = mem_alloc(error_err, r.mc, r.width * r.height
			* sizeof(t_object *));
	r.visuals = mem_alloc(error_err, r.mc, r.width * r.height
			* sizeof(t_visual *));
	i = -1;
	while (++i < r.width * r.height)
		r.visuals[i] = NULL;
	i = 0;
	while (room_fromfile2(fd, path, &i, &r))
		;
	mem_freeall(mc);
	room_fromfile3(&r);
	return (r);
}

void	room_init(t_const_string path)
{
	int	i;

	g_env.room = room_fromfile(path);
	g_env.moves = 0;
	g_env.ketchup = 0;
	g_env.max_ketchup = 0;
	i = -1;
	while (++i < g_env.room.width * g_env.room.height)
		if (g_env.room.objects[i]
			&& g_env.room.objects[i]->type.init == ketchup_init)
			g_env.max_ketchup++;
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
			visual_loop(&room.visuals[y * room.width + x], x * 50, y * 50);
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:11:29 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/18 21:09:31 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include "room_utils.h"

static t_room	room_fromfile3(t_const_string path, t_room *room)
{
	int	x;
	int	y;
	int	i;

	room_checkwallsallaround(path, room);
	x = -1;
	while (++x < room->width)
	{
		y = -1;
		while (++y < room->height)
		{
			i = y * room->width + x;
			if (y == 0 || y == room->height - 1)
			{
				room->surfaces[i] = sprite_init(CASE_BORDER_BOTTOM);
				if (y == 0)
					room->surfaces[i] = sprite_init(CASE_BORDER_TOP);
				room->objects[i] = NULL;
			}
			else
				if (room->surfaces[i].meta->first_frame == FLOOR_1)
					room->surfaces[i] = sprite_init(CASE_FLOOR_1 + (x + y) % 2);
		}
	}
	return (*room);
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
		room->objects[*i] = NULL;
		if (roomcase->object)
		{
			room->objects[*i] = mem_alloc(error_err, room->mc,
					sizeof(t_object));
			*(room->objects[*i]) = roomcase->object(room->mc);
		}
		room->surfaces[*i] = sprite_init(roomcase->surface);
		line++;
		(*i)++;
	}
	mem_freeall(mc);
	return (true);
}

static t_room	room_fromfile(t_room *r, t_const_string path)
{
	int					fd;
	const t_memclass	mc = mem_subclass(error_err, g_env.mc);
	int					i;

	if (!str_eq(path + str_len(path) - 4, ".ber"))
		error_str(path, "the room must be a '.ber' file.");
	room_getsize(mc, r, path);
	r->mc = mem_subclass(error_err, g_env.mc);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_perror(path);
	r->surfaces = mem_alloc(error_err, r->mc, r->width * r->height
			* sizeof(t_sprite));
	r->objects = mem_alloc(error_err, r->mc, r->width * r->height
			* sizeof(t_object *));
	r->visuals = mem_alloc(error_err, r->mc, r->width * r->height
			* sizeof(t_visual *));
	i = -1;
	while (++i < r->width * r->height)
		r->visuals[i] = NULL;
	i = 0;
	while (room_fromfile2(fd, path, &i, r))
		;
	mem_freeall(mc);
	return (room_fromfile3(path, r));
}

void	room_init(t_const_string path)
{
	room_fromfile(&g_env.room, path);
	g_env.moves = 0;
	g_env.ketchup = 0;
	g_env.max_ketchup = room_count(ketchup_init);
	if (room_count(exit_init) != 1)
		error_str(path, "there must be exactly 1 exit.");
	if (room_count(ketchup_init) < 1)
		error_str(path, "there must be at least 1 collectible.");
	if (room_count(snas_init) != 1)
		error_str(path, "there must be exactly 1 start position.");
	room_checkaccessibilities(path);
}

void	room_draw(void)
{
	t_point			p;

	room_drawsurfaceandobjects();
	p = point_init(10, 4);
	display_uint(&p, g_env.moves);
}

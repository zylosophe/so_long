/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 23:31:22 by mcolonna          #+#    #+#             */
/*   Updated: 2024/03/13 16:37:06 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "room.h"
#include "error.h"
#include "libtf.h"
#include "env.h"
#include "room_utils.h"

static bool	room_fromfile2(
				int fd, t_memclass mc, t_const_string path, t_sprite **surface)
{
	t_const_string		line;

	line = read_line(err_remember, mc, fd);
	if (err_get())
		err_perror(path);
	if (!line)
		return (false);
	while (*line && *line != '\n')
	{
		**surface = sprite_init(getroomcase(path, *line)->surface_spr);
		line++;
		(*surface)++;
	}
	return (true);
}

t_room	room_fromfile(t_const_string path)
{
	t_room				r;
	int					fd;
	t_sprite			*surface;
	const t_memclass	mc = mem_subclass(err, g_env.mc);

	room_getsize(mc, &r, path);
	r.mc = mem_subclass(err, g_env.mc);
	r.surfaces = mem_alloc(err, r.mc, r.width * r.height * sizeof(t_sprite));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		err_perror(path);
	surface = r.surfaces;
	while (surface - r.surfaces < r.width * r.height
		&& room_fromfile2(fd, mc, path, &surface))
		;
	mem_freeall(mc);
	return (r);
}

void	room_draw(t_room room)
{
	int	x;
	int	y;

	y = -1;
	while (++y < room.height)
	{
		x = -1;
		while (++x < room.width)
		{
			sprite_draw(x * 50, y * 50, room.surfaces + y * room.width + x);
		}
	}
}

void	room_free(t_room room)
{
	mem_freeall(room.mc);
}

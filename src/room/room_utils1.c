/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:21:33 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/15 18:59:54 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include "room_utils.h"

static t_roomcase	g_roomcases[] = {
{c: '0', object: NULL},
{c: '1', object: wall_init},
{c: 'P', object: snas_init},
{c: 'C', object: ketchup_init},
{c: 'E', object: exit_init},
{c: 'F', object: firsk_init},
{c: '\0'}
};

static int	getlinelen(t_const_string line)
{
	int	r;

	r = str_len(line);
	if (line[r - 1] == '\n')
		r--;
	return (r);
}

void	room_getsize(t_memclass mc, t_room *r, t_const_string path)
{
	int					fd;
	t_const_string		line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_perror(path);
	line = read_line(err_remember, mc, fd);
	if (err_get())
		error_perror(path);
	if (!line)
		error_str(path, "room is empty");
	r->width = getlinelen(line);
	r->height = 1;
	while (true)
	{
		line = read_line(err_remember, mc, fd);
		if (err_get())
			error_perror(path);
		if (!line)
			break ;
		if (getlinelen(line) != r->width)
			error_str(path, "the room must be rectangular");
		r->height++;
	}
}

t_roomcase	*getroomcase(t_const_string path, char c)
{
	int	i;

	i = -1;
	while (g_roomcases[++i].c)
	{
		if (g_roomcases[i].c == c)
			return (&g_roomcases[i]);
	}
	error_str(path, "unknown char");
	return (NULL);
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

void	room_checkaccessibilities(t_const_string path)
{
	t_point		p;
	t_object	*obj;
	t_point		snas_pos;

	snas_pos = room_find(snas_init);
	p.y = -1;
	while (++p.y < g_env.room.height)
	{
		p.x = -1;
		while (++p.x < g_env.room.width)
		{
			obj = g_env.room.objects[p.y * g_env.room.width + p.x];
			if (obj && obj->type.init == ketchup_init)
				if (pathfinding(snas_pos, p) == NO_DIRECTION)
					error_str(path, "all collectibles must be accessible.");
		}
	}
	if (pathfinding(snas_pos, room_find(exit_init)) == NO_DIRECTION)
		error_str(path, "the exit must be accessible.");
}

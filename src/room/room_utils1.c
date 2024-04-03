/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolonna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:26:28 by mcolonna          #+#    #+#             */
/*   Updated: 2024/04/03 13:35:35 by mcolonna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include "room_utils.h"

static t_roomcase	g_roomcases[] = {
{c: '0', object: NULL},
{c: '1', object: wall_init},
{c: 'P', object: snas_init},
{c: 'K', object: ketchup_init},
{c: '\0'}
};

int	getlinelen(t_const_string line)
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
			error_str(path, "the lines have different lengths");
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

void	moveobject(t_room room, t_point start, t_point move)
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

bool	isinlist(void *addr, t_list list)
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
